/* Filas são estruturas do tipo FIFO (Fist In, First Out)

    Suas principais funções são:
       - Inserir
       - Retirar
       - Verificar

*/

// ------------------------------- DECLARAÇÃO DAS ESTRUTURAS DA FILA ------------------------------------- 

#include <stdio.h>
#include <stdlib.h>

// O elemento a ser inserido na fila
typedef struct {
    char nome[30];
    int tamanho;
} Elemento;

// A fila em si

#define MAX 5

typedef struct {
    Elemento itens[MAX];
    int inicio;
    int fim;
    int total;
} Fila;

// Ponteiros da fila : necessários para que exista a referência de cada marcador

void inicializarFila(Fila *f){
    f->inicio = 0;
    f->fim = 0; // A fila é inicializada vazia;
    f->total = 0;
}

int filaCheia(Fila *f){
    return f->total==MAX;
}

int filaVazia(Fila *f){
    return f->total == 0;
}



// --------------------------------INSERIR (Queue) - é colocar um elemento no fim da fila: --------------------------------

void inserir (Fila *f, Elemento e){
    if (filaCheia(f)){ // Impede inserção em fila cheia
        printf("Fila cheia. Não é possível inserir");
        return;
    } 

    f->itens[f->fim] = e; // Insere o elemento novo 'e' no ponteiro que aponta para o fim da fila
    f->fim = (f->fim + 1) % MAX; // Logica Circular: acresce em 1 o índice do fim da fila;
    f->total++; // Incrementa  o contador de elementos do vetor;
}


/*  *Quando usamos um array como base de uma fila, surgem limitações naturais. Por exemplo, ao realizar múltiplas inserções e remoções, o índice fim pode alcançar o final do array, 
mesmo que ainda existam posições no início liberadas por operações de remoção (dequeue). Para resolver isso, aplicamos a lógica circular (array circular), ou seja, o array é tratado 
como se estivesse conectado em seus extremos. Assim, ao ultrapassarmos o último índice, 
voltamos ao início do array. 

É nesse momento que utilizamos o operador módulo %:

f−>fim=(f−>fim+1)% MAX;

Com esse cálculo, se somarmos 1 ao índice fim (atualizar o final da fila), ele retornará a 0 quando ultrapassar o tamanho máximo (MAX), reiniciando o ciclo do array.

Por que isso é importante?

Para que filas implementadas com arrays fixos não desperdicem memória! Sem o uso cíclico, precisaríamos realocar manualmente os elementos após cada remoção para “empurrá-los” para o início, o que seria ineficiente. Portanto, o uso cíclico evita esse custo e mantém as operações com complexidade constante; veja:

Inserção (enqueue): O(1) / Remoção (dequeue): O(1)

No caso prático que estamos implementando

*/

// ---------------------- REMOVER (dequeue): eliminar o elemento mais antigo -------------------------

Elemento remover(Fila *f, Elemento *e){
    if (filaVazia(f)){ // evita executar em fila vazia;
        printf("Fila vazia. Não é possível remover");
        Elemento vazio = {"", 0};  // ou {"(vazio)", -1};
        return vazio;
    }

    *e = f->itens[f->inicio]; // armazena quem está no inicio da fila
    f->inicio = (f->inicio + 1) % MAX; // Atualiza o índice de início para o segundo mais antigo (que agora torna-se o primeiro)
    f->total--; // Diminui o total

    return *e;
}


// ------------------------- Verificar sem remover (PEEK) -----------------------------


// Em algumas situações é importante checar informações sem alterar a fila:

Elemento espiar(Fila *f){
    Elemento vazio = {"", 0}; // Valor padrão caso a fila estiver vazia

    if(filaVazia(f)){
        return vazio;  // Impede acesso indevido
    }

    return f->itens[f->inicio];
}


// ---------------------------- Mostrar fila inteira ------------------------------------

void mostrarFila(Fila *f){
    printf("Fila: ");
    for (int i = 0, idx = f->inicio; i < f->total; i++, idx = (idx + 1) % MAX)
    {
        printf("[%s, %d]",
        f->itens[idx].nome,
        f->itens[idx].tamanho);
    }
    printf("\n");
}


// ---------------------- CRIANDO A FILA E UTILIZANDO NO MAIN -------------------------------

int main(){

    Fila f;
    inicializarFila(&f); // Passando o ponteiro da fila instanciada para a função que gera a fila;

    Elemento e1 = {"Escada", 15};
    Elemento e2 = {"Poste", 16};

    inserir(&f, e1);
    inserir(&f, e2);
    mostrarFila(&f); // Mostra a fila antes da remoção
    Elemento removido; // Remover o primeiro da fila
    remover(&f, &removido); // aplicando a função de remoção;
    printf("Elemento removido: %s, %d\n", removido.nome, removido.tamanho);
    mostrarFila(&f); // mostra a fila após a remoção

    return 0;
}