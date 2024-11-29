/*
** EPITECH PROJECT, 2024
** myhunter
** File description:
** events
*/

#include "includes/my.h"

void manage_mouseEvt(sprites_t *sprite, others_t other)
{
    sfVector2f sprite_pos;
    sfFloatRect candy_bounds;
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(other.window);
    sfVector2f mouse_pos_f = {mouse_pos.x, mouse_pos.y};

    for (int i = 0; i < 3; i++) {
        if (CANDY_NB1(i)->is_touched == 1)
            continue;
        sprite_pos = sfSprite_getPosition(CANDY_NB1(i)->candy);
        candy_bounds = sfSprite_getGlobalBounds(CANDY_NB1(i)->candy);
        candy_bounds.left += 40;
        candy_bounds.top += 30;
        candy_bounds.width -= 80;
        candy_bounds.height -= 80;
        if (sfFloatRect_contains(&candy_bounds, mouse_pos_f.x, mouse_pos_f.y)) {
            //printf("%s\n", "Touch!");
            destroy_candy(sprite, i);
            break;
        }
    }
}

void analyse_events(sprites_t *sprite, others_t other)
{
    if (other.event.type == sfEvtClosed)
        sfRenderWindow_close(other.window);
    if (other.event.type == sfEvtMouseButtonPressed)
        manage_mouseEvt(sprite, other);
}
