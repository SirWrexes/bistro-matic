#include <stdlib.h>
#include <stdio.h>

int is_a_nbr(char j);
void my_revstr(char *e);
int my_strlen(char const *str);
char my_transformnbr(int res);
char *infinadd(char *n1, char *n2);

//_______________________________________________________
void add_zero_beg(char* res8, int i)
{
    int j = 0;
    
    for (;j != i; j++){
        res8[j-1] = '0';
    }
}

//_______________________________________________________
int search_ret(int res_int)
{
    int res = 0;
    
    while (res_int >= 10){
        res_int = res_int / 10;
        res++;
    }
    return res;  
}
//________________________________________________________
char *mltp_same(char const *lit, char const *big)
{
    int i = 0;
    int ret = 0;
    int j = 0;
    int res_int = 0;
    char *res8 = calloc(0, sizeof(char) * my_strlen(lit) * my_strlen(big));
    char *res_rajout = malloc(sizeof(char) * my_strlen(lit) * my_strlen(big));
    
    for (;lit[i] != '\0'; i++){
    add_zero_beg(res8 , i);
        for (;big[j] != '\0'; j++){
            res_int = (is_a_nbr(big[j]) * is_a_nbr(lit[i])) +ret;
            ret = 0;
            if (res_int >= 10){
                ret = search_ret(res_int);
                res_int = res_int % 10;
            }
        res_rajout[j+i] = my_transformnbr(res_int);
        }
    j = 0;
    res8 = infinadd (res8, res_rajout);
    res_rajout = NULL;
    res_rajout = malloc(sizeof(char) * my_strlen(lit) * my_strlen(big));
    }
    printf("%s", res8);
}
//____________________________________________________________//
char *infinmultiplication(char *n1, char *n2)
{
    int i = 0;
    int res_int;
    char *res7 = malloc(sizeof(char) * my_strlen(n1) * my_strlen(n2));
    int taille_n1 = my_strlen(n1);
    int taille_n2 = my_strlen(n2);
    
    my_revstr(n1);
    my_revstr(n2);
    /*if (taille_n1  < taille_n2)
        res7 = mltp(n1, n2);
    else if (taille_n2  < taille_n1)
        res7 = mltp(n2, n1);*/
     if (taille_n2 == taille_n1)
        res7 = mltp_same(n2, n1);
    return res7;
}


//______________________________________________________________//
int main()
{
    char n1[10000] = "77";
    char n2[10000] = "45";
    //= 3300
    char *res = malloc(sizeof(char) * 1000 * 1000);
    
    res = infinmultiplication(n1, n2);
    return 0;
}
