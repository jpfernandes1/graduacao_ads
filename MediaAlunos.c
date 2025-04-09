/* Crie um programa em C que calcula a média de três notas inseridas pelo usuário. 
Utilize variáveis para armazenar as notas, operadores matemáticos para somar e calcular a média, 
e operadores de atribuição para atualizar valores. */

# include <stdio.h>

int main(){
    float nota1, nota2, nota3;

    printf("Calculadora de Médias\n");
    printf("Digite a primeira nota:");
    scanf("%f", &nota1);
    printf("Digite a segunda nota:");
    scanf("%f", &nota2);
    printf("Digite a terceira nota:");
    scanf("%f", &nota3);

    float media = (nota1 + nota2 + nota3)/3;

    printf("A média das notas inseridas é: %.2f", media);

}
