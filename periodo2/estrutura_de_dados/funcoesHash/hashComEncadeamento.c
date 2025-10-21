/*

    Tabela hash com encadeamento (chaining)

Quando lidamos com grandes volumes de dados e queremos fazer buscas rápidas, as tabelas hash surgem como uma das estruturas mais eficientes.
Elas permitem que uma chave — como um nome ou número — seja convertida em um índice de um vetor e usada para localizar um valor com tempo médio de acesso constante (O(1)).

No entanto, essa eficiência depende do bom tratamento de um problema inevitável: as colisões.

    O que são colisões?

Quando duas ou mais chaves diferentes são transformadas, pela função hash, no mesmo índice da tabela ocorre uma colisão. 
Como o vetor só pode armazenar um elemento por posição, precisamos de uma maneira de armazenar múltiplos dados na mesma posição.

    Encadeamento

A tabela hash é um vetor de ponteiro, onde cada posição aponta para o início de uma lista ligada (cadeia). 
Assim, quando várias chaves forem direcionadas ao mesmo índice, elas são adicionadas como nós dessa lista.
Assim como uma caixa de correio com várias cartas dentro, a "caixa" é a posição do vetor, e cada "carta" é um nó da lista com uma chave.
Essa solução é flexível, simples de implementar e eficiente na prática.


------------------------- EXEMPLO ---------------------------

- Vamos supor que 

TAMANHO_TABELA = 5
Função hash: soma dos valores ASCII das letras e resto da divisão por 5.

VAmos inserir os nomes: "Ana", "Bruno", "Carlos", "Amanda".

"Ana":

'A' (65) + 'n' (110) + 'a' (97) = 272
272 % 5 = 2

"Bruno":

'B' (66) + 'r' (114) + 'u' (117) + 'n' (110) + 'o' (111) = 518
518 % 5 = 3

"Carlos":

'C' (67) + 'a' (97) + 'r' (114) + 'l' (108) + 'o' (111) + 's' (115) = 612
612 % 5 = 2 (colide com "Ana")

"Amanda":

'A' (65) + 'm' (109) + 'a' (97) + 'n' (110) + 'd' (100) + 'a' (97) = 578
578 % 5 = 3 (colide com "Bruno")

    Cada posição é uma lista ligada (encadeamento)

- Cada índice da tabela pode conter vários nomes encadeados, se houver colisão.
- Ao buscar, percorremos a lista ligada daquele índice até encontrar (ou não) o nome.
- Ao remover, ajustamos a lista para tirar o nó desejado.

Índice	Lista Ligada
  0	    (vazio)
  1	    (vazio)
  2	    "Carlos" → "Ana" → NULL
  3	    "Amanda" → "Bruno" → NULL
  4	    (vazio)

*/


// ---------------------- IMPLEMENTAÇÃO -------------------------

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_TABELA 10

// estrutura do nó
typedef struct Nodo{
    char nome[50];
    struct Nodo* proximo; // ponteiro para o próximo nó
} Nodo;

Nodo* tabela_hash[TAMANHO_TABELA]; // vetor de ponteiros

// Função hash: Converte string em índice (exemplo: soma dos valores ASCII e módulo pelo tamanho da tabela)

int funcaoHash( const char* chave){
    int soma = 0;
    for (int i = 0; chave[i] != '\0'; i++){
        soma += chave[i];
    }
    return soma % TAMANHO_TABELA;   
}

/* Inserção: cria um nó e o insere ao início da lista ligada correspondente à posição gerada pela função hash

Não estamos sobrescrevendo o valor já presente no índice, mas, sim, encadeando os dados.
Inserir no início da lista é rápido (afinal, não é necessário percorrer a lista toda).
É possível que nomes diferentes com o mesmo índice sejam organizados como uma pequena fila, como consequência.

*/
void inserir(const char* nome){
    int indice = funcaoHash(nome); // Descobre onde armazenar
    // Cria um nó
    Nodo* novo = (Nodo*)malloc(sizeof(Nodo));
    strcpy(novo->nome, nome);
    // Insere no início da lista (head)
    novo->proximo = tabela_hash[indice];
    tabela_hash[indice] = novo;
}

/* Busca: A procura percorre a lista da posição indicada pela função hash e compara nome por nome até encontrar o desejado.

    Explicando:

Usamos strcmp para comparar strings.
Se o nome for encontrado, retornamos um ponteiro para o nó.
Se não, retornamos NULL, indicando que o nome não foi cadastrado.

*/

Nodo* buscar(const char* nome){
    int indice = funcaoHash(nome);
    Nodo* atual = tabela_hash[indice];
    while (atual != NULL){
        if (strcmp(atual->nome, nome) == 0){
            return atual; // Encontrou
        }
        atual = atual->proximo;
    }
    return NULL; // Não está na lista
}

/* Remoção: Excluir um item de uma lista ligada exige um pouco mais de cuidado. 
Assim, precisamos manter a referência do elemento anterior para reencadear a lista após a remoção.

Explicando passo a passo:

A função procura o nome desejado. 
Se for o primeiro da lista, apenas o ponteiro da tabela é atualizado.
Se estiver no meio ou final, o nome anterior aponta para o próximo do nome atual. 
A memória com free é liberada.

*/
void remover(const char* nome){
    int indice = funcaoHash(nome);
    Nodo* atual = tabela_hash[indice];
    Nodo* anterior = NULL;

    while(atual != NULL){
        if (strcmp(atual->nome, nome) == 0){
            if (anterior == NULL){
                tabela_hash[indice] = atual->proximo; // Era o primeiro
            } else {
                anterior->proximo = atual->proximo; // "Pula" o nó atual
            }
            free(atual);
            printf("'%s' removido. \n", nome);
            return;
        }
        anterior = atual;
        atual = atual->proximo;                
    }
    printf("'%s' não encontrado.\n", nome);
}

// -----------------------------------------------------------------------------------

int main() {
    inserir("Ana");
    inserir("Bruno");
    inserir("Carlos");
    inserir("Amanda"); // Pode colidir com "Ana"
 
    printf("Buscando 'Bruno': %s\n", buscar("Bruno") ? "Encontrado" : "Não encontrado");
    printf("Buscando 'João': %s\n", buscar("João") ? "Encontrado" : "Não encontrado");
 
    remover("Carlos");
    remover("João");
 
    return 0;
}

/*

O que acontece aqui:

"Ana" e "Amanda" podem acabar no mesmo índice — e o encadeamento resolve isso.

"Carlos" será removido com sucesso.
 
Ao tentar remover "João", a função nos informa que ele não foi encontrado.
 
A tabela hash com encadeamento é uma estrutura robusta para situações em que precisamos armazenar dados associados a uma chave, com acesso e manipulação rápidos. Sua implementação com listas ligadas torna o sistema flexível e resistente a colisões, que são comuns em qualquer função hash.

Tal modelo é usado em cadastros, dicionários, catálogos, banco de dados e sistemas de login, entre muitos outros contextos reais. Ao entender sua lógica, você amplia sua capacidade de desenvolver sistemas eficientes e escaláveis.

*/