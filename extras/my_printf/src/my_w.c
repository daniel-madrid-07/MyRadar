/*
** EPITECH PROJECT, 2025
** my put hexadecimal
** File description:
** transform decimal in hexadecimal
*/

#include "../include/my.h"

int my_w_caller(va_list list)
{
    int nb = va_arg(list, int);

    return my_x(nb);
}

int my_w(int nb)
{
    char hexa[] = "012345";
    int nbcopy;
    int count = 0;

    if (nb >= 6)
        count += my_w(nb / 6);
    nbcopy = nb % 6;
    count += my_c(hexa[nbcopy]);
    return count;
}
