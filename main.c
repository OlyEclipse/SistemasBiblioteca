#include <stdio.h>
void cadastrar();
void entrar();
int main(){
    int op;
    do{
        printf("-----------------------------------------MENU-------------------------------------------\n");
        printf("1-Cadastrar\n2-Entrar\n3-Sair\n");
        printf("----------------------------------------------------------------------------------------\n");
        scanf("%d",&op);
        switch(op){
            case 1:
                cadastrar();
            break;
            case 2:
                entrar();
            break;
            case 3:
            break;
            default:
            break;
        }
    }while(op!=3);
    return 0;
}
void cadastrar(){
    printf(":)");
}
void entrar(){
    printf(":()");
}
