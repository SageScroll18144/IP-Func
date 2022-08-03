#include <stdio.h>

#define maxn 110

int main(){
    char str[maxn];
    int tamanho = strlen(str);

    //ou
    int idx=0;
    while(str[idx++]!='\0');
    
    idx;//tamanho

    return 0;
}