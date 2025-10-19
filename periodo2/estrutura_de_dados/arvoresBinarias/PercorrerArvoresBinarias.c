/*

Percurso é o processo de visitar todos os nós da árvore de forma sistemática. 
Existem diversas maneiras de realizar essa travessia, e cada uma delas serve a um propósito diferente. 
Há três abordagens clássicas de percurso: pré-ordem, em ordem e pós-ordem.


Imagine que estamos caminhando por uma árvore, e em cada nó temos três possibilidades: 
1. Pré-ordem: Neste tipo de percurso, a visita começa pelo próprio nó, seguida pelo filho esquerdo e depois pelo direito. Funciona como um reconhecimento inicial: identificamos o ponto principal antes de explorar seus arredores. É especialmente útil para clonar uma árvore ou salvar sua estrutura original, já que percorre cada elemento na ordem em que está organizado.

2. Ordem: Amplamente utilizado em árvores binárias de busca, este percurso segue a sequência: filho esquerdo, nó atual e filho direito. Essa organização resulta em uma travessia com elementos dispostos em ordem crescente, sendo ideal para buscas eficientes, listagens ordenadas e aplicações que exigem hierarquia clara entre os dados. 

3. Pós-ordem: Aqui, o nó atual é deixado por último. Primeiro visitamos o filho esquerdo, depois o direito, e, por fim, retornamos ao nó principal. Essa abordagem é indicada para desmontar a árvore com segurança, liberar memória ou avaliar expressões aritméticas compostas, já que processa os componentes antes de lidar com o ponto central.

Observe a árvore da imagem:

https://cdn-conteudo.ensineme.com.br/15_79e74ba168.jpg

Se percorrermos a árvore em pré-ordem, a sequência será A, B, D, E, C. 
Já em em ordem, teremos D, B, E, A, C. 
No caso da pós-ordem, a ordem será D, E, B, C, A.

*/

//-------------------------------------------------------------------------------------------------------------------------------

/*

    Implementação de percursos

Cada um dos percursos vistos pode ser implementado de forma recursiva em C. 
A função preOrdem, por exemplo, começa imprimindo o valor do nó atual, depois chama a si mesma para o filho esquerda e, em seguida, para o direito. 
A emOrdem faz o mesmo, mas imprime o valor entre as duas chamadas recursivas. 
Já a posOrdem só imprime o valor do nó depois de visitar ambos os filhos:
*/

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