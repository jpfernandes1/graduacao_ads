// A seguir como Criar, Percorrer e Liberar uma árvore binária, com strings em cada nó:
    // - Consolidando conceitos de pontiros, alocação dinâmica, recursividade e manipulação de memória

//---------------------------------- Estrutura básica (Nós) ------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

struct No {
    char valor[50];
    struct No* esquerda;
    struct No* direita;
};

// Criação de nós (alocação dinâmica)

// Função que cria e inicializa um novo nó de árvore binária, armazenando o valor recebido
struct No* criarNo(char* valor){
    //Aloca dinamicamente memória para um novo nó e guarda o endereço em 'novo'
    struct No* novo = (struct No*) malloc(sizeof(struct No));

    // Copia o valor passado como parâmetro (string) para o campo 'valor' do nó
    strcpy(novo->valor, valor);
    
    // Inicializa os ponteiros dos filhos como NULL (sem filhos ainda)
        novo->esquerda = NULL;
        novo->direita = NULL;

    // Retorna o endereço do novo nó criado
    return novo;
};

// Função que libera toda a memória alocada para uma árvores binária de forma recursiva
void liberar(struct No* raiz){
    // Se o nó atual existe
    if(raiz != NULL){
        // Libera primeiro a subárvore esquerda
        liberar(raiz->esquerda);

        // Depois libera a subárvore direita
        liberar(raiz->direita);

        // Por último, libera o próprio nó atual (esse passo por último para não perdermos a referência)
        free(raiz);
    }
}

// ---------------------------------------- Métodos para percorrer ------------------------------------------

void preOrdem(struct No* raiz) {
    if (raiz != NULL) {
        // Imprime o valor do próprio nó primeiro
        printf("%s ", raiz->valor);
        // Percorre recursivamente o filho à esquerda
        preOrdem(raiz->esquerda);
        // Precorre recustivamente o filho à direita
        preOrdem(raiz->direita);
    }
}
 
void emOrdem(struct No* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esquerda);
        printf("%s ", raiz->valor);
        emOrdem(raiz->direita);
    }
}
 
void posOrdem(struct No* raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esquerda);
        posOrdem(raiz->direita);
        printf("%s ", raiz->valor);
    }
}

int main(){

    // Cria o nó raiz da árvore, representando o "Hall de entrada"
    struct No* raiz = criarNo("Hall de entrada");

    //Liga "Sala de Estar" como filho à esquerda da raiz
    raiz->esquerda = criarNo("Sala de Estar");

    //Liga o nó "Biblioteca" como filho à direita da raiz
    raiz->direita = criarNo("Biblioteca");

    // "Quarto" como filho à esquerda de "Sala de Estar"
    raiz->esquerda->esquerda = criarNo("Quarto");

    // Exibe os elementos da árvore em pré-ordem (raiz, esq., dir.)
    printf("Pre-ordem: "); 
    preOrdem(raiz); 
    printf("\n");

    // Exibe os elementos da árvore em ordem (esq., raiz, dir.)
    printf("Ordem: "); 
    emOrdem(raiz); 
    printf("\n");

    // Exibe os elementos da árvore em pos-ordem (esq., dir., raiz)
    printf("Pos-ordem: "); 
    posOrdem(raiz); 
    printf("\n");

    // Libera toda a memória alocada para a árvore
    liberar(raiz);

    // Indica que o programa terminou com sucesso
    return 0;
}