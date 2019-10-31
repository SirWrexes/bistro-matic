

void *my_revstr(char *e)
{
    char *c = e;
    char g;
  
    while(*c!='\0')
        c++;
    while(e < --c){
        g = *e;
        *e++ = *c;
        *c = g;
    }
    return e;
}