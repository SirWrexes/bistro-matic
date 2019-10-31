#include <stdlib.h>
#include <stdio.h>

char my_transformnbr(int res);
int is_a_nbr(char j);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void *my_revstr(char *e);
int my_search_of_the_number(char *n1, char *n2, char const *str);
void complement(char *pos, char *neg, char *tab_res);
void rajout_final(char *tab_res_fin, char const *tab_res, int j);
char *sous (char *pos, char *neg);
int who_is_neg(char const *str);
int who_is_bigger(char const *str);
char *infinadd(char *nb1, char *nb2);

char *recall(char const *str , char e)
{
    int i = 0;
    int j = 0;
    char *res4 = malloc(sizeof(char) * my_strlen(str) +10);
    
    res4[i] = e;
    i++;
    for(;str[j] != '\0'; j++)
    {
        res4[i] = str[j];
        i++;
    }
    
    return res4; 
}

char *my_soustraction(char const *str){
    char *n1 = malloc(sizeof(char) * my_strlen(str));
    char *n2 = malloc(sizeof(char) * my_strlen(str));
    int who_is = who_is_neg(str);
    char *res6 = malloc (sizeof(char) * my_strlen(str)*2);
    
    my_search_of_the_number(n1, n2, str);
    my_revstr(n1); 
    my_revstr(n2);
    if (who_is == 3)
        res6 = sous(n1 , n2);
    else if (who_is == 2)
        res6 = sous(n2 , n1);
    else if (who_is == 1){
        my_revstr(n1); 
        my_revstr(n2);
        res6 = infinadd(n1,n2);        
        res6 = recall (res6 , '-');
     }
     return res6;
}

/*int main(int argc, char **argv){
    char *res = malloc(sizeof(char) * my_strlen(argv[1]));
    res = my_soustraction(argv[1]);
    printf("%s = %s",argv[1], res);
    return 0;
}*/
//cas 3 :100-50 fait
//cas 2 :-100+50 fait
//cas 1 :-100-50 fait
//cas 0 : 100-200 non fait