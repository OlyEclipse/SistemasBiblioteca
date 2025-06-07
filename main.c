#include <stdio.h>

typedef struct usuario{
    char login[100];
    char senha[100];
}usuario[200];

typedef struct livro{
    char nomeLivro[100];
    char nomeAutor[100];
    char tema[100];
    int isbn;
    float avaliacao;
}livro[1000];

typedef struct adm{
    char login[100];
    char senha[100];
}adm[50];

//---FUNCOES
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
    printf(":)");
}
