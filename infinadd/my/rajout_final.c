/*                                                                              
** EPITECH PROJECT, 2019                                                        
** my_transformnbr.c                                                            
** File description:                                                            
** fonction pour les nombres negatif                                            
*/

void rajout_final(char *tab_res_fin, char const *tab_res, int j)
{
  int i = 0;
  for (;tab_res[i] != '\0';i++){
     tab_res_fin[j] = tab_res[i];
     j++;
  }
  tab_res_fin[j++] = '\0'; 
}