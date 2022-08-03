#include <stdio.h>

#define maxn 110

int main(){
    char a[maxn];
    char b[maxn];

    strcmp(a, b);//retorno < 0 : se a for lexicograficamente menor do que b
                 //retorno > 0 : se a for lexicograficamente maior do que b
                 //retorno == 0 : se a for igual à b

    return 0;
}