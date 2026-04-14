/*
** EPITECH PROJECT, 2025
** My_Hunter
** File description:
** background
*/

#include "../include/my.h"

background_t *generate_background(void)
{
    background_t *background = malloc(sizeof(background_t));
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f scale;

    texture = sfTexture_createFromFile("./content/background.jpg", NULL);
    background->sprite = sfSprite_create();
    sfSprite_setTexture(background->sprite, texture, sfTrue);
    background->pos.x = 0;
    background->pos.y = 0;
    background->scale.x = 1.765;
    background->scale.y = 1.765;
    pos.x = background->pos.x;
    pos.y = background->pos.y;
    scale.x = background->scale.x;
    scale.y = background->scale.y;
    sfSprite_setPosition(background->sprite, pos);
    sfSprite_setScale(background->sprite, scale);
    return background;
}
