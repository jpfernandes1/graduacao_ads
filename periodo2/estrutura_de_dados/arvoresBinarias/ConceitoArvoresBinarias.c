/*

Uma árvore binária balanceada é aquela cuja altura é mantida próxima do mínimo possível, o que proporciona bom desempenho mesmo para grandes volumes de dados. 
Em contrapartida, uma árvore desbalanceada pode se degenerar em uma lista encadeada, resultando em complexidades lineares para busca e inserção, que deveriam ser logarítmicas.

Uma árvore é uma estrutura de dados hierárquica composta por elementos chamados de nós. Cada nó pode conter um valor e ter uma ligação com outros, denominados filhos. 
Se um nó contiver um ou mais filhos, ele se torna um nó pai. A árvore binária, por sua vez, é um tipo especial, pois cada nó pai pode ter no máximo dois filhos: 
o filho à esquerda e o filho à direita.

O primeiro nó de uma árvore é chamado de raiz. A partir dele, a estrutura se ramifica, ressaltando que só pode haver uma raiz em cada árvore binária. 
Os nós que não possuem filhos são chamados de folhas. Cada ligação entre nós é chamada de aresta, e os caminhos formados por essas conexões ajudam a determinar 
características importantes da árvore, como a sua altura e a profundidade de seus nós.

Tipos de árvores binárias:
    - Árvore binária completa - todos os níveis estão preenchidos, com exceção talvez do último, que deve estar mais à esquerda possível.
    - Árvore estritamente binária - é caracterizada por nós que possuem apenas dois filhos ou nenhum, o que significa que não há nós com apenas um filho.
    - Árvore binária cheia - todos os nós internos têm dois filhos, e todas as folhas estão no mesmo nível.
    - Árvore binária de busca (BST – binary search tree) - organiza seus elementos obedecendo a uma regra de ordenação: todos os valores à esquerda de um nó são menores que o valor do próprio nó, e todos os valores à direita são maiores. Essa organização permite realizar operações como busca, inserção e remoção com eficiência média de tempo logarítmica, desde que a árvore esteja balanceada.
    - Subárvore - Cada nó de uma árvore, junto a seus descendentes, forma uma nova árvore, chamada de subárvore. Em implementações recursivas, operar sobre subárvores é a base de algoritmos eficientes.

*/


/* 

        ESTRUTURA DE UM NÓ

Essa estrutura define um nó que armazena uma string e dois ponteiros para os filhos esquerdo e direito. Cada instância de struct No é um elemento da árvore. 
Lembre-se: essa é a base para todas as operações com árvores binárias.

Porque isso importa?

A estrutura correta do nó viabiliza a construção de árvores de qualquer forma, 
conectando nós filhos de maneira livre e permitindo chamadas recursivas para percorrer ou modificar a árvore.

*/
struct No {
    char valor[50];
    struct No* esquerda;
    struct No* direita;
};

/*

            ALTURA DA ÁRVORE

É o maior número de arestas entre a raiz e uma folha. Em termos práticos, ela define a profundidade máxima da estrutura, 
e está relacionada ao desempenho de operações como busca.

*/

int altura(struct No* raiz) {

    //Se o nó for NULL, a altura é 0, significando que a árvore está vazia ou que chegamos ao fim da árvore.
    if (raiz == NULL) 
        return 0;

    //Calculamos a altura da subárvore esquerda e direita com chamada recursiva.
    int alt_esq = altura(raiz->esquerda);
    int alt_dir = altura(raiz->direita);

    //Comparamos alt_esq e alt_dir, que são as alturas das subárvores esquerda e direita.
    //Usamos o operador ternário (condição ? valor_se_verdadeiro : valor_se_falso) para escolher a maior altura entre as duas.
    //Somamos 1 ao resultado, representando o nível atual da árvore (ou seja, o próprio nó).
    //Retornamos a altura da árvore, que é 1 + a maior altura entre as subárvores.
    return 1 + (alt_esq > alt_dir ? alt_esq : alt_dir);
}

/*

            IMPORTANTE 

Identificar a altura de uma árvore é importante, pois afeta o tempo de execução das operações. 
Assim, uma árvore mais alta pode indicar desbalanceamento, tornando buscas e acessos mais lentos.

*/

// -------------------------------------------------------------------------------------------------------------------------

/*

            PROFUNDIDADE

É a distância entre a raiz e um determinado nó. É útil para localizar elementos ou medir o custo de acesso. 

*/


int profundidade(struct No* raiz, struct No* alvo, int nivel) {

    //Se a raiz for NULL, significa que atingimos o fim da árvore sem encontrar o nó alvo, 
    // então retornamos –1 para indicar que o nó não está presente.
    if (raiz == NULL) 
        return -1;

    // Se o nó atual (raiz) for o nó alvo, retornamos nivel, que representa sua profundidade na árvore.
    if (raiz == alvo) 
        return nivel;

    //Chamamos recursivamente a função para a subárvore esquerda, e “nivel +1” aumenta a profundidade à medida que descemos na árvore.
    int esq = profundidade(raiz->esquerda, alvo, nivel + 1);

    //Se encontrarmos o nó alvo na subárvore esquerda, retornamos essa profundidade.
    if (esq != -1) 
        return esq;

    //Se não encontrarmos na esquerda, chamamos recursivamente para a direita, mantendo a lógica.
    return profundidade(raiz->direita, alvo, nivel + 1);
}