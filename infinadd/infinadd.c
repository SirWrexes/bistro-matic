#include <stdlib.h>
#include <stdio.h>
char my_transformnbr(int res);
int my_strlen(char const *str);
int is_a_nbr(char j);
int my_getnbr(char const *str);
void *my_revstr(char *e);


char *ajout_grand(char *grand, char *petit)
{
    int i = 0;
    int res = 0;
    int retenu = 0;
    char *res3 = malloc(sizeof(char) * my_strlen(grand) * my_strlen(grand));
    
    for(; grand[i] != '\0'; i++)
    {
        if (my_strlen(petit) >= i+1){
            res = is_a_nbr(grand[i]) +  is_a_nbr(petit[i]) + retenu;
            retenu = 0;
            if (res >= 10){
                res = res-10;
                retenu = 1;
            }
            res3[i] = my_transformnbr(res);
        }
        else if (my_strlen(petit) < i+1){
            res = is_a_nbr(grand[i]) + retenu;
            retenu = 0;
            if (res >= 10){
                res = res-10;
                retenu = 1;
            }
            res3[i] = my_transformnbr(res);
        }
    }
    
    res3[i] ='\0';
    if (retenu != 0){
        res3[i] = my_transformnbr(retenu);
        res3[i+1] = '\0';
    }
    return res3;
}
//----------------------------------------------------------------//
char *ajout_egal(char *n1, char *n2)
{
    int i = 0;
    int res = 0;
    int retenu = 0;
    char *res3 = malloc(sizeof(char) * my_strlen(n1) * my_strlen(n2));
        for(; n1[i] != '\0'; i++){
        res = is_a_nbr(n1[i]) +  is_a_nbr(n2[i]) + retenu;
        retenu = 0;
        if (res >= 10){
            res = res-10;
            retenu = 1;
        }
        res3[i] = my_transformnbr(res);
    }
    if(retenu != 0){
        res3[i] = my_transformnbr(retenu);
    }
    return res3;
}



//--------------------------------------------------------//
char *infinadd(char *n1, char *n2)
{
    int taille_n1 = my_strlen(n1);
    int taille_n2 = my_strlen(n2);
    char *res2 = malloc(sizeof(char) * my_strlen(n1) * my_strlen(n2));
    int i = 0;
    
    my_revstr(n1);
    my_revstr(n2);
    if (taille_n1>taille_n2)
       res2 = ajout_grand(n1 , n2);
    if (taille_n1 < taille_n2)
        res2 = ajout_grand(n2 , n1);
    if (taille_n1 == taille_n2)
        res2 = ajout_egal(n1 , n2);     
    my_revstr(res2);
    return res2;
    
}
/*int main()
{
    char  n1[100000] = "50";
    char  n2[100000] = "100";
    char *res = malloc(sizeof(char) * my_strlen(n1) * my_strlen(n2));
    
    res = infinadd(n1, n2);
    printf("%s",res);
}*/