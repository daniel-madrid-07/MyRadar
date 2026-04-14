/*
** EPITECH PROJECT, 2025
** Graphical_Programming
** File description:
** My Radar
*/

#include "../include/my.h"
#include "../extras/my_printf/include/my.h"
#include <time.h>


int process_lines(char **argv)
{
    FILE *file = fopen(argv[1], "r");
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    if (file == NULL) {
        my_printf("Error with the file.\n");
        return 84;
    }
    global_game = malloc(sizeof(game_t));
    if (global_game == NULL)
        return 84;
    global_game->aircrafts = NULL;
    global_game->towers = NULL;
    while ((read = getline(&line, &len, file)) != -1) {
        if (line[0] == 'A')
            plane_config(line);
        else if (line[0] == 'T')
            tower_config(line);
        else if (line[0] != '\n' && line[0] != '\0')
            return 84;
    }
    free(line);
    fclose(file);
    return 0;
}

int parse_script(int argc, char **argv)
{
    if (argc  != 2) {
        my_printf("Invalid arguments, 1 is required.\n");
        my_printf("retry with -h\n");
        return 84;
    }
    if (my_strcmp(argv[1], "-h") == 0){
        help();
        return 0;
    }
    return process_lines(argv);
}


int main(int argc, char **argv)
{
    int result = parse_script(argc, argv);

    if (result != 0)
        return result;
    global_game->window = create_window();
    global_game->clock = sfClock_create();
    global_game->running = true;
    global_game->show_sprites = true;
    global_game->show_hitboxes = true;
    background_t *bg = generate_background();
    init_music(global_game);
    init_timer(global_game);
    create_tower_areas();
    create_aircraft_sprites();
    sfClock *delta_clock = sfClock_create();

    sfEvent event;
    
    while (global_game->running && sfRenderWindow_isOpen(global_game->window)) {
        sfTime frame_time = sfClock_restart(delta_clock);
        float delta_time = sfTime_asSeconds(frame_time);
        update_aircrafts(delta_time);
        while (sfRenderWindow_pollEvent(global_game->window, &event)) {
            if (event.type == sfEvtClosed)
                global_game->running = false;
            if (event.type == sfEvtKeyPressed) {
                if (event.key.code == sfKeyL)
                    global_game->show_sprites = !global_game->show_sprites;
                if (event.key.code == sfKeyS)
                    global_game->show_hitboxes = !global_game->show_hitboxes;
            }
        }
        sfRenderWindow_clear(global_game->window, sfBlack);
        sfRenderWindow_drawSprite(global_game->window, bg->sprite, NULL);
        draw_towers();
        draw_aircrafts();
        float timer_time = sfTime_asSeconds(sfClock_getElapsedTime(global_game->clock));
        draw_timer(global_game->window, timer_time);
        sfRenderWindow_display(global_game->window);
    }
    cleanup_game(bg, delta_clock);
    return 0;
}
