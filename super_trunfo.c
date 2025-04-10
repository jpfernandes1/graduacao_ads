#include <stdio.h>

int main() {
    char Estado1[20];
    char CodigoCarta1[20];
    char NomeCidade1[20];
    int Populacao1;
    float Area1;
    float PIB1;
    int QntPontosTuristicos1;
    float DensidadePopulacional1;
    float PibPerCapita1;

    char Estado2[20];
    char CodigoCarta2[20];
    char NomeCidade2[20];
    int Populacao2;
    float Area2;
    float PIB2;
    int QntPontosTuristicos2;
    float DensidadePopulacional2;
    float PibPerCapita2;

    printf("---Cadastro de Cartas para o Super Trunfo---\n\n");

    // Carta 1
    printf("Carta 1:\n\n");
    printf("Digite a letra do Estado (de 'A' a 'H'): ");
    scanf("%s", Estado1);

    printf("Digite o código da Carta (um número de 01 a 04): ");
    scanf("%s", CodigoCarta1);

    printf("Digite o nome da cidade: ");
    scanf("%s", NomeCidade1);

    printf("Digite a população da cidade: ");
    scanf("%d", &Populacao1);

    printf("Digite a área da cidade (em km²): ");
    scanf("%f", &Area1);

    printf("Digite o PIB da cidade: ");
    scanf("%f", &PIB1);

    printf("Digite o número de pontos turísticos da cidade: ");
    scanf("%d", &QntPontosTuristicos1);

    // Esse trecho atribui os valores, após o scan
    DensidadePopulacional1 = Populacao1 / Area1;
    PibPerCapita1 = PIB1/ Populacao1;
    
   // Carta 2
    printf("\n\nCarta 2:\n\n");
    printf("Digite a letra do Estado (de 'A' a 'H'): ");
    scanf("%s", Estado2);

    printf("Digite o código da Carta (um número de 01 a 04): ");
    scanf("%s", CodigoCarta2);

    printf("Digite o nome da cidade: ");
    scanf("%s", NomeCidade2);

    printf("Digite a população da cidade: ");
    scanf("%d", &Populacao2);

    printf("Digite a área da cidade (em km²): ");
    scanf("%f", &Area2);

    printf("Digite o PIB da cidade: ");
    scanf("%f", &PIB2);

    printf("Digite o número de pontos turísticos da cidade: ");
    scanf("%d", &QntPontosTuristicos2);

    // Esse trecho atribui os valores, após o scan
    DensidadePopulacional2 = Populacao2 / Area2;
    PibPerCapita2 = PIB2/ Populacao2; 

    // Esse Trecho exibe os dados
    printf("\n -------Seguem os dados cadastrados:------\n");

    printf("\nCarta 01:\n");
    printf("Estado: %s\n", Estado1);
    printf("Código: %s%s\n", Estado1, CodigoCarta1);
    printf("Nome da Cidade: %s\n", NomeCidade1);
    printf("População: %d\n", Populacao1);
    printf("Área: %.2f km²\n", Area1);
    printf("PIB: %.2f bilhões de reais\n", PIB1);
    printf("Número de Pontos Turísticos: %d\n", QntPontosTuristicos1);
    printf("Densidade Populacional: %.2f hab/km²\n", DensidadePopulacional1);
    printf("PIB per Capita: %.2f reais\n", PibPerCapita1);

    printf("\nCarta 02:\n");
    printf("Estado: %s\n", Estado2);
    printf("Código: %s%s\n", Estado2, CodigoCarta2);
    printf("Nome da Cidade: %s\n", NomeCidade2);
    printf("População: %d\n", Populacao2);
    printf("Área: %.2f km²\n", Area2);
    printf("PIB: %.2f bilhões de reais\n", PIB2);
    printf("Número de Pontos Turísticos: %d\n", QntPontosTuristicos2);
    printf("Densidade Populacional: %.2f hab/km²\n", DensidadePopulacional2);
    printf("PIB per Capita: %.2f reais\n", PibPerCapita2);

    printf("\n--- Fim do programa ---\n");

    return 0;
}
