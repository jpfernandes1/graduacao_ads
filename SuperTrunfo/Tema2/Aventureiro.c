#include <stdio.h>
#include <string.h>

int main() {
    char pais1[20]; 
    unsigned long int populacao1;
    float area1;
    float pib1;
    int qntPontosTuristicos1;
    float densidadePopulacional1;
    float pibPerCapita1;

    char pais2[20];
    unsigned long int populacao2;
    float area2;
    float pib2;
    int qntPontosTuristicos2;
    float densidadePopulacional2;
    float pibPerCapita2;

    printf("---Cadastro de Cartas para o Super Trunfo---\n\n");

    // Carta 1
    printf("Carta 1:\n\n");
    printf("Digite o nome do País: ");
    scanf(" %2s", pais1);

    getchar();  // Consumir o \n residual que ficou no buffer

    printf("Digite a população do país: ");
    scanf("%lu", &populacao1);

    printf("Digite a área do país (em km²): ");
    scanf("%f", &area1);

    printf("Digite o PIB do país: ");
    scanf("%f", &pib1);

    printf("Digite o número de pontos turísticos do país: ");
    scanf("%d", &qntPontosTuristicos1);

    densidadePopulacional1 = populacao1 / area1;
    pibPerCapita1 = pib1 / populacao1;
    double superPoder1 = populacao1 + area1 + pib1 + qntPontosTuristicos1 + pibPerCapita1 + (1.0 / densidadePopulacional1);

    // Carta 2
    printf("\n\nCarta 2:\n\n");
    printf("Digite o nome do País: ");
    scanf(" %2s", pais2);

    getchar();  // Consumir o \n residual que ficou no buffer

    printf("Digite a população do pais: ");
    scanf("%lu", &populacao2);

    printf("Digite a área do pais (em km²): ");
    scanf("%f", &area2);

    printf("Digite o PIB do pais: ");
    scanf("%f", &pib2);

    printf("Digite o número de pontos turísticos do país: ");
    scanf("%d", &qntPontosTuristicos2);

    densidadePopulacional2 = populacao2 / area2;
    pibPerCapita2 = pib2 / populacao2;
    double superPoder2 = populacao2 + area2 + pib2 + qntPontosTuristicos2 + pibPerCapita2 + (1.0 / densidadePopulacional2);

    printf("\n -------Seguem os dados cadastrados:------\n");

    printf("\nCarta 1:\n\n"
           "País: %s\n"
           "Código: %s\n"
           "População: %lu\n"
           "Área: %.2f km²\n"
           "PIB: %.2f bilhões de reais\n"
           "Número de Pontos Turísticos: %d\n"
           "Densidade Populacional: %.2f hab/km²\n"
           "PIB per Capita: %.2f reais\n",
           pais1, populacao1, area1, pib1,
           qntPontosTuristicos1, densidadePopulacional1, pibPerCapita1);

    printf("\nCarta 2:\n\n"
           "País: %s\n"
           "Código: %s\n"
           "População: %lu\n"
           "Área: %.2f km²\n"
           "PIB: %.2f bilhões de reais\n"
           "Número de Pontos Turísticos: %d\n"
           "Densidade Populacional: %.2f hab/km²\n"
           "PIB per Capita: %.2f reais\n",
           pais2, populacao2, area2, pib2,
           qntPontosTuristicos2, densidadePopulacional2, pibPerCapita2);

       printf("--------Fim dos Inputs--------\n\n");

       printf("Qual atributo você quer comparar?\n"
        "1. Nome do país (Exibir informações paises cadastrados\n"
        "2. População\n"
        "3. Área\n"
        "4. PIB\n"
        "5. Número de pontos Turísticos\n"
        "6. Densidade demográfica\n"
    );
 
    int escolha;
    scanf("%d", &escolha);

    switch (escolha)
    {
    case 1:
        printf("Os paises cadastrados foram: %s e %s", pais1, pais2);
        break;
    case 2:
        printf("O atributo selecionado foi População\n"
                "%s possui %lu habitantes\n"
                "%s possui %lu habitantes\n",
                pais1, pais2, populacao1, populacao2);

    if (populacao1 > populacao2)
    {
        printf("%s venceu pois possui uma população maior", pais1);
    } else if (populacao1 < populacao2){
        printf("%s venceu pois possui uma popuplação maior", pais2);
    } else {
        printf("Houve um empate! As populações são iguais.");
    }
    
        printf("---------Fim do jogo--------");
        break;
    
    case 3:
        printf("O atributo selecionado foi Área\n"
                "%s possui área de %.2f km²\n"
                "%s possui área de %.2f km²\n",
               pais1, pais2, area1, area2);

    if (area1 > area2)
    {
        printf("%s venceu pois possui uma area maior", pais1);
    } else if (area1 < area2){
        printf("%s venceu pois possui uma area maior", pais2);
    } else {    
        printf("Houve um empate! As areas são iguais.");
    }
    
        printf("---------Fim do jogo--------");
        break;
    
    case 4:
        printf("O atributo selecionado foi PIB\n"
                "%s possui PIB de %lu bilhões \n"
                "%s possui PIB de %lu bilhões\n",
                pais1, pais2, pib1, pib2);

    if (pib1 > pib2)
    {
        printf("%s venceu pois possui um PIB maior", pais1);
    } else if (populacao1 < populacao2){
        printf("%s venceu pois possui um PIB maior", pais2);
    } else {
        printf("Houve um empate! Os PIBs são iguais.");
    }
    
        printf("---------Fim do jogo--------");
        break;
    
    case 5:
        printf("O atributo selecionado foi Quantidade de Pontos turisticos\n"
                "%s possui %d Pontos Turisticos\n"
                "%s possui %d Pontos Turisticos\n",
                pais1, pais2, qntPontosTuristicos1, qntPontosTuristicos2);

    if (qntPontosTuristicos1 > qntPontosTuristicos2)
    {
        printf("%s venceu pois possui mais pontos turisticos", pais1);
    } else if (qntPontosTuristicos1 < qntPontosTuristicos2){
        printf("%s venceu pois possui mais pontos turisticos", pais2);
    } else {
        printf("Houve um empate! Os paises possuem a mesma quantidade de pontos turisticos.");
    }
    
        printf("---------Fim do jogo--------");
        break;
    
    case 6:
        printf("O atributo selecionado foi Densidade demográfica\n"
                "%s possui a densidade demográfica de %.2f\n"
                "%s possui a densidade demográfica de %.2f\n",
                pais1, pais2, densidadePopulacional1, densidadePopulacional2);

    if (densidadePopulacional1 < densidadePopulacional2)
    {
        printf("%s venceu pois possui Densidade demográfica menor", pais1);
    } else if (populacao1 > populacao2){
        printf("%s venceu pois possui Densidade demográfica menor", pais2);
    } else {
        printf("Houve um empate! As Densidades demográficas são iguais.");
    }
    
        printf("---------Fim do jogo--------");
        break;
    
    default:
        printf("Entrada inválida");
        break;
    }
/*
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

    printf("\n--- Fim do programa ---\n");*/

    return 0;
}

