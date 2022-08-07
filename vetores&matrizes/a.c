#include <stdio.h>
#include <string.h>

#define maxn 110

int main(){

    //zero-based
    int n=10;
    int vet[n]; 
    vet[0];//primeiro elemento
    vet[1];//segundo elemento

    int mat[maxn][maxn];
    //vetor de vetores

    memset(vet, 0, n*sizeof(vet[0]));//preenche tudo com zero(segundo parametro)

    return 0;
}