int is_a_nbr(char j)
{
    if (j=='0')
       { return 0;}
    if (j=='1')
       { return 1;}
    if (j=='2')
       { return 2;}
    if(j=='3')
        {return 3;}
    if (j=='4')
        {return 4;}
    if (j=='5')
        {return 5;}
    if(j=='6')
        {return 6;}
    if (j=='7')
        {return 7;}
    if (j=='8')
        {return 8;}
    if(j=='9')
        {return 9;}
    
    return -1;
}


int my_getnbr(char const *str)
{   int j = 0;
    int i = 0;
    int b;
    int res = 0;
    int pui = 1;
    while(is_a_nbr(str[i])==-1)
    {
        i=i+1;
    }
    j=i;
    while (is_a_nbr(str[j])!=-1){
        b=is_a_nbr(str[j]);
        i=j;
    while (is_a_nbr(str[i+1])!=-1){
	pui=pui*10;
        i++;
	}
    b=b*pui;
    res=res+b;
    j++;
    pui=1;
    }
    return res; 
}
