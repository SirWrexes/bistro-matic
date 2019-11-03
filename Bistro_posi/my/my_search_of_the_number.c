/*                                                                              
** EPITECH PROJECT, 2019                                                        
** my_search_of_the_number.c                                                            
** File description:                                                            
** fonction pour les nombres negatif                                            
*/

int my_search_of_the_number(char *n1, char *n2, char const *str)
{
    int i = 0;
    int j = 0;
    int yes = 0;
    
    if (str[i] == '-'){
        i++;
        yes = 1;
    }
    for(;str[i] != '-' && str[i] != '+'; i++){
        n1[j] = str[i];
        j++;
    }
    j=0;
    i++;
    for(;str[i] != '\0'; i++){
        n2[j] = str[i];
        j++;
    }
    return 0;
}