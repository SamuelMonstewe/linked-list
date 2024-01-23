#include <stdio.h>
#include <stdlib.h>

typedef struct Lista
{
    int elemento;
    struct Lista *ptrProximoElemento;
}   Lista;


Lista *criarNovoElemento(Lista *ultimoNodeAtual, int elemento){
    
    ultimoNodeAtual->ptrProximoElemento = (Lista *)malloc(sizeof(Lista));
    ultimoNodeAtual->ptrProximoElemento->elemento = elemento;
    ultimoNodeAtual->ptrProximoElemento->ptrProximoElemento = NULL;    

    return ultimoNodeAtual->ptrProximoElemento;
}

void percorrerLista(Lista *primeiroNode){

      if(primeiroNode->ptrProximoElemento == NULL){
        printf("A lista está vazia!");
        return;
    }

    Lista *ptr = primeiroNode->ptrProximoElemento;

    while(ptr != NULL){
        printf("%d", ptr->elemento);
        ptr = ptr->ptrProximoElemento;
    }
}

void limparLista(Lista *lista){
    Lista *ptr = lista->ptrProximoElemento;

    while(ptr != NULL){
        Lista *next = ptr->ptrProximoElemento;
        free(ptr);
        ptr = next;
    }

    free(lista);
}

int main(){

    Lista *header = (Lista *)malloc(sizeof(Lista));
    header->ptrProximoElemento = NULL;
    header->elemento = 0;
    int numero = 0;
    Lista *novoNode;
    Lista *ultimoNode = header;

    for(int i = 0; i < 5; i++){
        printf("Digite um numero:");
        scanf(" %d", &numero);
        novoNode = criarNovoElemento(ultimoNode, numero);
        ultimoNode = novoNode;

    }

    percorrerLista(header);
    limparLista(header);
    return 0;
}