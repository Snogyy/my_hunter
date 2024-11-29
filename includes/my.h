/*
** EPITECH PROJECT, 2024
** myhunter
** File description:
** my
*/

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define CANDY_NB1(i) (sprite)->candy_list[(i)]
#define CANDY_NB2(i) (sprite).candy_list[(i)]

#ifndef INCLUDED_MY_H
    #define INCLUDED_MY_H

typedef struct others {
    sfVideoMode mode;
    sfClock *clock_move;
    sfClock *clock_animation;
    sfRenderWindow *window;
    sfEvent event;
} others_t;

typedef struct candy {
    int max_cooldown;
    int is_touched;
    float acceleration_x;
    float acceleration_y;
    float candy_pos_x;
    int cooldown;
    sfIntRect rect;
    sfSprite *candy;
} candy_t;

typedef struct sprites {
    sfSprite *background;
    sfSprite *desk;
    sfSprite *pointer;
    sfSprite *score_icon;
    sfText *score_text;
    int score;
    sfTexture *texture_bg;
    sfTexture *texture_desk;
    sfTexture *texture_pointer;
    sfTexture *texture_score;
    sfTexture *texture_candy;
    candy_t **candy_list;
} sprites_t;

void create_sprite(sprites_t *sprite);
void draw_sprite(sprites_t *sprite, others_t other);
void moove_candy(sprites_t *sprite);
void set_rdm_position(candy_t *candy);
void analyse_events(sprites_t *sprite, others_t other);
void destroy_candy(sprites_t *sprite, int i);
void destroy_animation(candy_t *struct_candy);
void manage_clocks(sprites_t *sprite, others_t *other);
char *score_to_str(int i);
void select_rdm_candy(candy_t *struct_candy, sprites_t *sprite, int i);

#endif
