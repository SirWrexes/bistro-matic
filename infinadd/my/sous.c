/*                                                                              
** EPITECH PROJECT, 2019                                                        
** my_transformnbr.c                                                            
** File description:                                                            
** fonction pour les nombres negatif                                            
*/
#include <stdlib.h>
#include <stdio.h>

int my_strlen(char const *str);
void complement(char *pos, char *neg, char *tab_res);
void *my_revstr(char *e);
int who_is_bigger(char const *str);
void rajout_final(char *tab_res_fin, char const *tab_res, int j);

char *sous (char *pos, char *neg)
{
    char *tab_res = malloc(sizeof(char) *  (my_strlen(pos)) * my_strlen(neg));
    char *tab_res_fin = malloc(sizeof(char) *  (my_strlen(pos)) * my_strlen(neg));
    int j = 0;

    if(my_strlen(neg) == my_strlen(pos) && who_is_bigger(neg) < who_is_bigger(pos))
        complement(pos, neg, tab_res);  
    else if(my_strlen(neg) == my_strlen(pos) && who_is_bigger(neg) > who_is_bigger(pos)){
        complement(neg, pos, tab_res);
        tab_res_fin[j] = '-';
        j++;
    }
    else if(my_strlen(neg) < my_strlen(pos))
        complement(pos, neg, tab_res);
    else if(my_strlen(neg) > my_strlen(pos)){
        complement(neg, pos, tab_res);
        tab_res_fin[j] = '-';
        j++;
    } 
    else if(my_strlen(neg) == my_strlen(neg) && who_is_bigger(neg) == who_is_bigger(pos))
        tab_res_fin[j] = '0';  
    my_revstr(tab_res);
    rajout_final(tab_res_fin, tab_res, j);
    return tab_res_fin;
}