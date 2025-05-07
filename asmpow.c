#include <stdio.h>
#include <stdlib.h>
extern long asmpow(long x, long n);

int main(){
    long result = asmpow(12,2);
    printf("%ld\n", result);
    return 0;
};