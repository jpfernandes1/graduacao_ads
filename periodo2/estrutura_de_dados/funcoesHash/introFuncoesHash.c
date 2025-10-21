// Associação Chave-valor e Funções Hash

/*

Funcionamento Função Hash:
    - Converte a chave (geralmente uma string) em um índice numérico
    - Esse índice determina onde o valor é armazenado ou buscado em um vetor interno

Propriedades de uma boa função hash:
    - Determinismo: Sempre gera o mesmo índice para a mesma chave. Logo, se "João" for convertido em 35 uma vez, sempre deverá resultar 35.
    - Eficiência: O cálculo da função hash deve ser rápido, já que ela será usada com frequência durante operações de inserção, busca e remoção.
    - Dispersão uniforme: Deve distribuir as chaves bem na tabela para evitar colisões (índices repetidos)

*/

// --------- IMPLEMENTAÇÃO HASH SIMPLES -----------

/*

No exemplo abaixo a função percorre cada caractere da string e acumula seu valor numérico (com base na tabela ASCII). 
O resultado é, então, reduzido ao intervalo da tabela (por exemplo, 0 a 99 para uma tabela de 100 posições), usando o operador módulo (% tamanho_tabela).

*/

int hashSimples(const char* str, int tamanho_tabela){
    int soma = 0;
    for(int i = 0; str[i] != '\0'; i++){
        soma += str[i];
    }
    return soma % tamanho_tabela;
}


/* --------- IMPLEMENTAÇÃO HASH PONDERADA -----------

Podemos também aplicar pesos para dar mais importância à posição dos caracteres.
No exemplo a seguir, o valor de cada caractere é multiplicado por sua posição na string, 
o que tende a gerar uma distribuição um pouco melhor para certas combinações.

*/

int hashPonderado(const char* str, int tamanho_tabela){
    int hash = 0;
    for (int i = 0; str[i] != '\0'; i++){
        hash += str[i]* (i+1);
    }
    return hash %tamanho_tabela;
    
}


/*

Influência da função hash na eficiência

A escolha da função hash tem impacto direto na eficiência geral da tabela hash. Uma função ruim, que gera muitos índices repetidos, resulta colisões, que forçam o uso de técnicas adicionais, como listas encadeadas, sondagem linear ou dupla. Isso afeta a velocidade das operações e, em casos extremos, pode tornar a tabela hash tão lenta quanto uma lista comum.

Por outro lado, uma função hash bem planejada e adaptada ao tipo de dados armazenados proporciona acesso rápido, até mesmo em grandes volumes de informação. Por isso, projetar boas funções hash é uma etapa crítica na construção de sistemas de alta performance, desde bancos de dados até caches de páginas da web e verificadores de integridade de arquivos.


obs.: O estudo das funções hash vai muito além de um simples exercício técnico. Ele desempenha um papel fundamental na criação de soluções eficientes para problemas concretos de organização e busca de dados.
*/
