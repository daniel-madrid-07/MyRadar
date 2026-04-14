/*
** EPITECH PROJECT, 2022
** MY_H
** File description:
** desc
*/

#ifndef MY_H_
    # define MY_H_

    #include <stdarg.h>
    #include <SFML/Graphics.h>
    #include <SFML/Graphics/Sprite.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/Graphics/Types.h>
    #include <SFML/System.h>
    #include <SFML/System/Clock.h>
    #include <SFML/Window.h>
    #include <SFML/Audio.h>
    #include <stdbool.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <math.h>
    #include <string.h>
    #include <unistd.h>

typedef struct vector2f_s {
    float x;
    float y;
} vector2f_t;

typedef struct background_s {
    sfSprite *sprite;
    vector2f_t pos;
    vector2f_t scale;
} background_t;

typedef struct aircraft_s {
    vector2f_t departure;
    vector2f_t arrival;
    vector2f_t position;
    float speed;
    int delay;
    bool active;
    bool destroyed;
    sfSprite *sprite;
    sfRectangleShape *hitbox;
    struct aircraft_s *next;
} aircraft_t;

typedef struct tower_s {
    vector2f_t position;
    float radius;
    sfSprite *sprite;
    sfCircleShape *area;
    struct tower_s *next;
} tower_t;

typedef struct game_s {
    sfRenderWindow *window;
    sfClock *clock;
    float elapsed_time;
    aircraft_t *aircrafts;
    tower_t *towers;
    sfMusic *music;
    bool running;
    bool show_sprites;
    bool show_hitboxes;
    sfText *timer_text;
    sfFont *timer_font;
    sfRectangleShape *timer_bg;
    sfTexture *plane_texture;
    sfTexture *tower_texture;
} game_t;

typedef struct aircraft_data_s {
    int x1;
    int x2;
    int y1;
    int y2;
    int speed;
    int delay;
} aircraft_data_t;

typedef struct tower_data_s {
    int x1;
    int y1;
    int radius;
} tower_data_t;

// Global variable
extern game_t *global_game;

// Function prototypes
sfRenderWindow *create_window(void);
void init_music(game_t *game);
void init_timer(game_t *game);
void help(void);
int parse_script(int argc, char **argv);
background_t *generate_background(void);
int plane_config(char *line);
int tower_config(char *line);
int create_tower_areas(void);
int create_aircraft_sprites(void);
void update_aircrafts(float delta_time);
void draw_towers(void);
void draw_aircrafts(void);
void draw_timer(sfRenderWindow *window, float elapsed_time);
void cleanup_game(background_t *bg, sfClock *delta_clock);

#endif
