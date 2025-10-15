/* Descrição: Ordena um vetor de inteiros em ordem crescente usando o algoritmo de ordenação por inserção

 Pontos Fortes: muito bom para listas pequenas ou parcialmente ordenadas (o bubble sort precisaria fazer todas as iterações)

*/
void insertionSort(int vetor[], int tamanho){
    // Começamos do segundo elemento (índice 1), pois o primeiro já está "ordenado".
    for (int i = 1; i < tamanho; i++){
        // 1. Pegamos a "carta da vez" e guardamos na nossa 'chave'.
        int valorAtual = vetor[i];
        int j = i - 1;

        // 2. Agora, olhamos para a "mão" (a parte ordenada à esquerda).
        // Enquanto houver elementos para trás, ou seja, enquanto não atingir o inicio do array (j >= 0) 
        // e o elemento no index anterior for maior que a nossa chave...
        while (j >= 0 && vetor[j] > valorAtual){
            // ... empurramos o elemento da mão uma posição para a direita.
            vetor[j+1] = vetor[j];
            j--; // E olhamos para a proxima "carta" na mão, para trás.
        }

        // 3. O loop 'while' parou. Encontramos o lugar certo!
        // Inserimos a nossa chave no espaço que foi aberto.
        // Aqui o j está valendo 1 a menos devido o j-- do bloco while, então quando colocamos j + 1, o indice
        // encontrado era o j de antes do while.
        vetor[j + 1] = valorAtual;
    }
}

int main(){

    int vetor[] = {4, 3, 2, 1, 0};

    insertionSort(vetor, 5);

    for (int i = 0; i < 5; i++){
        printf("%d", vetor[i]);
    }
    
}