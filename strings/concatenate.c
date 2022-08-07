#include <stdio.h>

#define maxn 110

int main(){
    char a[maxn];
    char b[maxn];

    strcat(a, b);//realiza a operação a = a + b

    char c[maxn];
    char x;

    strncat(a, &x, 1);//realiza a operação (string) a = (string) a + (char) x

    char d[maxn];
    char e[maxn];
    strcpy(d, e);//copia e para d

    char f[maxn];
    sprintf(f, "%s %d", "substitui", 10); //copia para 'f' a concatenação da string + inteiro

    return 0;
}