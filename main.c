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
void cadastrarlivro ();
void verifLivro();
void removerLivro();
void menuUser();
void menuAdm();
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
//MENUS USUARIO--------------------
void menuUser(){
} 
// MENU ADMIN
void menuAdm(){
    int op;
    do{
        printf("-----------------------------------------MENU ADM-------------------------------------------\n");
        printf("1-Cadastrar Livro\n2-Verificar livros\n3-Excluir Livro\n4-Sair\n");
        printf("----------------------------------------------------------------------------------------\n");
        scanf ("%i", &op);
        switch (op){
            case 1:
                cadastrarlivro();
            break;
            case 2:
                verifLivro ();
            break;
            case 3:
                removerLivro ();
            break;
            case 4:
            break;
            default:
            break;    
        }
    } while (op != 4);

}

void cadastrarlivro(){ //cadastro dos livros
    printf("-----------------------------------------CADASTRO LIVRO-------------------------------------------\n");
    printf ("Nome do livro: ");
    scanf (" %s", livro[quantLivro].nomeLivro);
    printf ("Nome do autor: ");
    scanf (" %s", livro[quantLivro].nomeAutor);
    printf ("Tema do livro: ");
    scanf (" %s", livro[quantLivro].tema);
    printf ("ISBN do livro: ");
    scanf (" %i", &livro[quantLivro].isbn);

    quantLivro ++;
    printf ("Livro %i cadastrado com sucesso!\n", quantLivro);
}

void verifLivro (){ //lista de livros apos serem cadastrados 
    printf ("-----------------------------------------LISTA DE LIVROS-------------------------------------------\n");
    for(int i = 0; i < quantLivro; i++) {
        printf("Livro %i:\n", i+1);
        printf("Titulo do livro: %s\n", livro[i].nomeLivro);
        printf("Autor do livro: %s\n", livro[i].nomeAutor);
        printf("Tema do livro: %s\n", livro[i].tema);
        printf("ISBN: %d\n", livro[i].isbn);
    }
}

void removerLivro (){ //admin pode remover algum livro
    int isbn, i, j, exist = 0; //assume que o isbn nao existe ate provar o contrario
    printf ("Digite o ISBN do livro que deseja remover: ");
    scanf ("%i", &isbn);
        
    for(i = 0; i < quantLivro; i++) {
        if(livro[i].isbn == isbn) {
            exist = 1;
            for(j = i; j < quantLivro - 1; j++) {
                livro[j] = livro[j+1];
            }
            quantLivro--;
            printf("Livro removido com sucesso!\n");
            break;
        }
    }
    
    if(!exist) {
        printf("Livro com ISBN %i nao encontrado.\n", isbn);
    }
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