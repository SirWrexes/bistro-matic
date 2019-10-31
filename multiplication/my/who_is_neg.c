/*                                                                              
** EPITECH PROJECT, 2019                                                        
** my_transformnbr.c                                                            
** File description:                                                            
** fonction pour les nombres negatif                                            
*/
int is_a_nbr(char j);

int who_is_neg(char const *str)
{
  int count = 0;
  int i = 0;
  int j = 0;
  int v = 0;
  int res = 0;
  for(; str[i] != '\0'; i++){
      if (str[i] == '-')
          count ++;
  }
  if (count == 2)
    return 1;
  if (count == 1){
     i = 0;
     for(; str[i] != '\0'; i++){
         if (str[i] == '-' && v == 0)
             return 2;
      
         else if (is_a_nbr(str[i]) != -1)
             v = 1;
        
         else if (str[i] == '-' && v == 1)
             return 3;
    }
  }
}