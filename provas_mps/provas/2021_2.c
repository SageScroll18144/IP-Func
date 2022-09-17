#include <stdio.h>
#include <stdlib.h>

typedef struct{
    float pReal, pImag;

}Complexo;

void empilhe(Complexo **cPilha, Complexo umC, int *tPilha);
Complexo desempilhe(Complexo **cPilha, int *tPilha);
Complexo topo(Complexo *cPilha, int tPilha);
int pilhaVazia(Complexo *cPilha, int tPilha);
void salvePilha(Complexo *cPilha, int tPilha);
Complexo *recuperePilha(int *tPilha);

int main(){

    Complexo *cPilha = NULL;
    int tPilha = 0;

    // Complexo x;
    // x.pImag=1;
    // x.pReal=1;

    // empilhe(&cPilha, x, &tPilha);
    // printf("%d\n", tPilha);
    // // empilhe(&cPilha, x, &tPilha);
    // // printf("%d\n", tPilha);
    // desempilhe(&cPilha, &tPilha);
    // printf("%d\n", tPilha);

    if(pilhaVazia(cPilha, tPilha)){
        printf("Tudo certo com a pilha inicial\n");
        Complexo a;
        a.pReal = 2.5;
        a.pImag = 3.5;

        empilhe(&cPilha, a, &tPilha);

        a.pReal = -1.5;
        a.pImag = 2.0;
        empilhe(&cPilha, a, &tPilha);

        Complexo elem_topo = topo(cPilha, tPilha);

        if(elem_topo.pReal == a.pReal && elem_topo.pImag == a.pImag){
            salvePilha(cPilha, tPilha);
            desempilhe(&cPilha, &tPilha);
            desempilhe(&cPilha, &tPilha);

            int len_ans = 0;
            Complexo *ans = recuperePilha(&len_ans);
            Complexo top = desempilhe(&ans, &len_ans);
            printf("Conteudo: Real.: %.2f, Imagem.: %.2f\n", top.pReal, top.pImag);
            top = desempilhe(&ans, &len_ans);
            printf("Conteudo: Real.: %.2f, Imagem.: %.2f\n", top.pReal, top.pImag);

            printf("\n%s\n", (ans == cPilha)?"São iguais!":"Não são iguais...");

            free(ans);
        }
    }

    free(cPilha);
    return 0;
}

void empilhe(Complexo **cPilha, Complexo umC, int *tPilha){
    //LIFO
    Complexo *tmp = *cPilha;
    *cPilha = (Complexo *) realloc(*cPilha, (*tPilha + 1) * sizeof(Complexo));
    if(*cPilha == NULL){
        printf("Deu errado!\n");
        free(tmp);
        exit(1);
    }

    (*cPilha)[*tPilha] = umC;
    (*tPilha)++;
}
Complexo desempilhe(Complexo **cPilha, int *tPilha){
    Complexo ans;
    if(*tPilha > 0){
        Complexo *tmp = *cPilha;
        ans = (*cPilha)[*tPilha-1];
        if(*tPilha == 1){
            free(tmp);
            *cPilha = NULL;
        }
        else{
            
            *cPilha = (Complexo *) realloc(*cPilha, (*tPilha-1) * sizeof(Complexo));
            
            if(*cPilha == NULL){
                printf("Deu errado!\n");
                free(tmp);
                exit(1);
            }
        }
        (*tPilha)--;
    }

    return ans;
}
Complexo topo(Complexo *cPilha, int tPilha){
    return cPilha[tPilha-1];
}
int pilhaVazia(Complexo *cPilha, int tPilha){
    return (cPilha == NULL || tPilha == 0);
}
void salvePilha(Complexo *cPilha, int tPilha){
    FILE *file = fopen("pilha.bin", "wb");
    if(file == NULL){
        printf("\t\tNão foi possivel abrir o arquivo\n");
        exit(1);
    }
    fwrite(&tPilha, sizeof(int), 1, file);
    fwrite(cPilha, sizeof(Complexo), tPilha, file);
    fclose(file);
}
Complexo *recuperePilha(int *tPilha){
    FILE *file = fopen("pilha.bin", "rb");
    if(file == NULL){
        printf("\t\tNão foi possivel abrir o arquivo\n");
        exit(1);
    }
    fread(tPilha, sizeof(int), 1, file);
    
    Complexo *cPilha = (Complexo *)malloc(*tPilha * sizeof(Complexo));
    fread(cPilha, sizeof(Complexo), *tPilha, file);
    fclose(file);

    return cPilha;
}