/*
** EPITECH PROJECT, 2024
** myhunter
** File description:
** clock
*/

#include "includes/my.h"

void manage_clocks(sprites_t *sprite, others_t *other)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(other->clock_move)) > 40.0f) {
        moove_candy(sprite);
        sfClock_restart(other->clock_move);
    }
    if (sfTime_asSeconds(sfClock_getElapsedTime(other->clock_animation)) > 0.35f) {
        for (int i = 0; i < 3 && CANDY_NB1(i)->is_touched == 1; i++)
            destroy_animation(CANDY_NB1(i));
        sfClock_restart(other->clock_animation);
    }
}