# README - Super Trunfo Tema 2 - Aventureiro

# Super Trunfo - Cadastro de Cartas de Países

Este aplicativo implementa um jogo de Super Trunfo onde é possível cadastrar cartas de países e compara-las conforme seus atributos.

## Funcionalidade

O jogo permite o cadastro de duas cartas de países, com os seguintes atributos:

- Nome do país
- População
- Área (em km²)
- PIB (em bilhões de reais)
- Quantidade de pontos turísticos
- Densidade populacional (calculada automaticamente)
- PIB per capita (calculado automaticamente)

Após o cadastro, o usuário pode escolher um atributo e comparar as cartas de acordo com o atributo escolhido. O programa então determina qual país "vence" a rodada com base no valor do atributo selecionado.

## Como Rodar o Projeto

### Pré-requisitos

Para executar o projeto, você precisa ter um compilador C instalado em seu sistema. Caso não tenha, você pode instalar o **GCC** ou usar qualquer ambiente de desenvolvimento C de sua preferência.

### Passos para Execução

1. **Baixe o código:**
   Clone ou faça o download deste repositório.

   ```bash
   git clone https://seu_repositorio.git
   ```

2. **Compile o código**: 

    Use o seguinte comando para compilar o arquivo main.c:

    ```bash
    gcc main.c -o super_trunfo
    ```

3. **Execute o programa**: 

    Após compilar, execute o programa com o comando:

    ```bash
    ./super_trunfo
    ```

4. **Interaja com o jogo**: 
    
    Siga as instruções no console para cadastrar os países e escolher os atributos para comparação.


### Estrutura do Código
O código principal está no arquivo Aventureiro.c, onde as funcionalidades são divididas em etapas:

### Cadastro de cartas: 
O usuário insere os dados de dois países, incluindo nome, população, área, PIB, quantidade de pontos turísticos e o número de habitantes.

### Cálculos automáticos: 
O programa calcula automaticamente a densidade populacional e o PIB per capita para cada país.

### Comparação dos atributos: 
O usuário escolhe um atributo (população, área, PIB, pontos turísticos ou densidade populacional) e o programa compara os países com base nesse atributo.

### Resultado da rodada: 
O país com o maior valor para o atributo escolhido é o vencedor da rodada. Em caso de empate, é informado ao usuário.


## Contribuições

Se você quiser melhorar o projeto ou adicionar novas funcionalidades, 
fique à vontade para criar um fork e enviar um pull request.
