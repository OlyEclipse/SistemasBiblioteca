#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int quantU = 0;
int quantLivro = 0;

typedef struct{
    char login[100];
    char senha[100];
}Usuarios;
Usuarios user[100];

typedef struct{
    char nomeLivro[100];
    char nomeAutor[100];
    char tema[100];
    int isbn;
    float avaliacao;
}Livros;
Livros livro[100];

typedef struct{
    char login[100];
    char senha[100];
}Administrador;
Administrador adm;

//---FUNCOES
void cadastrar();
void entrar();
int verifCad(char loginTeste[100]);
int verifLogin(char loginTeste[100]);
int verifSenha(char senhaTeste[100],int indiceLogin);
void menuUser();
int menuAdm();
int main(){
    strcpy(adm.login, "adm");
    strcpy(adm.senha, "senhaadm");
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
//VERIFICACOES-------------
int verifCad(char loginTeste[100]){
    if(strcmp(loginTeste,"adm")==0){
        return 0;
    }
    //ve se ha um login igual
    for(int i=0;i<quantU;i++){
        if(strcmp(loginTeste,user[i].login)==0){
            return 0;
        }
    }
    return 1;
}
int verifLogin(char loginTeste[100]){
    //ve se ha um login igual
    if(strcmp(loginTeste,"adm")==0){
        return -2;
    }
    for(int i=0;i<quantU;i++){
        if(strcmp(loginTeste,user[i].login)==0){
            return i;
        }
    }
    return -1;
}
int verifSenha(char senhaTeste[100],int indiceLogin){
    if(strcmp(senhaTeste,user[indiceLogin].senha)==0){
        return 0;
    }
    return 1;
}
//-------------------------
//MENUS--------------------
void menuUser(){
    printf("");
}
int menuAdm(){
    int op;
    do{
        printf("-----------------------------------------MENU-------------------------------------------\n");
        printf("1-Cadastrar Livro\n2-Excluir Livro\n3-Sair\n");
        printf("----------------------------------------------------------------------------------------\n");
        scanf("%d",&op);
        switch(op){
            case 1:
            break;
            case 2:
            break;
            case 3:
            return 0;
            break;
            default:
            break;
        }
    }while(op!=3);
}
//-------------------------
void cadastrar(){
    char loginTeste[100];
    do{
        printf("Login:");
        scanf(" %s",loginTeste);
        if(verifCad(loginTeste)==0){
            printf("Esse Login ja existe\n");
        }
    }while(verifCad(loginTeste)==0);
    printf("Senha:");
    scanf(" %s",user[quantU].senha);
    //adiciona o novo usuario
    strcpy(user[quantU].login, loginTeste);
    //atualiza o numero de usuarios
    quantU++;
}
void entrar(){
    char loginTeste[100];
    char senhaTeste[100];
    int indiceLogin;
    do{
        printf("Login:");
        scanf(" %s",loginTeste);
        indiceLogin = verifLogin(loginTeste);
        if(indiceLogin==-1){
            printf("Esse Login nao existe\n");
        }
    }while(indiceLogin==-1);
    if(indiceLogin!=-2){
        do{
            printf("Senha:");
            scanf(" %s",senhaTeste);
            if(verifSenha(senhaTeste,indiceLogin)==1){
                printf("Senha incorreta\n");
            }
        }while(verifSenha(senhaTeste,indiceLogin)==1);
        menuUser();
    }else{
        do{
            printf("Senha:");
            scanf(" %s",senhaTeste);
            if(strcmp(senhaTeste,adm.senha)!=0){
                printf("Senha incorreta\n");
            }
        }while(strcmp(senhaTeste,adm.senha)!=0);
        menuAdm();
    }
}