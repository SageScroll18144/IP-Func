#include <stdio.h>

int main(){
    /*tipo nome = valor;*/

    int qtd_copos = 10;//valor inteiro
    
    //operaçẽos aritméticas
    qtd_copos = qtd_copos + 1
    qtd_copos+=10;
    qtd_copos++;

    float altura = 1.87;//valor real
    double pi = 3.141516;//valor real com maior precisão

    char x = 'a';//caractere
    x = x + 1;//na memória todo char é um inteiro representado na tabela ASCII, assim podemos 
                //realizar varias operaçẽos

    int tam = sizeof(int);//retorna o tamanho de cada tipo ou variavel na memoria em bytes     

    return 0;
}