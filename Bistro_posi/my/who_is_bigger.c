/*                                                                              
** EPITECH PROJECT, 2019                                                        
** my_transformnbr.c                                                            
** File description:                                                            
** fonction pour les nombres negatif                                            
*/

int is_a_nbr(char j);
int my_strlen(char const *str);

int who_is_bigger(char const *str)
{
  int res = 0;
  int i = 0;
  
  for (;i< my_strlen(str); i++)
      res = res + is_a_nbr(str[i]);
  return res;
}