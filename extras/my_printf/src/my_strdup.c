/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** my_strdup
*/

#include "../include/my.h"

char *my_strdup(char const *src)
{
    int len = 0;
    char *dest;

    if (src == NULL)
        return NULL;
    while (src[len])
        len++;
    dest = malloc(sizeof(char) * (len + 1));
    if (dest == NULL)
        return NULL;
    for (int i = 0; i <= len; i++)
        dest[i] = src[i];
    return dest;
}
