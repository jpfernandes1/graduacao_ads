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
    fgets(pais1, sizeof(pais1), stdin);
    pais1[strcspn(pais1, "\n")] = 0;  // Remover o '\n' ao fim do input do fgets

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

    // Limpar o buffer após o último scanf
    getchar();

    // Carta 2
    printf("\n\nCarta 2:\n\n");
    printf("Digite o nome do País: ");
    fgets(pais2, sizeof(pais2), stdin);
    pais2[strcspn(pais2, "\n")] = 0;  // Remover o '\n' ao fim do input do fgets

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
           "População: %lu\n"
           "Área: %.2f km²\n"
           "PIB: %.2f bilhões de reais\n"
           "Número de Pontos Turísticos: %d\n"
           "Densidade Populacional: %.2f hab/km²\n"
           "PIB per Capita: %.2f reais\n",
           pais2, populacao2, area2, pib2,
           qntPontosTuristicos2, densidadePopulacional2, pibPerCapita2);

    printf("--------Fim dos Inputs--------\n\n");

    printf("Atributos inseridos: \n"
           "1. Nome do país (Exibir informações paises cadastrados\n"
           "2. População\n"
           "3. Área\n"
           "4. PIB\n"
           "5. Número de pontos Turísticos\n"
           "6. Densidade demográfica\n"
    );
    printf("Digite o numero correspondente ao atributo que você quer avaliar: ");
    printf("\n");
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
                printf("%s venceu pois possui uma população maior\n", pais1);
            } else if (populacao1 < populacao2){
                printf("%s venceu pois possui uma população maior\n", pais2);
            } else {
                printf("Houve um empate! As populações são iguais.\n\n");
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
                printf("%s venceu pois possui uma area maior\n", pais1);
            } else if (area1 < area2){
                printf("%s venceu pois possui uma area maior\n", pais2);
            } else {    
                printf("Houve um empate! As areas são iguais.\n\n");
            }

            printf("---------Fim do jogo--------");
            break;

        case 4:
            printf("O atributo selecionado foi PIB\n"
                   "%s possui PIB de %.2f bilhões \n"
                   "%s possui PIB de %.2f bilhões\n",
                   pais1, pais2, pib1, pib2);

            if (pib1 > pib2)
            {
                printf("%s venceu pois possui um PIB maior\n", pais1);
            } else if (pib1 < pib2){
                printf("%s venceu pois possui um PIB maior\n", pais2);
            } else {
                printf("Houve um empate! Os PIBs são iguais.\n\n");
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
                printf("%s venceu pois possui mais pontos turisticos\n", pais1);
            } else if (qntPontosTuristicos1 < qntPontosTuristicos2){
                printf("%s venceu pois possui mais pontos turisticos\n", pais2);
            } else {
                printf("Houve um empate! Os paises possuem a mesma quantidade de pontos turisticos.\n\n");
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
                printf("%s venceu pois possui Densidade demográfica menor\n", pais1);
            } else if (densidadePopulacional1 > densidadePopulacional2){
                printf("%s venceu pois possui Densidade demográfica menor\n", pais2);
            } else {
                printf("Houve um empate! As Densidades demográficas são iguais.\n\n");
            }

            printf("---------Fim do jogo--------");
            break;

        default:
            printf("Entrada inválida\n");
            printf("---------Fim do jogo--------");
            break;
    }

    return 0;
}
