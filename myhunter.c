/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** bs
*/

#include "includes/my.h"

void destroy_all(sprites_t sprite, others_t other)
{
    sfRenderWindow_destroy(other.window);
    sfSprite_destroy(sprite.background);
    sfSprite_destroy(sprite.desk);
    for (int i = 0; i < 3; i++) {
        sfSprite_destroy(CANDY_NB2(i)->candy);
    }
    sfSprite_destroy(sprite.pointer);
    sfSprite_destroy(sprite.score_icon);
    sfText_destroy(sprite.score_text);
    sfTexture_destroy(sprite.texture_bg);
    sfTexture_destroy(sprite.texture_desk);
    sfTexture_destroy(sprite.texture_candy);
    sfTexture_destroy(sprite.texture_pointer);
    sfTexture_destroy(sprite.texture_score);
    sfClock_destroy(other.clock_move);
    sfClock_destroy(other.clock_animation);
}

int main(void)
{
    sprites_t sprite;
    others_t other = {{1080, 1080, 32}, sfClock_create(), sfClock_create()};
    
    srand(time(NULL));
    other.window = sfRenderWindow_create(other.mode, "Sweet Hunter", sfResize | sfClose, NULL);
    if (!other.window)
        return EXIT_FAILURE;
    sfRenderWindow_setMouseCursorVisible(other.window, sfFalse);
    create_sprite(&sprite);
    while (sfRenderWindow_isOpen(other.window)) {
        while (sfRenderWindow_pollEvent(other.window, &other.event))
            analyse_events(&sprite, other);
        manage_clocks(&sprite, &other);
        sfRenderWindow_clear(other.window, sfBlack);
        draw_sprite(&sprite, other);
        sfRenderWindow_display(other.window);
    }
    destroy_all(sprite, other);
    return EXIT_SUCCESS;
}
