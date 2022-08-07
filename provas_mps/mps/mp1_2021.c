#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define maxn 5010

int main(){
    int n, i, j, k;
    printf("Digite a dimensão da matriz: ");
    scanf("%d", &n);

    printf("Digite agora as %d strings que comporão a matriz %d x %d:\n", n*n, n, n);
    char matriz_str[n][n][35];
    for(i=0;i<n;i++) for(j=0;j<n;j++) scanf("%s", matriz_str[i][j]);

    //Primeiro caso
    int flag_tam=1, idx=0;
    while(flag_tam && idx<n-1){
        //vogal
        for(i=0;i<strlen(matriz_str[idx][idx]);i++){
            if(matriz_str[idx][idx][i]=='A'||matriz_str[idx][idx][i]=='E'||matriz_str[idx][idx][i]=='I'||matriz_str[idx][idx][i]=='O'||matriz_str[idx][idx][i]=='U'){
                flag_tam=0;
            }
        }

        //tamanho
        if(strlen(matriz_str[idx][idx]) != 2*idx+1){
            flag_tam=0;
        }

        idx++;
    }
    //Segundo caso
    if(flag_tam){
        char tmp;
        for(i=0;i<n;i++) for(j=0;j<n;j++) for(k=0;k<strlen(matriz_str[i][j]);k++){
            if(i!=j){
                if(matriz_str[i][j][k]=='A'||matriz_str[i][j][k]=='E'||matriz_str[i][j][k]=='I'||matriz_str[i][j][k]=='O'||matriz_str[i][j][k]=='U'||matriz_str[i][j][k]=='a'||matriz_str[i][j][k]=='e'||matriz_str[i][j][k]=='i'||matriz_str[i][j][k]=='o'||matriz_str[i][j][k]=='u'){
                    tmp = matriz_str[i][j][k];
                    tmp = toupper(tmp);    
                    if(tmp!=matriz_str[i][j][k]) flag_tam=0;
                }
            }

        }
    }
    //Gerar a senha
    if(!flag_tam) printf("NÃO A MATRIZ NÃO ATENDE AS CONDIÇÕES!\n");
    else{
        int ans=0;
        char pass_ans[maxn];
        strcpy(pass_ans, "\0");
        for(i=0;i<n;i++) for(j=0;j<n;j++) {
            if((i==0&&j==0)) strcat(pass_ans, matriz_str[0][0]);
            else if(i!=j){
                for(k=0;k<strlen(matriz_str[i][j]);k++) ans+=(int)matriz_str[i][j][k];
                sprintf(pass_ans, "%s%d", pass_ans, ans);
            }else{
                strcat(pass_ans, matriz_str[i][j]);  
            }
            ans=0;
        }

        printf("A senha gerada foi: %s\n", pass_ans);
    }

    return 0;
}