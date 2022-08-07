#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Transicao{
    int estado_atual, estado_futuro, charAReconhecer;
    char estado_final;
}tt;

tt * carregaAutomato(char *nome, long *numEstados){
    char nome_cp[100];
    strcpy(nome_cp, nome);
    FILE *file = fopen(strcat(nome_cp, ".bin"), "rb");
    fseek(file, 0L, SEEK_END);

    *numEstados = ftell(file)/sizeof(tt);

    tt *vet = (tt*)malloc((*numEstados)*sizeof(tt));
    

    if(file==NULL){
        printf("Tá vazio chefe!\n");
        exit(1);
    } 
    fread(vet, sizeof(tt), *numEstados, file);

    fclose(file);

    return vet;
}

void gravaStatus(FILE *file, char *entrada, int status){
    entrada = (status == -1) ? "erro de reconhecimento\n" : ((status) ? "reconhecida\n" : "não reconhecida\n");
    fputs(entrada, file);
}
long *localizaEstado(tt *automato, long numEstados, int estadoAtual, int *numEstadosAtuais, char qual){
    long *vet = (long*)malloc(*numEstadosAtuais*sizeof(long));//armazena os indices de 'automato'
    if(qual-'0'){
        for(int i=0;i<numEstados;i++) vet[i] = automato[i].estado_futuro;
    }else{
        for(int i=0;i<numEstados;i++) vet[i] = automato[i].estado_atual;
    }

    return vet;
}
int avaliaTransicao(tt *automato, long numEstados, int estado_atual, char charAtual){
    int n = numEstados, *numEstadosAtuais = &n;
    long *vet = localizaEstado(automato, numEstados, estado_atual, numEstadosAtuais, '1');
    for(int i=0;i<numEstados;i++){
        if(vet[i]==estado_atual && (int)charAtual == automato[i].charAReconhecer){
            return automato[i].estado_futuro;
        }
    }
    return -1;
}
void reconhece(FILE *file, tt *automato, long numEstados, char *entrada){
    int lim = sizeof(entrada)/sizeof(char);
    char *str;
    for(int i=0;i<lim;i++){
        int ans = avaliaTransicao(automato, numEstados, 0, entrada[i]);
        if(ans == -1){
            gravaStatus(file, str, -1);
        }else if(lim-1==i&&ans<numEstados){
            gravaStatus(file, str, 0);
        }else{
            gravaStatus(file, str, 1);
        }
    }
} 

int main(){

    char file_name[100];
    scanf("%100s", &file_name);
    long *numEstados;
    tt *automato = carregaAutomato(file_name, numEstados);

    FILE *file_out = fopen(strcat(file_name, ".txt"), "w");
    char str_in[100];
    while(fgets(str_in, 100, stdin) && !(str_in[0]=='.' && str_in[1]=='\n')){
        reconhece(file_out, automato, *numEstados, file_name);
    } 
    fclose(file_out);
    return 0;
}