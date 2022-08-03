#include <stdio.h>

#define maxn 110

int main(){
    char a[maxn];
    
    char *split = strtok(a, " ");//string e token
    while(split!=NULL){
        printf("%s\n", split);
        split = strtok(NULL, " ");
    }
    
    return 0;
}