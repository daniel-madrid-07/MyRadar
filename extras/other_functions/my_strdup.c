/*
** EPITECH PROJECT, 2025
** organized
** File description:
** my_strdup
*/

#include "../../include/my.h"

static int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL)
        return 0;
    while (str[i] != '\0')
        i++;
    return i;
}

char *my_strdup(char const *src)
{
    char *dest;
    int len;
    int i = 0;

    if (src == NULL)
        return NULL;
    len = my_strlen(src);
    dest = malloc(sizeof(char) * (len + 1));
    if (dest == NULL)
        return NULL;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
