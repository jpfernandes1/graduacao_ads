/*

    Organizar dados de forma eficiente e com acesso rápido é uma necessidade recorrente em diversas áreas da computação. 
    Diante disso, há estruturas de dados que cumprem esse papel com diferentes estratégias: 
        a) Árvores binárias de busca (BST)
        b) Tries. 
        
    Embora cada uma possua regras e finalidades distintas, todas compartilham o princípio de representar dados de maneira hierárquica
    para otimizar operações como busca, inserção e exclusão. 


    Árvore binária de busca (BST)

    Provavelmente a mais clássica das árvores de busca. Cada nó seu contém um valor e até dois filhos. 
    A principal regra da BST estabelece que todos os valores menores que o de um nó ficam à  esquerda, e os maiores, à direita. 
    Essa ordenação natural permite que buscas por elementos ocorram de forma eficiente e com complexidade média de tempo O(log n), 
    mas desde que a árvore esteja balanceada. No entanto, lembre-se: a eficiência da BST depende da forma como os dados são inseridos. 
    Em casos desfavoráveis, como inserção de dados em ordem crescente, a estrutura  pode se degradar para algo próximo a uma lista encadeada, 
    perdendo sua principal vantagem.


    A comparação entre strings segue a ordem lexicográfica.
    A função strcmp() compara caractere por caractere, da esquerda para a direita, usando o valor ASCII de cada caractere.

    -Ex.:
            "Livro com página faltando" -> "L" (76 na tabela ASCII)
            "Pegadas de lama" -> "P" (80 na tabela ASCII)

            Como 76 < 80, "Livro com página faltando" é menor que "Pegadas de Lama".
            o primeiro seria alocado à esquerda e o segundo à direita (se forem filhos do mesmo nó)

*/

// ------------------------------------- IMPLEMENTAÇÃO ----------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura do nó

//Cada nó possui três componentes:
typedef struct No
{
    // valor: o dado armazenado (nesse caso, uma string). 
    char valor[50];
    // esquerda: ponteiro para o filho à esquerda.
    struct No* esquerda;
    // direita: ponteiro para o filho à direita.
    struct No* direita;
} No;


/*

Criando um nó

Sempre que quisermos adicionar um novo valor à árvore, precisaremos criar um nó com esse valor. 
Essa função aloca memória e inicializa os ponteiros como NULL, já que novos nós começam sem filhos.

*/

No* criarNo(const char* valor){
    No* novo = (No*) malloc(sizeof(No));
    strcpy(novo->valor, valor); // inserindo o valor da chamada no novo nó
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

/*

Inserindo elementos na árvore

Esse passo certifica que cada valor inserido é um novo bloco na árvore, isolado, pronto para ser conectado a outros nós e
seguindo a regra da BST: valores menores vão à esquerda, maiores à direita:

*/

No* inserir(struct No* raiz, const char* valor){
    if(raiz == NULL){
        return criarNo(valor);
    }

    if(strcmp(valor, raiz->valor) < 0){
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else if (strcmp(valor, raiz->valor) > 0) {
        raiz->direita = inserir(raiz->direita, valor);
    }

    return raiz;   
}

/*

Como árvores binárias são recursivas, ou seja, percorrem até encontrar uma posição livre para inserir o novo valor, cada chamada vai descendo um nível, a árvore cresce de cima para baixo. Toda vez que um nó for inserido, é considerada a lógica que caracteriza uma BST. Quando um nó é menor que a raiz atual, ele é alocado à esquerda dela, caso contrário, à direita.


Percorrendo a árvore em ordem (in-order)

A principal vantagem da BST é poder ser percorrida em ordem crescente com um algoritmo simples. 
Esse percurso visita primeiro a esquerda, depois o nó atual, e, por fim, a direita. 

*/

void emOrdem(struct No* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esquerda);
        printf("%s ", raiz->valor);
        emOrdem(raiz->direita);
    }
}

/*

Buscando um valor na árvore

Procurar em uma BST é muito mais eficiente do que em uma lista, pelo simples fato de que porque podemos eliminar metade dos elementos a cada comparação:

*/

int buscar(struct No* raiz, const char* chave){
    if(raiz == NULL){
        return 0;
    }
    
    if(strcmp(chave, raiz->valor) == 0){
        return 1;
    } else if (strcmp(chave, raiz->valor) < 0){
        return buscar(raiz->esquerda, chave);
    } else {
        return buscar(raiz->direita, chave);
    }
}

/* O algoritmo segue a lógica da inserção: se o valor é menor, buscamos à esquerda. Se maior, à direita. Quando encontramos, retornamos 1; caso contrário, 0.

obs.: a comparação == 0 e < 0 deve-se ao funcionamento do retorno da função strcmp:

Comparação caractere a caractere: A função compara as duas strings a partir do primeiro caractere. 
Resultado:
0: As strings são idênticas. 
Valor negativo: A primeira string é menor que a segunda na ordem alfabética (ex: "apple" < "banana"). 
Valor positivo: A primeira string é maior que a segunda na ordem alfabética. 

*/

//---------------------------------------------------------------------------------------------------------------------------------------------


/* 

                REMOÇÃO DE UM NÓ

 É preciso sempre considerar os casos distintos para exclusão. São eles:


Remoção na folha

    Quando o nó a ser excluído não possui filhos: 
        o ponteiro do pai é ajustado para NULL e o nó é liberado da memória. 
        Como não há subárvores envolvidas, a estrutura da árvore se mantém válida e não é necessário nenhum reordenamento adicional.
 
        https://cdn-conteudo.ensineme.com.br/17_89de374a40.jpg

Remoção de um nó com um filho

    Exige que o ponteiro do pai do nó removido passe a apontar para o filho existente, que pode estar à esquerda ou à direita. 
    Isso permite que os elementos inferiores continuem acessíveis e preserva a ordenação da árvore binária de busca. 
    O nó retirado é, então, liberado da memória sem quebrar a hierarquia da árvore. Veja:

    https://cdn-conteudo.ensineme.com.br/18_7104eb1d70.jpg


Remoção de nó com dois filhos

    Exige substituição cuidadosa para manter a ordenação da estrutura. 
    Há duas abordagens corretas e equivalentes:

    Usar o sucessor: Localizar o menor valor da subárvore direita do nó a ser removido. Esse valor é o primeiro maior do que o valor atual. 
    Após copiar esse valor para o nó original, remova o nó que continha esse sucessor na subárvore.

    Usar o antecessor: Identificar o maior valor da subárvore esquerda do nó a ser removido. Esse valor é o último menor do que o valor atual. 
    Assim como no caso anterior, ele é copiado para o nó original, que é, então, removido.

    https://cdn-conteudo.ensineme.com.br/19_45f509984a.jpg


*/

/*

Função para encontrar o nó com menor valor (mais à esquerda)
Essa função é usada na remoção quando o nó tem dois filhos

*/
No* encontrarMinimo(No* raiz) {
    No* atual = raiz;
    // Percorre sempre para a esquerda até encontrar o nó mais à esquerda
    while (atual && atual->esquerda != NULL) {
        atual = atual->esquerda;
    }
    return atual;
}

No* remover(No* raiz, const char* valor){
    if(raiz == NULL){
        return NULL;
    }

    if(strcmp(valor, raiz->valor) < 0){
        raiz->esquerda = remover(raiz->esquerda, valor);
    } else if (strcmp(valor, raiz->valor) > 0){
        raiz->direita = remover(raiz->direita, valor);
    } else {

        // Caso 1: sem filhos
        if(raiz->esquerda == NULL && raiz->direita == NULL){
            free(raiz);
            return NULL;
        }
        
        // Caso 2: com um único filho
        No* temp = NULL;

        if (raiz->esquerda == NULL) {
            temp = raiz->direita;
        } else if (raiz->direita == NULL) {
            temp = raiz->esquerda;
        }

        // Se um dos filhos é NULL, libera a raiz e retorna o filho não nulo
        if (raiz->esquerda == NULL || raiz->direita == NULL) {
            free(raiz->valor);
            free(raiz);
            return temp;
        }

        // Caso 3: dois filhos
        else{
            No* sucessor = encontrarMinimo(raiz->direita);
            free(raiz->valor);
            strcpy(raiz->valor, sucessor->valor);
            raiz->direita = remover(raiz->direita, sucessor->valor);
        }
    }
    return raiz;
}



// ---------------------------------------- IMPLEMENTAÇÃO -----------------------------------------------------

int main() {
    struct No* raiz = NULL;
 
    raiz = inserir(raiz, "Pegadas de Lama");
    raiz = inserir(raiz, "Chave perdida");
    raiz = inserir(raiz, "Livro com pagina faltando");
    raiz = inserir(raiz, "Lencol manchado");
    raiz = inserir(raiz, "Gaveta perdida");
 
    printf("\nElementos em ordem: ");
    emOrdem(raiz);
 
    printf("\nBusca por 'Lencol manchado': %s", buscar(raiz, "Lençol manchado") ? "Encontrado" : "Nao encontrado");
    printf("\nBusca por 'Oculos': %s\n", buscar(raiz, "Oculos") ? "Encontrado" : "Nao encontrado");
 
    return 0;
}

/* 
    
    Diagrama:
        https://cdn-conteudo.ensineme.com.br/20_5637cf1e33.jpg

*/