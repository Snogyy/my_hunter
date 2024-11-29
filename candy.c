/*
** EPITECH PROJECT, 2024
** myhunter
** File description:
** candy
*/

#include "includes/my.h"

void select_rdm_candy(candy_t *struct_candy, sprites_t *sprite, int i)
{
    int pos[3] = {0, 500, 1000};
    int randomIndex = rand() % 3;
    CANDY_NB1(i)->rect.top = pos[randomIndex];
    CANDY_NB1(i)->rect.left = 0;
    CANDY_NB1(i)->rect.width = 500;
    CANDY_NB1(i)->rect.height = 500;
    sfSprite_setTextureRect(struct_candy->candy, struct_candy->rect);
}

void calculate_acceleration(candy_t *candy)
{
    int min = -34;
    int max = -28; 

    candy->acceleration_y = rand() % (max - min + 1) + min;
    if (candy->candy_pos_x <= 100) {
        max = 11;
        min = 17;
        candy->acceleration_x = rand() % (max - min + 1) + min;
    } else {
        max = -11;
        min = -17;
        candy->acceleration_x = rand() % (max - min + 1) + min;
    }
}

void reset_candy(candy_t *struct_candy, sprites_t *sprite, int i)
{
    if (struct_candy->cooldown == struct_candy->max_cooldown) {
        set_rdm_position(struct_candy);
        calculate_acceleration(struct_candy);
        select_rdm_candy(struct_candy, sprite, i);
        if (struct_candy->is_touched == 1) {
            struct_candy->rect.left = 0;
            sfSprite_setTextureRect(struct_candy->candy, struct_candy->rect);
        }
        struct_candy->is_touched = 0;
        struct_candy->cooldown = 0;
    } else
        struct_candy->cooldown += 1;
}

void moove_candy(sprites_t *sprite)
{
    sfVector2f position;
    candy_t *struct_candy;

    for (int i = 0; i < 3; i++) {
        struct_candy = CANDY_NB1(i);
        position = sfSprite_getPosition(struct_candy->candy);
        if (struct_candy->acceleration_x == -1)
            calculate_acceleration(struct_candy);
        if (position.y < 650) {
            struct_candy->acceleration_y += 1;
            sfSprite_move(struct_candy->candy, (sfVector2f){0, struct_candy->acceleration_y});
        }
        sfSprite_move(struct_candy->candy, (sfVector2f){struct_candy->acceleration_x, 0});
        if (position.y > 650) 
            reset_candy(struct_candy, sprite, i);
    }
}

void destroy_animation(candy_t *struct_candy)
{
    if (struct_candy->rect.left == 1000)
        struct_candy->rect.left = 500;
    else
        struct_candy->rect.left += 500;
    sfSprite_setTextureRect(struct_candy->candy, struct_candy->rect);
}

void destroy_candy(sprites_t *sprite, int i)
{
    candy_t *struct_candy = CANDY_NB1(i);

    destroy_animation(struct_candy);
    struct_candy->acceleration_x = 0;
    struct_candy->acceleration_y = 5;
    struct_candy->is_touched = 1;
    sprite->score += 1;
}
