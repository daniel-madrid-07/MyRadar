/*
** EPITECH PROJECT, 2025
** Graphical_Programming, My Radar
** File description:
** Initialization functions
*/

#include "../include/my.h"

sfRenderWindow *create_window(void)
{
    sfVideoMode mode;
    sfRenderWindow *window;

    mode.width = 1920;
    mode.height = 1080;
    mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(mode, "My Radar", sfResize | sfClose,
        NULL);
    sfRenderWindow_setFramerateLimit(window, 240);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    return window;
}

void init_music(game_t *game)
{
    game->music = sfMusic_createFromFile("./content/music.mp3");
    if (game->music) {
        sfMusic_setLoop(game->music, sfTrue);
        sfMusic_setVolume(game->music, 40.f);
        sfMusic_play(game->music);
    }
}

void init_timer(game_t *game)
{
    game->timer_font = sfFont_createFromFile("./content/font.ttf");
    game->timer_text = sfText_create();
    game->timer_bg = sfRectangleShape_create();

    if (game->timer_text && game->timer_font) {
        sfText_setFont(game->timer_text, game->timer_font);
        sfText_setCharacterSize(game->timer_text, 40);
        sfText_setColor(game->timer_text, sfWhite);
        sfVector2f text_position = {20, 1020};
        sfText_setPosition(game->timer_text, text_position);
    }
    if (game->timer_bg) {
        sfRectangleShape_setFillColor(game->timer_bg, sfBlack);
        sfVector2f rect_position = {10, 1020};
        sfRectangleShape_setPosition(game->timer_bg, rect_position);
    }
}
