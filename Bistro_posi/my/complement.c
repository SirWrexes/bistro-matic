/*                                                                              
** EPITECH PROJECT, 2019                                                        
** complement.c                                                            
** File description:                                                            
** fonction pour les nombres negatif                                            
*/
char my_transformnbr(int res);
int my_strlen(char const *str);
int is_a_nbr(char j);

void complement(char *pos, char *neg, char *tab_res)
{
  int i = 0;
  int ret = 0;
  int res =0;
  
  for(;i < my_strlen(pos); i++){
      if (i < my_strlen(neg)){
          res = is_a_nbr(pos[i]) - is_a_nbr(neg[i]) - ret;
          if (res >= 0){
              tab_res[i] = my_transformnbr(res);
              ret = 0;
              }
          else if (res < 0){
              res = (is_a_nbr(pos[i]) + 10) - is_a_nbr(neg[i]) - ret;
              tab_res[i] = my_transformnbr(res);
              ret = 1;
           }
      }    
      if (i >= my_strlen(neg)){
          res = is_a_nbr(pos[i]) - ret;
          ret = 0;
              if (res < 0){
                  res = (is_a_nbr(pos[i]) + 10) + res;
                  tab_res[i] = my_transformnbr(res);
                  ret = 1;
              }
          tab_res[i] =  my_transformnbr(res);
      }
   }
}