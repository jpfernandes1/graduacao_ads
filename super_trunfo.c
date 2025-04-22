#include <stdio.h>
#include <string.h>

int main() {
    char estado1[3];  // 2 letras + '\0'
    char codigoCarta1[3];
    char nomeCidade1[50];
    unsigned long int populacao1;
    float area1;
    float pib1;
    int qntPontosTuristicos1;
    float densidadePopulacional1;
    float pibPerCapita1;
    char codigoFinal1[6];

    char estado2[3];
    char codigoCarta2[3];
    char nomeCidade2[50];
    unsigned long int populacao2;
    float area2;
    float pib2;
    int qntPontosTuristicos2;
    float densidadePopulacional2;
    float pibPerCapita2;
    char codigoFinal2[6];

    printf("---Cadastro de Cartas para o Super Trunfo---\n\n");

    // Carta 1
    printf("Carta 1:\n\n");
    printf("Digite a sigla do estado (Ex.: MA, SP..): ");
    scanf(" %2s", estado1);

    printf("Digite o código da Carta (um número de 01 a 04): ");
    scanf(" %2s", codigoCarta1);

    // Limpar buffer antes de usar fgets
    getchar();  // Consumir o \n residual que ficou no buffer

    printf("Digite o nome da cidade: ");
    fgets(nomeCidade1, sizeof(nomeCidade1), stdin);
    nomeCidade1[strcspn(nomeCidade1, "\n")] = '\0'; // remove o \n

    printf("Digite a população da cidade: ");
    scanf("%lu", &populacao1);

    printf("Digite a área da cidade (em km²): ");
    scanf("%f", &area1);

    printf("Digite o PIB da cidade: ");
    scanf("%f", &pib1);

    printf("Digite o número de pontos turísticos da cidade: ");
    scanf("%d", &qntPontosTuristicos1);

    sprintf(codigoFinal1, "%s%s", estado1, codigoCarta1);

    densidadePopulacional1 = populacao1 / area1;
    pibPerCapita1 = pib1 / populacao1;
    double superPoder1 = populacao1 + area1 + pib1 + qntPontosTuristicos1 + pibPerCapita1 + (1.0 / densidadePopulacional1);

    // Carta 2
    printf("\n\nCarta 2:\n\n");
    printf("Digite a sigla do estado (Ex.: MA, SP..): ");
    scanf(" %2s", estado2);

    printf("Digite o código da Carta (um número de 01 a 04): ");
    scanf(" %2s", codigoCarta2);

    // Limpar buffer antes de usar fgets
    getchar();  // Consumir o \n residual que ficou no buffer

    printf("Digite o nome da cidade: ");
    fgets(nomeCidade2, sizeof(nomeCidade2), stdin);
    nomeCidade2[strcspn(nomeCidade2, "\n")] = '\0';

    printf("Digite a população da cidade: ");
    scanf("%lu", &populacao2);

    printf("Digite a área da cidade (em km²): ");
    scanf("%f", &area2);

    printf("Digite o PIB da cidade: ");
    scanf("%f", &pib2);

    printf("Digite o número de pontos turísticos da cidade: ");
    scanf("%d", &qntPontosTuristicos2);

    sprintf(codigoFinal2, "%s%s", estado2, codigoCarta2);
    densidadePopulacional2 = populacao2 / area2;
    pibPerCapita2 = pib2 / populacao2;
    double superPoder2 = populacao2 + area2 + pib2 + qntPontosTuristicos2 + pibPerCapita2 + (1.0 / densidadePopulacional2);

    printf("\n -------Seguem os dados cadastrados:------\n");

    printf("\nCarta 1:\n\n"
           "Estado: %s\n"
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
           "Estado: %s\n"
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

    printf("\nComparação de cartas (Atributo: População):\n\n"
           "Carta 1 - %s (%s): %lu\n"
           "Carta 2 - %s (%s): %lu\n",
           nomeCidade1, estado1, populacao1, nomeCidade2, estado2, populacao2);

    if (populacao1 > populacao2) {
        printf("Resultado: %s (%s) venceu!\n\n", nomeCidade1, estado1);
    } else {
        printf("Resultado: %s (%s) venceu!\n\n", nomeCidade2, estado2);
    }

    const char *numeroCarta[] = {"2", "1"};

    printf("\nComparação dos demais atributos:\n\n"
           "Área: Carta %s venceu (%d)\n"
           "PIB: Carta %s venceu (%d)\n"
           "Pontos Turísticos: Carta %s venceu (%d)\n"
           "Densidade Populacional: Carta %s venceu (%d)\n"
           "PIB per Capita: Carta %s venceu (%d)\n"
           "Super Poder: Carta %s venceu (%d)\n",
           numeroCarta[area1 > area2], (area1 > area2),
           numeroCarta[pib1 > pib2], (pib1 > pib2),
           numeroCarta[qntPontosTuristicos1 > qntPontosTuristicos2], (qntPontosTuristicos1 > qntPontosTuristicos2),
           numeroCarta[densidadePopulacional1 > densidadePopulacional2], (densidadePopulacional1 > densidadePopulacional2),
           numeroCarta[pibPerCapita1 > pibPerCapita2], (pibPerCapita1 > pibPerCapita2),
           numeroCarta[superPoder1 > superPoder2], (superPoder1 > superPoder2));

    printf("\n--- Fim do programa ---\n");

    return 0;
}
