/*
** EPITECH PROJECT, 2025
** Graphical_Programming
** File description:
** Memory cleanup functions
*/

#include "../include/my.h"

static void cleanup_aircrafts(void)
{
    aircraft_t *aircraft = global_game->aircrafts;
    aircraft_t *next;

    while (aircraft != NULL) {
        next = aircraft->next;
        if (aircraft->sprite != NULL)
            sfSprite_destroy(aircraft->sprite);
        if (aircraft->hitbox != NULL)
            sfRectangleShape_destroy(aircraft->hitbox);
        free(aircraft);
        aircraft = next;
    }
}

static void cleanup_towers(void)
{
    tower_t *tower = global_game->towers;
    tower_t *next;

    while (tower != NULL) {
        next = tower->next;
        if (tower->sprite != NULL)
            sfSprite_destroy(tower->sprite);
        if (tower->area != NULL)
            sfCircleShape_destroy(tower->area);
        free(tower);
        tower = next;
    }
}

void cleanup_game(background_t *bg, sfClock *delta_clock)
{
    cleanup_aircrafts();
    cleanup_towers();
    if (global_game->window != NULL)
        sfRenderWindow_destroy(global_game->window);
    if (global_game->clock != NULL)
        sfClock_destroy(global_game->clock);
    if (global_game->music != NULL)
        sfMusic_destroy(global_game->music);
    if (global_game->timer_text != NULL)
        sfText_destroy(global_game->timer_text);
    if (global_game->timer_font != NULL)
        sfFont_destroy(global_game->timer_font);
    if (global_game->timer_bg != NULL)
        sfRectangleShape_destroy(global_game->timer_bg);
    if (global_game->plane_texture != NULL)
        sfTexture_destroy(global_game->plane_texture);
    if (global_game->tower_texture != NULL)
        sfTexture_destroy(global_game->tower_texture);
    if (delta_clock != NULL)
        sfClock_destroy(delta_clock);
    if (bg != NULL) {
        if (bg->sprite != NULL)
            sfSprite_destroy(bg->sprite);
        free(bg);
    }
    if (global_game != NULL)
        free(global_game);
}
