/*
** EPITECH PROJECT, 2025
** My_Hunter
** File description:
** background
*/

#include "../include/my.h"

game_t *global_game = NULL;

int fill_config(aircraft_t *new_aircraft, aircraft_data_t *data)
{
    new_aircraft->departure.x = data->x1;
    new_aircraft->departure.y = data->y1;
    new_aircraft->arrival.x = data->x2;
    new_aircraft->arrival.y = data->y2;
    new_aircraft->position.x = data->x1;
    new_aircraft->position.y = data->y1;
    new_aircraft->speed = data->speed;
    new_aircraft->delay = data->delay;
    new_aircraft->active = false;
    new_aircraft->destroyed = false;
    new_aircraft->sprite = NULL;
    new_aircraft->hitbox = NULL;
    new_aircraft->next = global_game->aircrafts;
    global_game->aircrafts = new_aircraft;
    return 0;
}

int plane_config(char *line)
{
    aircraft_data_t data;

    int scanned = sscanf(line, "A %i %i %i %i %i %d",
        &data.x1, &data.y1, &data.x2, &data.y2, &data.speed, &data.delay);
    if (scanned != 6)
        return 84;
    aircraft_t *new_aircraft = malloc(sizeof(aircraft_t));
    if (new_aircraft == NULL) {
        return 84;
    }
    fill_config(new_aircraft, &data);
    return 0;
}