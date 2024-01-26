#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int elemento;
    int posicao;
    struct Node *ptrProximoElemento;
}   Node;


Node *criarNovoNode(Node *ultimoNodeAtual, __uint8_t elemento){
    
    ultimoNodeAtual->ptrProximoElemento = (Node *)malloc(sizeof(Node));
    __uint8_t posicaoNovoNode = ultimoNodeAtual->posicao;
    posicaoNovoNode++;
    ultimoNodeAtual->ptrProximoElemento->elemento = elemento;
    ultimoNodeAtual->ptrProximoElemento->posicao = posicaoNovoNode;
    ultimoNodeAtual->ptrProximoElemento->ptrProximoElemento = NULL;    

    return ultimoNodeAtual->ptrProximoElemento;
}

void percorrerLista(Node *primeiroNode){

      if(primeiroNode->ptrProximoElemento == NULL){
        printf("A lista está vazia!");
        return;
    }

    Node *ptr = primeiroNode->ptrProximoElemento;

    printf("Elementos na lista:");
    while(ptr != NULL){
        printf("| %u | ", ptr->elemento);
        ptr = ptr->ptrProximoElemento;
    }
}

void destruirLista(Node *head){       
    Node *temp;
    Node *nodeAtual;
    temp = head;

    while(temp != NULL){
        nodeAtual = temp->ptrProximoElemento;
        free(temp);
        temp = nodeAtual;
    }
    head = NULL;
}

void removerNode(Node *head, int posicao){

    
}

Node *encontrarElemento(Node *lista, int elementoProcurado){

    Node *nodeAtual = lista->ptrProximoElemento;

    while(nodeAtual != NULL){   
        if(nodeAtual->elemento == elementoProcurado){
            return nodeAtual;   
        }
        nodeAtual = nodeAtual->ptrProximoElemento;
    }
    return NULL;
}

int main(){

    Node *HEAD = (Node *)malloc(sizeof(Node));
    Node *ultimoNode = HEAD;
    Node *novoNode;
    Node *nodeEncontrado;
    int flag = -1;
    int opcao = 0;
    int elemento;
    int elementoParaEncontrar;

    HEAD->ptrProximoElemento = NULL;
    HEAD->elemento = 0;
    HEAD->posicao = 0;

    while(flag == -1){
        system("clear");
        printf("O QUE DESEJA FAZER?\n");
        printf(" ______________________________________________________________________________\n");
        printf(" | CRIAR NODE(1) |  EXIBIR ELEMENTOS(2) | ENCONTRAR ELEMENTO(3) | REMOVER NODE(4) |\n");
        printf(" ______________________________________________________________________________\n");
        scanf(" %d", &opcao);

        switch (opcao)
        {
            case 1:
                printf("DIGITE O ELEMENTO:");
                scanf(" %d", &elemento);
                novoNode = criarNovoNode(ultimoNode, elemento);
                ultimoNode = novoNode;
                printf("\nNODE CRIADO\n______________________________________\n\n");
                
                break;
            case 2:
                percorrerLista(HEAD);
                printf("\n______________________________________\n\n");
                break;
            case 3:

                printf("Qual elemento deseja encontrar?");
                scanf("%d", &elementoParaEncontrar);
                nodeEncontrado = encontrarElemento(HEAD, elementoParaEncontrar);
                if(nodeEncontrado == NULL){
                    printf("Elemento não encontrado!\n"); break;
                }
                printf("Elemento encontrado! Ele está na posição [%d] da lista\n", nodeEncontrado->posicao);
                printf("\n______________________________________\n\n");
                break;
                
            case 4:

            break;
        }

        printf("DESEJA FAZER MAIS ALGUMA OPERAÇÃO?");
        scanf(" %d", &flag);
        
    }
    destruirLista(HEAD);
    return 0;
}