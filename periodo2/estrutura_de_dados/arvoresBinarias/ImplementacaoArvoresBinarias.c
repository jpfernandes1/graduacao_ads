// A seguir como Criar, Percorrer e Liberar uma árvore binária, com strings em cada nó:
    // - Consolidando conceitos de pontiros, alocação dinâmica, recursividade e manipulação de memória

//---------------------------------- Estrutura básica (Nós) ------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char valor[50];
    struct No* esquerda;
    struct No* direita;
} No;

// Criação de nós (alocação dinâmica)

// Função que cria e inicializa um novo nó de árvore binária, armazenando o valor recebido
 No* criarNo(const char* valor){
    //Aloca dinamicamente memória para um novo nó e guarda o endereço em 'novo'
    No* novo = (No*) malloc(sizeof(No));

    // Copia o valor passado como parâmetro (string) para o campo 'valor' do nó
    strcpy(novo->valor, valor);
    
    // Inicializa os ponteiros dos filhos como NULL (sem filhos ainda)
        novo->esquerda = NULL;
        novo->direita = NULL;

    // Retorna o endereço do novo nó criado
    return novo;
};

// Função que libera toda a memória alocada para uma árvores binária de forma recursiva
void liberar(No* raiz){
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

/* 
    Função que insere um novo valor na árvore de forma recursiva.
    Aqui, usamos ordem alfabética para organizar os nós.
    - Se valor < nó atual -> vai para a subárvore esquerda
    - Se valor >= nó atual -> vai para a subárvore direita
*/
No* inserirPorOrdem(No* raiz, const char* valor){
    if(raiz == NULL){
        // Se a árvore (ou subárvore) está vazia, cria u novo nó
        return criarNo(valor);
    }

    if(strcmp(valor, raiz->valor) < 0){
        //Insere na subárvore esquerda
        raiz->esquerda = inserirPorOrdem(raiz->esquerda, valor);
    } else {
        //Insere na subárvore direita
        raiz->direita = inserirPorOrdem(raiz->direita, valor);
    }
    return raiz;
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

    printf("=== DEMONSTRACAO DE DUAS ABORDAGENS ===\n\n");

    // ABORDAGEM 1: CONSTRUÇÃO MANUAL (ESTRUTURA FIXA)
    printf("1. ARVORE COM CONSTRUCAO MANUAL:\n");
    printf("   (Estrutura predeterminada como exemplo da casa)\n");

    // Cria o nó raiz da árvore, representando o "Hall de entrada"
    No* arvoreManual = criarNo("Hall de entrada");

    // Construção manual dos relacionamentos feitos diretamente pelos ponteiros:
    //Liga "Sala de Estar" como filho à esquerda da raiz
    arvoreManual->esquerda = criarNo("Sala de Estar");

    //Liga o nó "Biblioteca" como filho à direita da raiz
    arvoreManual->direita = criarNo("Biblioteca");

    // "Quarto" como filho à esquerda de "Sala de Estar"
    arvoreManual->esquerda->esquerda = criarNo("Quarto");

    // "Cozinha" como filho à direita de "Sala de Estar"
    arvoreManual->esquerda->direita = criarNo("Cozinha");

    // Exibe os elementos da árvore em pré-ordem (raiz, esq., dir.)
    printf("Pre-ordem: "); 
    preOrdem(arvoreManual); 
    printf("\n");

    // Exibe os elementos da árvore em ordem (esq., raiz, dir.)
    printf("Ordem: "); 
    emOrdem(arvoreManual); 
    printf("\n");

    // Exibe os elementos da árvore em pos-ordem (esq., dir., raiz)
    printf("Pos-ordem: "); 
    posOrdem(arvoreManual); 
    printf("\n");


     // ABORDAGEM 2: INSERÇÃO POR ORDEM ALFABÉTICA (ÁRVORE BINÁRIA DE BUSCA)
    printf("2. ARVORE BINARIA DE BUSCA (por ordem alfabetica):\n");
    printf("   (Elementos inseridos na ordem: Hall, Sala, Biblioteca, Quarto, Cozinha)\n");
    
    No* arvoreBusca = NULL;
    // Inserção automática por ordem alfabética
    arvoreBusca = inserirPorOrdem(arvoreBusca, "Hall de entrada");
    arvoreBusca = inserirPorOrdem(arvoreBusca, "Sala de Estar");
    arvoreBusca = inserirPorOrdem(arvoreBusca, "Biblioteca");
    arvoreBusca = inserirPorOrdem(arvoreBusca, "Quarto");
    arvoreBusca = inserirPorOrdem(arvoreBusca, "Cozinha");
    
    printf("   Pre-ordem:  "); preOrdem(arvoreBusca); printf("\n");
    printf("   Em ordem:   "); emOrdem(arvoreBusca); printf("\n");
    printf("   Pos-ordem:  "); posOrdem(arvoreBusca); printf("\n\n");
    
    // EXPLICAÇÃO DAS DIFERENÇAS
    printf("=== DIFERENCAS ENTRE AS ABORDAGENS ===\n");
    printf("- CONSTRUCAO MANUAL: Voce controla exatamente a estrutura da arvore\n");
    printf("- ARVORE DE BUSCA:   A estrutura e determinada pela ordem alfabetica\n");
    printf("                     (menores a esquerda, maiores a direita)\n\n");
    
    printf("Note que na arvore de busca, 'Em ordem' sempre mostra os elementos ordenados!\n");
    
    // Libera toda a memória alocada para as árvores
    liberar(arvoreManual);
    liberar(arvoreBusca);

    // Indica que o programa terminou com sucesso
    return 0;
}