// Descrição: Ordena um vetor de inteiros em ordem crescente usando o algoritmo Bubble sort
// Ponto Forte: simplicidade
// Ponto Fraco: muito lento para listas grandes.

void bubbleSort(int vetor[], int tamanho){
    // Laço externo: controla o número de passadas pelo vetor.
    // A cada passada 'i', o i-ésimo maior elemento "borbulha para o lugar certo".
    for (int i=0; i < tamanho - 1; i++){

        // Laço interno: percorre o vetor comparando pares de vizinhos.
        // O limite (tamanho -1 -i) é uma otimização: ele diminui a cada iteração,
        // pois assim ele irá ignorar os últimos elementos que já foram ordenados.
        for (int j=0; j < tamanho -1 - i; j++){

            // A condição de comparação: se o elemento da esquerda for maior que o da direita...
            if (vetor[j] > vetor[j + 1]){

                // ...Troca. Passamos os endereços dos elementos para a função 'trocar';
                trocar(&vetor[j], &vetor[j + 1]);
            }
            
        }
    }
}

// Função auxiliar para inverter as posições entre dois elementos: o valor de 'a' passa para a posição de 'b' e vice-versa;
void trocar(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


int main(){

    int a[] = {8, 5, 2, 1, 0};

    bubbleSort(a, 5);

    for (int i=0; i < 5; i++){
        printf("%d ", a[i]);
    }
}