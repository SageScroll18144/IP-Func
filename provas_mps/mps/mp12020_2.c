#include <stdio.h>
#include <string.h>

typedef struct Aluno{
    char nome[20];
    char mat[20];
    float vetor[5];//notas
    int faltas;
}aluno;

typedef struct Turma{
    int qtd;
    char professor[20];
    char id[5];
    aluno *alunos;
}turma;

int main(){

    int flag=1;
    turma *acm;
    while(flag){
        printf("Escolha uma opção abaixo:\n1)Inserção.\n2)Remoção de Aluno.\n3)Aprovados.\n4)Reprovados.\n5)Turmas.\n6)Sair do programa.\n");
        printf("Pedido.: ");
        int option;
        scanf("%d", &option);
        
        switch(option){
            case 1:
                printf("Informa a quantidade de alunos: ");
                int n;
                scanf("%d", &n);
                acm.qtd=n;
                printf("Para cada aluno informe: (Nome) (matricula) (notas) (qtd de faltas)\n");
                aluno tmp;
                while(n--){
                    scanf(" %s", tmp.nome);
                    scanf(" %s", tmp.mat);
                }
                break;
            case 2:
                break;
            case 3:
                printf("*Aprovados*\n");
                char id_tmp[5];
                scanf(" %s", id_tmp);
                int idx=0;
                while(strcmp(acm[idx++].id, id_tmp)!=0);
                idx--;
                for(int i=0;i<acm[idx].qtd;i++){
                    float media=0;
                    for(int j=0;j<5;j++){
                        media+=acm[idx].alunos[i].vetor[j];
                    }
                    media = media / 5;
                    if(media>=7) printf("%s\n", acm[idx].aluno[i].nome);
                }
                break;
            case 4:
                printf("*Reprovados*\n");
                char id_tmp[5];
                scanf(" %s", id_tmp);
                int idx=0;
                while(strcmp(acm[idx++].id, id_tmp)!=0);
                idx--;
                for(int i=0;i<acm[idx].qtd;i++){
                    float media=0;
                    for(int j=0;j<5;j++){
                        media+=acm[idx].alunos[i].vetor[j];
                    }
                    media = media / 5;
                    if(media<3) printf("%s\n", acm[idx].aluno[i].nome);
                }
                break;
            case 5:
                break;
            case 6:
                break;
        }
    }    

    return 0;
}