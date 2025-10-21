/* Tabela Hash com endereçamento Aberto

 é um vetor com espaços numerados (índices), onde cada palavra é transformada em um número (índice)
 usando uma função hash. Ele mantém todos os dados dentro do próprio vetor da tabela, sem usar listas auxiliares.

 O que é endereçamento aberto?


Quando duas chaves produzem o mesmo índice (colisão), em vez de criar listas, a estrutura procura outra posição livre no vetor seguindo um padrão de busca (linear, quadrática, duplo hashing etc.). Usaremos aqui a sondagem linear (ou linear probing): se a posição i estiver ocupada, ela tenta i+1, depois i+2, e assim por diante, até encontrar uma posição livre.


  ---------------------------------------- Exemplo ---------------------------------------

  Em um vetor com 10 espaços (indices 0 a 9) vamos inserir quatro nomes:
   "Ana", "Bruno", "Carlos", "amanda"

   Usando a função hash simples:
    - some o valor de cada letra (ASCII)
    - Faça o resto da divisão pelo tamanho da tabela (10)


    ------- Inserir -------

"Ana":

65 (A) + 110 (n) + 97 (a) = 272
272 % 10 = 2
R = Espaço 2 está livre ⇒ coloca "Ana" em 2.

"Bruno":

66 + 114 + 117 + 110 + 111 = 518
518 % 10 = 8
R = Espaço 8 está livre ⇒ coloca "Bruno" em 8.

"Carlos":

67 + 97 + 114 + 108 + 111 + 115 = 612
612 % 10 = 2
R = Espaço 2 está ocupado, já tem "Ana" ⇒ Procura o próximo espaço: 3 está livre ⇒ Coloca "Carlos em 3"

"Amanda":

65 + 109 + 97 + 110 + 100 + 97 = 578
578 % 10 = 8
R = Espaço 8 está ocupado, já tem "Bruno" ⇒ Procura o próximo espaço: 9 está livre ⇒ Coloca "Amanda" em 9;


    ------- Buscar -------

    1. Calcula o índice: "Carlos" --> 2
    2. Olha o espaço 2: está "Ana" (não é o que buscamos)
    3. Vai para o próximo espaço (3): está "Carlos" (achou)
    Fim.

*/

// -------------------------- IMPLEMENTAÇÃO ---------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_TABELA 10
typedef struct {
    char nome[50];
    int ocupado; // 0 = vazio, 1 = ocupado, -1 = removido
} Entrada;

Entrada tabela_hash[TAMANHO_TABELA];


// Função hash

int funcao_hash(const char* chave) {
    int soma = 0;
    for (int i = 0; chave[i] != '\0'; i++) {
        soma += chave[i];
    }
    return soma % TAMANHO_TABELA;
}

/* Inserção com sondagem linear: se a posição estiver ocupada, seguimos procurando a próxima vaga. 

Explicação detalhada:

Começamos do índice gerado pela função hash. 
Se a posição estiver livre (0) ou marcada como removida (-1), inserimos um nome.
Tentamos a próxima posição (pos = (índice + i) % tamanho), caso a posição esteja ocupada.
Se percorremos toda a tabela sem sucesso, significa que ela está cheia.

*/

void inserir(const char* nome) { 
    int indice = funcao_hash(nome);
    for (int i = 0; i < TAMANHO_TABELA; i++) {
                int pos = (indice + i) % TAMANHO_TABELA;
        
                if (tabela_hash[pos].ocupado == 0 || tabela_hash[pos].ocupado == -1) {
                    strcpy(tabela_hash[pos].nome, nome);
                    tabela_hash[pos].ocupado = 1;
                    return;
            }
    }
        printf("Tabela cheia. Não foi possível inserir '%s'.\n", nome);
}

// Buscar um nome: A procura também segue o mesmo padrão de sondagem linear:

int buscar(const char* nome) { 
    int indice = funcao_hash(nome);
    
        for (int i = 0; i < TAMANHO_TABELA; i++) {
                int pos = (indice + i) % TAMANHO_TABELA;
        
                if (tabela_hash[pos].ocupado == 0) {
                    return -1; // Paramos: posição nunca foi usada
            }
    
            if (tabela_hash[pos].ocupado == 1 && strcmp(tabela_hash[pos].nome, nome) == 0) {
                    return pos;
            }
    }
    
        return -1; // Não encontrou
}

/*

    Atenção

Se encontramos uma posição vazia (0), podemos parar o dado, pois não está na tabela.
Se achamos uma posição com o nome certo, retornamos seu índice. 
Se o campo está removido (-1) ou ocupado com outro valor, continuamos procurando.

*/


/* 

Remover um nome: Para retirar, procuramos pelo nome e marcamos a posição como removida (-1)

Por que marcar como removido?

Se colocarmos como 0 (vazio), a busca futura pode terminar cedo demais, achando que o item nunca esteve ali. 
Usar -1 permite manter o ciclo de busca funcionando como o esperado. */

void remover(const char* nome) {
    int pos = buscar(nome);
    if (pos == -1) {
        printf("'%s' não encontrado.\n", nome);
        return;
    }
 
    tabela_hash[pos].ocupado = -1;
    printf("'%s' removido da tabela.\n", nome);
}


// ---------------------------- Função Main ---------------------------------

int main() {
    // Inicializa a tabela
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        tabela_hash[i].ocupado = 0;
    }
 
    inserir("Ana");
    inserir("Bruno");
    inserir("Carlos");
    inserir("Amanda"); // Pode colidir com Ana
 
    printf("Buscando 'Bruno': %s\n", buscar("Bruno") != -1 ? "Encontrado" : "Não encontrado");
    printf("Buscando 'João': %s\n", buscar("João") != -1 ? "Encontrado" : "Não encontrado");
 
    remover("Carlos");
    remover("João");
 
    return 0;
}


/*
            CONSIDERAÇÕES FINAIS

A tabela hash com endereçamento aberto é uma alternativa elegante ao encadeamento: todas as informações são mantidas dentro do próprio vetor, 
sem uso de ponteiros ou listas. Isso simplifica o gerenciamento da memória e melhora o cache do processador.


Por outro lado, essa abordagem exige controle cuidadoso de colisões e atenção especial ao estado das posições (livre, ocupado e removido).

Essa técnica é bastante usada em bancos de dados simples, compiladores, mecanismos de busca e em qualquer sistema que precise associar com
 rapidez uma chave a um valor como logins, dicionários e catálogos, entre outros.

*/