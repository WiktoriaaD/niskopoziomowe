#include <stdio.h>
#include <stdbool.h>

int pn_str_len(const char *str){
    if (str==NULL)
    {
        return -1;
    }
    int length=0;
    while (str[length]!=0)
    {
        length++;
    }
    return length;
    
}

bool pn_str_cmp(const char *a,const char *b){
    int i=0;
    if(a==NULL&&b==NULL)
    {
        return false;
    }
    while(a[i]!=0)
    {
        if(b[i]==0) return false;
        if (a[i]!=b[i]) return false;
        i++;
    }
    if(a[i]==b[i]) return true;
    return false;

}

void pn_str_capitalize(char *str){
    if (str==NULL)
    {
        return;
    }
    if(str[0]>='a' && str[0]<='z'){
        str[0]-=32;
    }
}

void pn_str_trim(char *str){
    int i=pn_str_len(str)-1;
    if (str==NULL)
    {
        return;
    }
    for(i;str[i]==' ';i--){
        str[i]=0; 
    }
    int j=0;
    while (str[j]==' ')
    {
        j++;
    }
    int k;
    for(k=j;str[k]>0;k++){
        str[k-j]=str[k];
        str[j]=0;
    }
}

void pn_str_rev(char *str){
    if (str==NULL)
    {
        return;
    }
    int len=pn_str_len(str);
    for(int i=0;i<pn_str_len(str)/2;i++){
        char tmp=str[i];
        str[i]=tmp;
        str[i] = str[len-1-i];
    }
}

int main(){
    printf("Podaj slowo: ");
    char str[100];
    scanf("%s",&str);
    printf("%d",pn_str_len(str));
    printf("\n");

    char *a="aa";
    char *b = "aaa";
    printf("%d",pn_str_cmp(a,b));
    printf("\n");

    pn_str_capitalize(str);
    printf("%s",str);
    printf("\n");
    
    char wyraz[]="                           a ahalala   ";
    pn_str_trim(wyraz);
    printf("%s",wyraz);
    printf("\n");

    pn_str_rev(wyraz);
    printf("%s",wyraz);
    printf("\n");
    return 0;
}

