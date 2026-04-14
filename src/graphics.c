/*
** EPITECH PROJECT, 2026
** my_radar
** File description:
** graphics
*/

#include "../include/my.h"
#include <SFML/Graphics/CircleShape.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Font.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/Text.h>

int create_aircraft_sprites()
{
    aircraft_t *aircraft = global_game->aircrafts;
    sfColor red = sfColor_fromRGBA(255, 0, 0, 100);
    sfVector2f size = {10, 10};

    global_game->plane_texture = sfTexture_createFromFile("./content/plane.png", NULL);
    if (global_game->plane_texture == NULL)
        return 84;
    while (aircraft != NULL) {
        sfVector2f position = {aircraft->departure.x, aircraft->departure.y};
        aircraft->sprite = sfSprite_create();
        sfVector2f scale = {0.05, 0.05};
        sfSprite_setScale(aircraft->sprite, scale);
        sfSprite_setTexture(aircraft->sprite, global_game->plane_texture, sfTrue);
        sfVector2u textureSize = sfTexture_getSize(global_game->plane_texture);
        sfVector2f sprite_origin = {textureSize.x / 2.0, textureSize.y / 2.0};
        sfSprite_setOrigin(aircraft->sprite, sprite_origin);
        sfSprite_setPosition(aircraft->sprite, position);
        aircraft->hitbox = sfRectangleShape_create();
        sfVector2f hitbox_origin = {size.x / 2, size.y / 2};
        sfRectangleShape_setSize(aircraft->hitbox, size);
        sfRectangleShape_setOrigin(aircraft->hitbox, hitbox_origin);
        sfRectangleShape_setFillColor(aircraft->hitbox, red);
        sfRectangleShape_setPosition(aircraft->hitbox, position);

        aircraft = aircraft->next;
    }
    return 0;
}

void check_collisions(void)
{
    aircraft_t *aircraft1 = global_game->aircrafts;
    
    while (aircraft1 != NULL) {
        aircraft_t *aircraft2 = aircraft1->next;

        if (!aircraft1->active || aircraft1->destroyed) {
            aircraft1 = aircraft1->next;
            continue;
        }
        while (aircraft2 != NULL) {
            if (!aircraft2->active || aircraft2->destroyed) {
                aircraft2 = aircraft2->next;
                continue;
            }
            float dx = aircraft2->position.x - aircraft1->position.x;
            float dy = aircraft2->position.y - aircraft1->position.y;
            float distance = sqrt(dx * dx + dy *dy);
            if (distance < 15.0) {
                aircraft1->destroyed = true;
                aircraft2->destroyed = true;
                break;
            }
            aircraft2 = aircraft2->next;
        }
        aircraft1 = aircraft1->next;
    }
}

void update_aircrafts(float delta_time)
{
    float elapsed_time = sfTime_asSeconds(sfClock_getElapsedTime(global_game->clock));
    aircraft_t *aircraft = global_game->aircrafts;

    while (aircraft != NULL) {
        if (elapsed_time >= aircraft->delay && !aircraft->active)
            aircraft->active = true;
        if (aircraft->active) {
                float dx = aircraft->arrival.x - aircraft->position.x;
                float dy = aircraft->arrival.y - aircraft->position.y;
                float distance = sqrt(dx * dx + dy * dy);
                float movement = aircraft->speed * delta_time;
                float ratio = movement / distance;
                if (movement >= distance) {
                    aircraft->position.x = aircraft->arrival.x;
                    aircraft->position.y = aircraft->arrival.y;
                    aircraft->destroyed = true;
                }
                else {
                    aircraft->position.x += dx * ratio;
                    aircraft->position.y += dy * ratio;
            }
            sfVector2f new_pos = {aircraft->position.x, aircraft->position.y};
            sfSprite_setPosition(aircraft->sprite, new_pos);
            sfRectangleShape_setPosition(aircraft->hitbox, new_pos);
        }
        aircraft = aircraft->next;
    }
    check_collisions();
}

void draw_towers(void)
{
    tower_t *tower = global_game->towers;

    while (tower != NULL) {
        if (global_game->show_hitboxes)
            sfRenderWindow_drawCircleShape(global_game->window, tower->area, NULL);
        if (global_game->show_sprites)
            sfRenderWindow_drawSprite(global_game->window, tower->sprite, NULL);
        tower = tower->next;
    }
}

void draw_aircrafts(void)
{
    aircraft_t *aircraft = global_game->aircrafts;

    while (aircraft != NULL) {
        if (aircraft->active && !aircraft->destroyed) {
            if (global_game->show_hitboxes)
                sfRenderWindow_drawRectangleShape(global_game->window, aircraft->hitbox, NULL);
            if (global_game->show_sprites)
                sfRenderWindow_drawSprite(global_game->window, aircraft->sprite, NULL);
        }
        aircraft = aircraft->next;
    }
}

void draw_timer(sfRenderWindow *window, float elapsed_time)
{
    char time_str[20];
    sfVector2f size;

    if (!global_game->timer_text || !global_game->timer_bg)
        return;
    snprintf(time_str, 20, "%.1f", elapsed_time);
    if (elapsed_time >= 100) {
        size.x = 135;
        size.y = 50;
    }
    else if (elapsed_time >= 10) {
        size.x = 105;
        size.y = 50;
    }
    else {
        size.x = 80;
        size.y = 50;
    }
    sfRectangleShape_setSize(global_game->timer_bg, size);
    sfText_setString(global_game->timer_text, time_str);
    sfRenderWindow_drawRectangleShape(window, global_game->timer_bg, NULL);
    sfRenderWindow_drawText(window, global_game->timer_text, NULL);
}

int create_tower_areas()
{
    sfColor green = sfColor_fromRGBA(0, 255, 0, 100);
    tower_t *tower = global_game->towers;

    global_game->tower_texture = sfTexture_createFromFile("./content/tower.png", NULL);
    if (global_game->tower_texture == NULL)
        return 84;
    while (tower != NULL) {
        sfVector2f origin = {tower->radius, tower->radius};
        sfVector2f position = {tower->position.x, tower->position.y};
        tower->area = sfCircleShape_create();
        tower->sprite = sfSprite_create();
        sfCircleShape_setRadius(tower->area, tower->radius);
        sfCircleShape_setOrigin(tower->area, origin);
        sfCircleShape_setPosition(tower->area, position);
        sfCircleShape_setFillColor(tower->area, green);
        sfSprite_setTexture(tower->sprite, global_game->tower_texture, sfTrue);
        sfVector2u textureSize = sfTexture_getSize(global_game->tower_texture);
        sfVector2f sprite_origin = {textureSize.x / 2.0, textureSize.y / 1.05};
        sfSprite_setOrigin(tower->sprite, sprite_origin);
        sfSprite_setPosition(tower->sprite, position);
        sfVector2f scale = {0.2, 0.2};
        sfSprite_setScale(tower->sprite, scale);
        tower = tower->next;
    }
    return 0;
}
