#include <stdio.h>

#define maxn 110

int main(){
    //Substring
    char a[maxn];
    char sub_a[maxn];

    int *p = strstr(a, sub_a);

    printf("Existe a substring pertence a string? %s!\n", (p!=NULL)?"Sim":"Nao");

    //Char
    char x;
    char str[maxn];
    
    int idx=0;
    while(str[idx++]!=x);
    if(idx < strlen(str)) printf("Tem esse char aqui!\n");

    //ou

    for(int i=0;i<strlen(str);i++) {
        if(str[i]==x){
            printf("Tem esse char aqui!\n");
        }
    }

    return 0;
}