// Introdução a Pilhas

/* 
    Estrutura do tipo LIFO (Last In, First Out)

    Utilizado preferencialmente para informações que precisam ser lidas na ordem inversa de alocação. ex:
    - Navegação em paginas web;
    - Ordem de edição (ação desfazer)
    - Chamada de funções recursivas;

São fundamentais para:

    * Manipulação de estados;
    * Execução reversa;
    * Controle de chamadas
    
    
    Pilhas são importantes devido ao fato de serem constantemente utilizadas em algoritmos de:


* Parsing- Os algoritmos de parsing analisa e estrutura dados de entrada, verificando sua sintaxe e convertendo os dados para um formato compreensível. 
O parsing usa uma pilha para organizar tokens em ordem hierárquica, auxiliando na análise sintática de expressões e linguagens.

* Resolução de expressões matemáticas- A pilha é fundamental, pois garante a ordem correta dos cálculos. 
Esse método é utilizado em calculadoras e interpretadores de linguagem.

* Backtracking - A pilha é usada para armazenar estados anteriores, possibilitando retornar e tentar alternativas em problemas recursivos. 
Assim, backtracking é muito utilizado em softwares para que o usuário desfaça ações em sequência.

Os sistemas operacionais utilizam pilhas para o gerenciamento de chamadas de função e armazenamento de variáveis locais. 
Ao entender como a pilha funciona internamente, podemos otimizar o uso da memória e prever comportamentos críticos, como estouro de pilha (stack overflow). */


// ------------------------   CRIAÇÃO DAS ESTRUTURAS  -------------------------------

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    char nome[50];
    int idade;
} Elemento;


typedef struct {
    Elemento itens[MAX];
    int topo;

} Pilha; 

/*

As principais funções que compõem as pilhas são:
 * Inserir (push)
 * Remover (pop)
 * Consultar o topo (peek)
 * Liberar (free)
 
*/

// --------------------------------- Inserir (Push) ---------------------------------------

void push(Pilha *p, Elemento e){
    if(pilhaCheia(p)){
        printf("Erro: pilha cheia. Não é possível inserir. \n");
        return;
    }

    p->topo++; // avança o indice do topo, criando o espaço para adicionar o novo elemento
    p->itens[p->topo] = e; // Insere o elemento no topo;
}


// ---------------------------------- Remover (pop) ---------------------------------------
void pop(Pilha *p, Elemento *e){
    if (pilhaVazia(p)){
        printf("Impossível remover, a pilha está vazia!");
        return;
    }

    *e = p->itens[p->topo]; // Copia o valor do topo (não é obrigatório, mas interessante para saber o elemento que foi removido)
    p->topo--; // Decrementa o topo;
    
}

// ---------------------------------- Consultar (Peek) ---------------------------------------
// Quase idêntico ao pop, retirando apenas a linha que decrementa o topo;
void peek(Pilha *p, Elemento *e){
    if (pilhaVazia(p)){
        printf("A pilha está vazia!");
        return;
    }

    *e = p->itens[p->topo]; // Copia o valor do topo sem alterar a pilha
    
}

// ---------------------------------- Liberar (free) ---------------------------------------
// Libera/esvazia a pilha da memória

// No caso de uma pilha de tamanho fixo, é importante ter em mente que os elementos não são removidos do vetor de modo físico,
// mas a pilha perde a referência de onde o topo estava.
void liberarPilha(Pilha *p){
    p->topo = -1; // Define a pilha como vazia novamente
}


/*
Resumindo
A função free() só é necessária em pilhas implementadas com alocação dinâmica, em que cada elemento é criado com malloc. Nessas pilhas, é preciso liberar manualmente cada nó para evitar vazamentos de memória. Já nas pilhas com tamanho fixo (usando arrays), não se usa free, pois a memória é gerenciada de maneira automática. Para "limpar" a pilha estática, basta redefinir o topo para -1. Isso torna os elementos antigos inacessíveis pela lógica da pilha.
*/

// ----------------------------------- Métodos Auxiliares ---------------------------------------

void inicializarPilha(Pilha *p){
    p->topo = -1;
}

int pilhaVazia(Pilha *p){
    return p->topo == -1;
}

int pilhaCheia(Pilha *p){
    return p->topo == MAX - 1;
}

void mostrarPilha(Pilha *p){
    printf("Pilha (topo -> base): \n");
    for (int i = p->topo; i >= 0 ; i--){

        printf("[%s, %d]\n", p->itens[i].nome, p->itens[i].idade);
    }
    printf("\n");
    
}

// obs.: em pilhaCheia, utiliza-se MAX - 1 porque quando se chama o topo, ele aponta para o índice.
// E o índice é sempre tamanho da pilha - 1 (pois o indice inicia em zero)


// ------------------------  IMPLEMENTAÇÃO -------------------------------

int main(){
    Pilha p;
    inicializarPilha(&p);

    Elemento a = {"Ana", 20};
    Elemento b = {"Joao", 30};
    Elemento c = {"Jose", 35};

    push(&p, a);
    push(&p, b);
    push(&p, c);

    mostrarPilha(&p);

    Elemento removido;

    pop(&p, &removido);
    printf("Removido: %s, %d\n", removido.nome, removido.idade);

    mostrarPilha(&p);

    Elemento topo;
    peek(&p, &topo);
    printf("Topo atual: %s, %d\n", topo.nome, topo.idade);

    return 0;

}