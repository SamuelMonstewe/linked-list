#include <stdio.h>
#include <stdlib.h>

typedef struct Lista
{
    int elemento;
    __uint8_t posicao;
    struct Lista *ptrProximoElemento;
}   Lista;


Lista *criarNovoElemento(Lista *ultimoNodeAtual, int elemento){
    
    ultimoNodeAtual->ptrProximoElemento = (Lista *)malloc(sizeof(Lista));
    ultimoNodeAtual->ptrProximoElemento->elemento = elemento;
    ultimoNodeAtual->ptrProximoElemento->posicao = ultimoNodeAtual->posicao++;
    ultimoNodeAtual->ptrProximoElemento->ptrProximoElemento = NULL;    

    return ultimoNodeAtual->ptrProximoElemento;
}

void percorrerLista(Lista *primeiroNode){

      if(primeiroNode->ptrProximoElemento == NULL){
        printf("A lista está vazia!");
        return;
    }

    Lista *ptr = primeiroNode->ptrProximoElemento;

    printf("Elementos na lista:");
    while(ptr != NULL){
        printf("| %d | ", ptr->elemento);
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

Lista *encontrarElemento(Lista *lista, int elementoProcurado){

    Lista *nodeEncontrado;

    while(lista->ptrProximoElemento != NULL){
        if(lista->elemento == elementoProcurado){
            return lista;   
        }
    }
    return NULL;
}
void preencherLista(Lista *header, __uint8_t quantidadeDesejada){
   
    int numero = 0;
    Lista *novoNode;
    Lista *ultimoNode = header;

    for(__uint8_t i = 0; i < quantidadeDesejada; i++){
        printf("Digite um numero:");
        scanf(" %d", &numero);
        novoNode = criarNovoElemento(ultimoNode, numero);
        ultimoNode = novoNode;

    }
}

int main(){
    Lista *header = (Lista *)malloc(sizeof(Lista));
    header->ptrProximoElemento = NULL;
    header->elemento = 0;
    header->posicao = 0;
    int flag = -1;
    int opcao;
    int quantidadeDeElementosDesejados;

    while(flag == -1){
        printf("O QUE DESEJA FAZER?\n");
        printf(" ________________________________________________________________\n");
        printf(" | PREENCHER LISTA(1) |  EXIBIR ELEMENTOS(2) | LIMPAR LISTA(3)  |\n");
        printf(" ________________________________________________________________\n");
        scanf(" %d", &opcao);

        switch (opcao)
        {
            case 1:
                printf("QUANTOS ELEMENTOS VOCÊ QUER NA LISTA?");
                scanf(" %d", &quantidadeDeElementosDesejados);
                preencherLista(header, quantidadeDeElementosDesejados);
                printf("\nELEMENTOS CRIADOS\n______________________________________\n\n");
                break;
            case 2:
                percorrerLista(header);
                printf("\n\n______________________________________\n");
                break;
            case 3:
                limparLista(header);
                printf("\n______________________________________");
                break;
        }

        printf("DESEJA FAZER MAIS ALGUMA OPERAÇÃO?");
        scanf(" %d", &flag);
        
    }
   
    return 0;
}