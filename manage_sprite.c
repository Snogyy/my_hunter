/*
** EPITECH PROJECT, 2024
** myhunter
** File description:
** manage_sprite
*/

#include "includes/my.h"

void resize_background(sfSprite *sprite, sfTexture *texture)
{
    sfVector2u size_texture = sfTexture_getSize(texture);
    float scaleX = (float)1080 / size_texture.x;
    float scaleY = (float)1080 / size_texture.y;
    sfSprite_setScale(sprite, (sfVector2f){scaleX, scaleY});
}

void set_rdm_position(candy_t *candy)
{
    int min = -230;
    int max = 100;

    if ((rand() % 2) == 1)
        candy->candy_pos_x = rand() % (max - min + 1) + min;
    else {
        int min = 700;
        int max = 1100;
        candy->candy_pos_x = rand() % (max - min + 1) + min; 
    }
    sfSprite_setPosition(candy->candy, (sfVector2f){candy->candy_pos_x, 600});
}

candy_t *add_candy_list(sprites_t *sprite, int i)
{
    candy_t *struct_candy = malloc(sizeof(candy_t));
    CANDY_NB1(i) = struct_candy;
    struct_candy->candy = sfSprite_create();
    return CANDY_NB1(i);
}

void create_candy(sprites_t *sprite)
{
    candy_t *struct_candy;

    sprite->texture_candy = sfTexture_createFromFile("src/candy_sheet.png", NULL);
    sprite->candy_list = malloc(sizeof(candy_t *) * 3);
    for (int i = 0; i < 3; i++) {
        struct_candy = add_candy_list(sprite, i);
        struct_candy->max_cooldown = 20;
        struct_candy->cooldown = 0;
        struct_candy->is_touched = 0;
        struct_candy->acceleration_x = -1;
        sfSprite_setTexture(struct_candy->candy, sprite->texture_candy, sfTrue);
        select_rdm_candy(struct_candy, sprite, i);
        sfSprite_setScale(struct_candy->candy, (sfVector2f){0.4, 0.4});
        set_rdm_position(struct_candy);
    }
}

void create_score(sprites_t *sprite)
{
    sfFont* candy_font = sfFont_createFromFile("src/candycane.ttf");
    
    sprite->score_text = sfText_create();
    sfText_setFont(sprite->score_text, candy_font);
    sfText_setColor(sprite->score_text, sfRed);
    sprite->score = 0;
    sfText_setScale(sprite->score_text, (sfVector2f){2.7, 2.7});
    sfText_setPosition(sprite->score_text, (sfVector2f){930, 5});
    sfSprite_setTexture(sprite->score_icon, sprite->texture_score, sfTrue);
    sfSprite_setScale(sprite->score_icon, (sfVector2f){0.25, 0.25});
    sfSprite_setPosition(sprite->score_icon, (sfVector2f){810, -5});
}

void init_sprite(sprites_t *sprite)
{
    sprite->background = sfSprite_create();
    sprite->desk = sfSprite_create();
    sprite->pointer = sfSprite_create();
    sprite->score_icon = sfSprite_create();
    sprite->texture_bg = sfTexture_createFromFile("src/background1.jpeg", NULL);
    sfTexture_setSmooth(sprite->texture_bg, sfTrue);
    sprite->texture_desk = sfTexture_createFromFile("src/desk.jpeg", NULL);
    sprite->texture_pointer = sfTexture_createFromFile("src/pointer.png", NULL);
    sfTexture_setSmooth(sprite->texture_pointer, sfTrue);
    sprite->texture_score = sfTexture_createFromFile("src/candy_score.png", NULL);
}

void create_sprite(sprites_t *sprite)
{
    init_sprite(sprite);
    sfSprite_setTexture(sprite->background, sprite->texture_bg, sfTrue);
    resize_background(sprite->background, sprite->texture_bg);
    sfSprite_setTexture(sprite->desk, sprite->texture_desk, sfTrue);
    sfSprite_setScale(sprite->desk, (sfVector2f){2.12, 2});
    sfSprite_setPosition(sprite->desk, (sfVector2f){0, 640});
    sfSprite_setTexture(sprite->pointer, sprite->texture_pointer, sfTrue);
    sfSprite_setScale(sprite->pointer, (sfVector2f){0.2, 0.2});
    create_candy(sprite);
    create_score(sprite);
}

void draw_nb_candy(sprites_t *sprite, others_t other)
{
    const int score = sprite->score;
    int nb_candy;

    if (score >= 0 && score < 5)
        nb_candy = 1;
    if (score >= 5 && score < 10)
        nb_candy = 2;
    if (score >= 10)
        nb_candy = 3;
    for (int i = 0; i < nb_candy; i++)
        sfRenderWindow_drawSprite(other.window, CANDY_NB1(i)->candy, NULL); 
}

void draw_sprite(sprites_t *sprite, others_t other)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(other.window);
    sfVector2f mouse_pos_f = {mouse_pos.x - 50, mouse_pos.y - 50};

    sfRenderWindow_drawSprite(other.window, sprite->background, NULL);
    draw_nb_candy(sprite, other);
    sfSprite_setPosition(sprite->pointer, mouse_pos_f);
    sfRenderWindow_drawSprite(other.window, sprite->pointer, NULL);
    sfRenderWindow_drawSprite(other.window, sprite->desk, NULL);
    sfText_setString(sprite->score_text, score_to_str(sprite->score));
    sfRenderWindow_drawText(other.window, sprite->score_text, NULL);
    sfRenderWindow_drawSprite(other.window, sprite->score_icon, NULL);
}
