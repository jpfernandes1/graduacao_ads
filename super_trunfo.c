#include <stdio.h>

int main() {
    char estado1;
    char codigoCarta1[3];
    char nomeCidade1[20];
    unsigned long int populacao1;
    float area1;
    float pib1;
    int qntPontosTuristicos1;
    float densidadePopulacional1;
    float pibPerCapita1;
    char codigoFinal1[4];

    char estado2;
    char codigoCarta2[3];
    char nomeCidade2[20];
    unsigned long int populacao2;
    float area2;
    float pib2;
    int qntPontosTuristicos2;
    float densidadePopulacional2;
    float pibPerCapita2;
    char codigoFinal2[4];

    printf("---Cadastro de Cartas para o Super Trunfo---\n\n");

    // Carta 1
    printf("Carta 1:\n\n");
    printf("Digite a letra do Estado (de 'A' a 'H'): ");
    scanf(" %c", &estado1);  // espaço antes do %c é importante

    printf("Digite o código da Carta (um número de 01 a 04): ");
    scanf("%s", &codigoCarta1);

    printf("Digite o nome da cidade: ");
    scanf("%s", &nomeCidade1);

    printf("Digite a população da cidade: ");
    scanf("%lu", &populacao1);

    printf("Digite a área da cidade (em km²): ");
    scanf("%f", &area1);

    printf("Digite o PIB da cidade: ");
    scanf("%f", &pib1);

    printf("Digite o número de pontos turísticos da cidade: ");
    scanf("%d", &qntPontosTuristicos1);

    // Unificando Estado e numeração para criar o código
    sprintf(codigoFinal1, "%c%s", estado1, codigoCarta1);

    densidadePopulacional1 = populacao1 / area1;
    pibPerCapita1 = pib1 / populacao1;
    double superPoder = populacao1 + area1 + pib1 + qntPontosTuristicos1 + pibPerCapita1 + 1 / densidadePopulacional1;

    // Carta 2
    printf("\n\nCarta 2:\n\n");
    printf("Digite a letra do Estado (de 'A' a 'H'): ");
    scanf(" %c", &estado2);

    printf("Digite o código da Carta (um número de 01 a 04): ");
    scanf("%s", &codigoCarta2);

    printf("Digite o nome da cidade: ");
    scanf("%s", &nomeCidade2);

    printf("Digite a população da cidade: ");
    scanf("%lu", &populacao2);

    printf("Digite a área da cidade (em km²): ");
    scanf("%f", &area2);

    printf("Digite o PIB da cidade: ");
    scanf("%f", &pib2);

    printf("Digite o número de pontos turísticos da cidade: ");
    scanf("%d", &qntPontosTuristicos2);

    sprintf(codigoFinal2, "%c%s", estado2, codigoCarta2);
    densidadePopulacional2 = populacao2 / area2;
    pibPerCapita2 = pib2 / populacao2;
    double superPoder2 = populacao2 + area2 + pib2 + qntPontosTuristicos2 + pibPerCapita2 + 1 / densidadePopulacional2;

    printf("\n -------Seguem os dados cadastrados:------\n");

    printf("\nCarta 1:\n\n"
           "Estado: %c\n"
           "Código: %s\n"
           "Nome da Cidade: %s\n"
           "População: %lu\n"
           "Área: %.2f km²\n"
           "PIB: %.2f bilhões de reais\n"
           "Número de Pontos Turísticos: %d\n"
           "Densidade Populacional: %.2f hab/km²\n"
           "PIB per Capita: %.2f reais\n",
           estado1, codigoFinal1, nomeCidade1, populacao1, area1, pib1,
           qntPontosTuristicos1, densidadePopulacional1, pibPerCapita1);

    printf("\nCarta 2:\n\n"
           "Estado: %c\n"
           "Código: %s\n"
           "Nome da Cidade: %s\n"
           "População: %lu\n"
           "Área: %.2f km²\n"
           "PIB: %.2f bilhões de reais\n"
           "Número de Pontos Turísticos: %d\n"
           "Densidade Populacional: %.2f hab/km²\n"
           "PIB per Capita: %.2f reais\n",
           estado2, codigoFinal2, nomeCidade2, populacao2, area2, pib2,
           qntPontosTuristicos2, densidadePopulacional2, pibPerCapita2);

    const char *numeroCarta[] = {"2", "1"};

    printf("\nComparação de Cartas:\n\n"
           "População: Carta %s venceu (%d)\n"
           "Área: Carta %s venceu (%d)\n"
           "PIB: Carta %s venceu (%d)\n"
           "Pontos Turísticos: Carta %s venceu (%d)\n"
           "Densidade Populacional: Carta %s venceu (%d)\n"
           "PIB per Capita: Carta %s venceu (%d)\n"
           "Super Poder: Carta %s venceu (%d)\n",
           numeroCarta[populacao1 > populacao2], (populacao1 > populacao2),
           numeroCarta[area1 > area2], (area1 > area2),
           numeroCarta[pib1 > pib2], (pib1 > pib2),
           numeroCarta[qntPontosTuristicos1 > qntPontosTuristicos2], (qntPontosTuristicos1 > qntPontosTuristicos2),
           numeroCarta[densidadePopulacional1 < densidadePopulacional2], (densidadePopulacional1 < densidadePopulacional2),
           numeroCarta[pibPerCapita1 > pibPerCapita2], (pibPerCapita1 > pibPerCapita2),
           numeroCarta[superPoder > superPoder2], (superPoder > superPoder2));

    printf("\n--- Fim do programa ---\n");

    return 0;
}
