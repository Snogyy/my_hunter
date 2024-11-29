/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** int_to_str
*/

#include "includes/my.h"

char *score_to_str(int score)
{
    char c;
    char res[3];

    for (int j = 0; j < 3; j++){
        if (score != 0) {
            c = score % 10;
            score = score / 10;
            res[j] = c + 48;
        } else
            res[j] = 48;
    }
    c = res[0];
    res[0] = res[2];
    res[2] = c;
    return strdup(res);
}
