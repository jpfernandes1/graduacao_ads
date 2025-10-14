#include <stdlib.h>
#include <stdio.h>
/* Descrição: Procura por um valor em um array lista de tamanho conhecido.
    Retorno:
        O índice (posição) da primeira ocorrência do valor, se encontrado.
        -1 se o valor não estiver na lista.
*/
int buscaLinearVetor(int lista[], int tamanho, int valor){
    //Começamos um loop do início (índice 0) até o fim da lsita
    for (int i = 0; i < tamanho -1; i++){
        // Em cada passo, comparamos o elemento atual com o valor que buscamos
        if (lista[i] == valor){
            // Se o valor for encontrado, retorna a posição (indice) atual do loop;
            return i;
        }
    }

    // Se o loop encerrar e não encontrar o valor, retorna -1
    return -1;
}

/* 
    Descrição: procura por um 'valor' em uma lista encadeada
    Retorno:
        O índice (posição) da primeira ocorrência do valor, se encontrado.
        -1 se o valor não estiver na lista.

*/

   struct No {
    int dado;
    struct No* proximo;
    };

int buscaLinearListaEncadeada(struct No* inicio, int valor){
    int pos = 0; // Um contados para sabermos a posição (indice)
    struct No* atual = inicio; // O ponteiro "viajante"

    // Enquanto o fim não for atingido:
    while (atual != NULL) {
        // Verifica se o dado do nó atual é o valor procurado
        if (atual->dado == valor){
            //Se encontrar, retorna a posição atual:
            return pos;
        }

        // Se não for, continua a iteração;
        atual = atual->proximo;

        // e incrementa o contador de posição:
        pos++;
    }

    //Se o while acabar, sifnifica que o valor não foi encontrado na lista;
    return -1;
}

int main() {
    struct No n3 = {30, NULL};
    struct No n2 = {20, &n3};
    struct No n1 = {10, &n2};

    int pos = buscaLinearListaEncadeada(&n1, 20);
    printf("Posicao encontrada: %d\n", pos);

    return 0;
}
