/* Descrição: Procura por um valor em um vetor.
 Pré-requisitos: 
    - o vetor deve ser : 
        a) ORDENADO em ordem crescente
        b) de tamanho conhecido
 Retorno: 
        O índice do valor, se encontrado. 
        - 1 se o vetor não contém o valor procurado
 */

 int BuscaBinaria(int vetor[], int tamanho, int valor){
    int inicio = 0;
    int fim = tamanho - 1;

    // O loop continua enquanto a "fatia" de busca for válida (inicio <= fim).
    while (inicio <= fim){
        
        //A forma comum de calcular o méio é: int meio = (inicio + fim) / 2, mas essa pode dar overflow com numeros muito grandes.
        // A forma mais segura evitando overflow é:
        int meio = inicio + (fim - inicio) / 2;

        // 1. Se o valor estiver exatamente no meio, encontramos!
        if (vetor[meio] == valor){
            return meio; // retorna o indice onde o valor foi encontrado
        }

        // 2. Se o valor no meio for menor que o valor buscado, nosso alvo só pode estar na metade com numeros maiores:
        else if (vetor[meio] < valor){
            inicio = meio + 1; // descarte da metade esquerda
        }

        // 3. Se o valore no meio for maior que o valor buscado, nosso alvo esta na metade com numeros menores
        else {
            fim = meio - 1; // descarte da metade direita
        }
    }

    // Se o loop terminar, significa que 'inicio' ultrapassou 'fim' e o valor não foi encontrado.

    return -1;


 }