/*

    Organizar dados de forma eficiente e com acesso rápido é uma necessidade recorrente em diversas áreas da computação. 
    Diante disso, há estruturas de dados que cumprem esse papel com diferentes estratégias: 
        a) Árvores binárias de busca (BST)
        b) Tries. 
        
    Embora cada uma possua regras e finalidades distintas, todas compartilham o princípio de representar dados de maneira hierárquica
    para otimizar operações como busca, inserção e exclusão. 

    Trie (árvore de prefixos para strings)

    Atuam em um campo distinto, porém igualmente relevante. Diferente da BST, que opera com comparações entre valores, ela organiza strings caractere 
    por caractere: cada nível representa uma posição na string, enquanto cada ramificação indica uma possibilidade de caractere. 
    Assim, palavras com prefixos comuns compartilham parte do caminho dentro da estrutura. Essa organização permite buscas extremamente rápidas por palavras 
    completas e prefixos, com complexidade proporcional apenas ao tamanho da palavra, independentemente da quantidade de elementos armazenados.

    Dica: tries são amplamente utilizadas em sistemas de autocompletar, corretores ortográficos e algoritmos de compressão.

*/

/* 
        ESTRUTURA DO NÓ

        Para construir uma Trie, cada nó precisa representar possíveis ramificações para os próximos caracteres. 
        Em geral, utilizamos um array de ponteiros (por exemplo, 26 para letras minúsculas de 'a' a 'z') e um indicador 
        booleano que mostra se um caminho forma uma palavra completa:
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define TAMANHO_ALFABETO 26

typedef struct {
    struct NoTrie* filhos[TAMANHO_ALFABETO];
    bool ehFimDePalavra;
} NoTrie;

// A estrutura reserva espaço para até 26 possíveis filhos em cada nível e um campo ehFimDePalavra, 
// que nos ajuda a reconhecer quando uma sequência de caracteres completa uma palavra.

/*

    Criação de um nó

Ao iniciarmos a Trie, precisaremos de um nó raiz vazio.
Cada novo caractere inserido será conectado de modo dinâmico, conforme a palavra for processada.

*/

NoTrie* criarNo()
{
    NoTrie* novoNo = (NoTrie*) malloc(sizeof(NoTrie));
    novoNo->ehFimDePalavra = false;
    for(int i = 0; i<TAMANHO_ALFABETO; i++){
        novoNo->filhos[i] = NULL;
    }
};

// A alocação dinâmica permite que o espaço de memória seja utilizado apenas quando necessário. 
// Cada ponteiro inicializado com NULL viabiliza que a árvore cresça sob demanda, economizando espaço.


/*

    Inserção de palavras na Trie

Percorremos caractere por caractere e criamos os nós intermediários se eles ainda não existirem. 
A marcação de fim de palavra é essencial para distinguir palavras completas de simples prefixos.

*/

void inserir(NoTrie* raiz, const char* palavra){
    NoTrie* atual = raiz;

    for (int i = 0; palavra[i] != '\0'; i++) {
        int indice = palavra[i] - 'a';

        if(atual->filhos[indice] == NULL) {
            atual->filhos[indice] = criarNo();
        }
        atual = atual->filhos[indice];
    }
    atual->ehFimDePalavra = true;
}

// O uso de palavra[i] - 'a' transforma letras em índices de 0 a 25. Assim, a letra 'c' vira índice 2, por exemplo. 
// Isso permite acesso direto ao filho correspondente, sem necessidade de laços ou comparações.

/*

    Busca de palavras

É muito parecida com a inserção, ou seja, percorremos os nós conforme os caracteres da palavra. 
Se em algum momento o caminho não existir, significa que a palavra não está presente. 
E, mesmo se todos os caracteres forem encontrados, o nó final precisa estar marcado como fim de palavra, conforme vemos a seguir:

*/

bool buscar(NoTrie* raiz, const char* palavra){
    NoTrie* atual = raiz;

    for (int i = 0; palavra[i] !='\0'; i++) {
        int indice = palavra[i] - 'a';

        if (atual->filhos[indice] == NULL){
            return false;
        }

        atual = atual->filhos[indice];
    }

    return atual != NULL && atual->ehFimDePalavra;
        
}

// A função retorna true apenas se a sequência existir e estiver marcada como palavra completa. 
// Isso evita confundir prefixos com palavras reais.
    
/*

    Ordenação lexicográfica e normalização

Como a Trie armazena os caracteres em ramos que seguem a ordem do alfabeto (de ‘a’ a ‘z’), 
podemos percorrê-la em pré-ordem alfabética para imprimir todas as palavras de forma ordenada. 
Esse percurso pode ser feito de modo recurso.

*/

void listarPalavras(NoTrie* no, char* buffer, int nivel){
    if (no->ehFimDePalavra){
        buffer[nivel] = '\0';
        printf("%s\n", buffer);
    }

    for (int i = 0; i < TAMANHO_ALFABETO; i++) {
        if (no->filhos[i] != NULL){
            buffer[nivel] = 'a' + i;
            listarPalavras(no->filhos[i], buffer, nivel + 1);
        }
    }
}

void normalizar(const char* entrada, char* saida){
    int j = 0;
    for (int i = 0; entrada[i] != '\0'; i++)
    {
        char c = entrada[i];
        if(c >= 'A' && c <= 'Z') { c += 32;} // Converte para minúsculo
        if(c >= 'a' && c <= 'z') {saida[j++] = c;} // Mantém apenas letras
    }
    saida[j] = '\0';
}

/*

    Por que é necessário normalizar?

Nossa Trie foi projetada para funcionar com letras minúsculas de ‘a’ a ‘z’, ou seja, apenas 26 caracteres. 
Assim, ao tentar usar palavras com letras maiúsculas, espaços e acentos, podem ocorrer erros de acesso fora dos limites, 
retornando possíveis falhas no funcionamento do programa.

A normalização corrige isso, pois, antes de inserir a palavra na Trie, é feita uma conversão para letras minúsculas, 
remoção dos espaços, eliminar ou substituir caracteres com acento e garantir que cada caractere esteja entre ‘a’ e ‘z’.

*/

// ------------------------------------------------- IMPLEMENTAÇÃO -------------------------------------------------------

int main(){
    NoTrie* raiz = criarNo();
    char normalizada[100];

    normalizar("Pegadas de Lama", normalizada);
    inserir(raiz, normalizada);

    normalizar("Chave perdida", normalizada);
    inserir(raiz, normalizada);

    normalizar("Livro com página faltando", normalizada);
    inserir(raiz, normalizada);

     normalizar("Lençol manchado", normalizada);
    inserir(raiz, normalizada);
 
    normalizar("Gaveta perdida", normalizada);
    inserir(raiz, normalizada);

    char buffer[100]; // Tamanho máximo de palavra suportado
    listarPalavras(raiz, buffer, 0);

    return 0;
}