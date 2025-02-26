#include <stdio.h>
int main(int argc, char *argv[]){
    printf("Podaj wartość: ");
    int wartosc;
    scanf("%d", &wartosc);
    int padding = 1;
    int liczba=wartosc*wartosc;
    int j;
    int i;
    do{
        liczba/=10;
        padding++;
    }while (liczba!=0);
    for (i = 1; i <= wartosc; i++)
    {
        for (j = 1; j <= wartosc; j++)
        {
            printf("%*X",padding, i * j);
        }
        printf("\n");
        
    }
    return 0;
    
}
