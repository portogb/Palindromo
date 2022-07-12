#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    char l;
    struct no *ant;
    struct no *prox;
}no;
no *inicioE;
no *inicioD;

void iniciaLista(){
    inicioE = NULL;
    inicioD = NULL;
}

int listaVazia(){
    if(inicioE == NULL)
        return 1;
    return 0;
}

no* criaNo(char letra){
    no *aux = (no*) malloc(sizeof(no));
    if(aux == NULL){
        printf("\nERRO");
    }
    aux -> l = letra;
    aux -> ant = NULL;
    aux -> prox = NULL;
    return aux;
}

void inserirEsquerda(char letra){
    no *aux = criaNo(letra);
    if(listaVazia()){
        inicioE = aux;
        inicioD = aux;
    }else{
        aux -> prox = inicioE;
        inicioE -> ant = aux;
        inicioE = aux;
    }
}

void percorrer(){
    no *aux = inicioE;
    if(!listaVazia()){
        while(aux != NULL){
            printf("%c ", aux -> l);
            aux = aux -> prox;
        }
    }else{
        printf("\nLista vazia\n");
    }
}

void palindromo(){
    no *auxD, *auxE, *aux;
    auxE = inicioE;
    auxD = inicioD;
    aux = auxE;
    while(auxE != NULL && auxD != NULL){
        if(auxE -> l == auxD -> l){
            printf("%c ", aux -> l);
            auxE = auxE -> prox;
            auxD = auxD -> ant;
            aux = auxE;
            if(auxE == NULL && auxD == NULL)
                printf("\nA palavra e um palindromo");
        }else{
            printf("A palavra nao e um palindromo");
            break;
        }
    }
}

int main(){
    char letra;
    int op;
    iniciaLista();
    do{
        printf("Informe uma letra: ");
        fflush(stdin);
        scanf("%s", &letra);
        inserirEsquerda(letra);
        printf("Deseja inserir um novo elemento?(1- Sim)(2- Nao) ");
        scanf("%d", &op);
    }while(op != 2);
    palindromo();
    printf("\n");
    system("pause");
}