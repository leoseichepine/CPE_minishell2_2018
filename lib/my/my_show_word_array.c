/*
** EPITECH PROJECT, 2018
** CPE_BSQ_2018
** File description:
** __DESCRIPTION__
*/

#include "my.h"

int my_show_word_array(char **tab, int rows)
{
    for (int i = 0; i < rows; i++)
        my_putstr(tab[i]);
    return (0);
}
