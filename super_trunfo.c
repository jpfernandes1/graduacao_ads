# include <stdio.h>

int main(){

    char Estado1[20];
    char CodigoCarta1[20];
    char NomeCidade1[20];
    int Populacao1;
    float Area1;
    float PIB1;
    int QntPontosTuristicos1;

    char Estado2[20];
    char CodigoCarta2[20];
    char NomeCidade2[20];
    int Populacao2;
    float Area2;
    float PIB2;
    int QntPontosTuristicos2;

printf("---Cadastro de Cartas para o Super Trunfo---\n\n");
printf("Carta 1:\n\n");
printf("Digite a letra do Estado (de 'A' a 'H'):");
scanf("%s", &Estado1);
printf("Digite o código da Carta (um número de 01 a 04):");
scanf("%s", &CodigoCarta1);
printf("Digite o nome da cidade:");
scanf("%s", &NomeCidade1);
printf("Digite a população da cidade: ");
scanf("%d", &Populacao1);
printf("Digite a área da cidade (em km²):");
scanf("%f", &Area1);
printf("Digite o PIB da cidade: ");
scanf("%f", &PIB1);
printf("Digite o numero de pontos turísticos da cidade: ");
scanf("%d", &QntPontosTuristicos1);


printf("\n\nCarta 2:\n\n");
printf("Digite a letra do Estado (de 'A' a 'H'):");
scanf("%s", &Estado2);
printf("Digite o código da Carta (um número de 01 a 04):");
scanf("%s", &CodigoCarta2);
printf("Digite o nome da cidade:");
scanf("%s", &NomeCidade2);
printf("Digite a população da cidade: ");
scanf("%d", &Populacao2);
printf("Digite a área da cidade (em km²):");
scanf("%f", &Area2);
printf("Digite o PIB da cidade: ");
scanf("%f", &PIB2);
printf("Digite o numero de pontos turísticos da cidade: ");
scanf("%d", &QntPontosTuristicos2);

printf("\n -------Seguem os dados cadastrados:------\n");

printf("\nCarta 01:\n");
printf("\nEstado: %s", Estado1);
printf("\nCódigo: %s%s", Estado1, CodigoCarta1);
printf("\nNome da Cidade: %s", NomeCidade1);
printf("\nPopulação: %d", Populacao1);
printf("\nÁrea: %.2f", Area1, "km²");
printf("\nPIB: %.2f", PIB1, "bilhões de reais");
printf("\nNúmero de Pontos Turísticos: %d\n", QntPontosTuristicos1);

printf("\n\nCarta 02:\n");
printf("\nEstado: %s", Estado2);
printf("\nCódigo: %s%s", Estado2, CodigoCarta2);
printf("\nNome da Cidade: %s", NomeCidade2);
printf("\nPopulação: %d", Populacao2);
printf("\nÁrea: %.2f", Area2, "km²");
printf("\nPIB: %.2f", PIB2, "bilhões de reais");
printf("\nNúmero de Pontos Turísticos: %d", QntPontosTuristicos2);



printf("\n Fim do programa---");
}
