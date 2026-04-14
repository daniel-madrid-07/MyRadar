/*
** EPITECH PROJECT, 2025
** My_Hunter
** File description:
** background
*/

#include "../include/my.h"

int filltower_config(tower_t *new_tower, tower_data_t *data)
{
    new_tower->position.x = data->x1;
    new_tower->position.y = data->y1;
    new_tower->radius = data->radius;
    new_tower->sprite = NULL;
    new_tower->area = NULL;
    new_tower->next = global_game->towers;
    global_game->towers = new_tower;
    return 0;
}

int tower_config(char *line)
{
    tower_data_t data;

    int scanned = sscanf(line, "T %i %i %i",
        &data.x1, &data.y1, &data.radius);
    if (scanned != 3)
        return 84;
    tower_t *new_tower = malloc(sizeof(tower_t));
    if (new_tower == NULL) {
        return 84;
    }
    filltower_config(new_tower, &data);
    return 0;
}