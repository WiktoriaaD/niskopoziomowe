#include <stdio.h>
int main(int argc, char *argv[]){
    printf("Podaj wartość/wartosci: ");
    int wartosc;
    scanf("%d", &wartosc);
    int padding = 1;
    int liczba=wartosc*wartosc;
    int j;
    int i;
    if (argc>1) 
    do{
        liczba/=16;
        padding++;
    }while (liczba!=0);
    else 
    do{
        liczba/=10;
        padding++;
    }while (liczba!=0);

    if(argc>1)
    {
        for (i = 1; i <= wartosc; i++)
        {
            for (j = 1; j <= wartosc; j++)
            {
                printf("%*X",padding, i * j);
            }
            printf("\n");
        
        }
    }
    else
    {
        for (i = 1; i <= wartosc; i++)
        {
            for (j = 1; j <= wartosc; j++)
            {
                printf("%*d",padding, i * j);
            }
            printf("\n");
        
        }
    }
    return 0;
}
