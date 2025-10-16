// Descrição: Ordena um vetor de inteiros em ordem crescente usando o algoritmo de Ordenação por seleção

void selectionSort(int vetor[], int tamanho){
    // Laço externo: percorre as posições que precisam ser preenchidas,
    // uma de cada vez, da esquerda para a direita.
    for (int i=0; i < tamanho - 1; i++){
        //Assume que o menor, por enquanto, é o elemento na posição 'i'.
        int indiceMenor = i;

        // Laço interno: busca pelo menor elemento no resto do vetor (à direita de 'i').
        for (int j = i + 1; j < tamanho; j++){
            // Se encontrar um elemento ainda menor...
            if (vetor[j] < vetor[indiceMenor]){
                // ... atualiza o nosso índice do menor.
                indiceMenor = j;
            }
        }

        // Após o laço interno, 'indiceMenor' contém a posição do menor elemento.
        // Se o menor não for o próprio elemento da posição 'i' (uma pequena otimização),
        // realiza a troca.
        if (indiceMenor != i ){
            trocar(&vetor[i], &vetor[indiceMenor]);
        }
    }
}

// Função auxiliar para inverter as posições entre dois elementos: o valor de 'a' passa para a posição de 'b' e vice-versa;
void trocar(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}