#include <stdio.h>
#include <stdlib.h>
extern int asm_min(int *tab, int count);
extern int asm_max(int *tab, int count);

int main(){
    int tab[] = {1,2,3,9,6};
    int min = asm_min(tab,5);
    int max = asm_max(tab,5);
    printf("Minimum: %d\n", min);
    printf("Maksimum: %d\n", max);
    return 0;
};