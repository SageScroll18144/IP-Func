#include <stdio.h>

int main(){

    /*
        switch(variavel){
            case valor_1:
            case valor_2:
                .
                .
                .
            case valor_n:
            default:
        }
    */
    int x=1;
    switch(x){
        case 1:
            printf("é um chefe");
            break;
        case 2:
            printf("é dois chefe");
            break;
        default:
            printf("ta bom meu patrao");
            break;
    }


    return 0;
}