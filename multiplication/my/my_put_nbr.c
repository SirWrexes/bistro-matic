/*
** EPITECH PROJECT, 2019
** my_put_nbr.c
** File description:
** réussis
*/



#include <unistd.h>

void my_putchar(char c);


void my_put_nbr(int nb)
{
  if (nb > 9)
    my_put_nbr(nb / 10);
    if (nb < 0){
    nb = nb * -1;
    my_putchar('-');
    my_put_nbr(nb / 10);
  }  
  my_putchar(nb % 10 + '0');
}