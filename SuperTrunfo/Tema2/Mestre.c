#include <stdio.h>
#include <string.h>

int main() {
    
    char pais1[20];
    unsigned long int populacao1 = 0;
    float area1 = -1.0;
    float pib1 = -1.0;
    int qntPontosTuristicos1 = -1;
    float densidadePopulacional1 = -1.0;
    float pibPerCapita1 = -1.0;

    char pais2[20];
    unsigned long int populacao2 = 0;
    float area2 = -1.0;
    float pib2 = -1.0;
    int qntPontosTuristicos2 = -1;
    float densidadePopulacional2 = -1.0;
    float pibPerCapita2 = -1.0;

    printf("---Cadastro dos para o Super Trunfo---\n\n");

    // Carta 1
    printf("Carta 1:\n");
    printf("Digite o nome do primeiro País: ");
    fgets(pais1, sizeof(pais1), stdin);

    // Carta 2
    printf("\nCarta 2:\n");
    printf("Digite o nome do segundo País: ");
    fgets(pais2, sizeof(pais2), stdin);
    pais2[strcspn(pais2, "\n")] = 0;  // Remover o '\n' ao fim do input do fgets


    printf("\nEscolha o primeiro atributo para preencher e comparar:\n");
    if (populacao1 == 0) printf("1. População\n");
    if (area1 == -1.0) printf("2. Área\n");
    if (pib1 == -1.0) printf("3. PIB\n");
    if (qntPontosTuristicos1 == -1) printf("4. Quantidade de Pontos Turísticos\n");
    if (densidadePopulacional1 == -1.0) printf("5. Densidade Populacional\n");
    if (pibPerCapita1 == -1.0) printf("6. PIB per Capita\n");

    int escolha1;
    scanf("%d", &escolha1);

    switch (escolha1) {
        case 1:
            printf("Digite a população do país %s: ", pais1);
            scanf("%lu", &populacao1);
            printf("Digite a população do país %s: ", pais2);
            scanf("%lu", &populacao2);
            
            char* resultado1 = populacao1 > populacao2 ? pais1 : pais2;
            printf("%s Venceu a primeira rodada, pois tem população maior\n", resultado1);

            break;

        case 2:
            printf("Digite a área do pais %s", (char *)pais1);
            scanf("%f", &area1);
            printf("Digite a área do pais %s", (char *)pais2);
            scanf("%f", &area2);

            char* resultado1 = area1 > area2 ? pais1 : pais2;
            printf("%s Venceu a primeira rodada, pois tem area maior\n", resultado1); 

            break;

        case 3:
        printf("Digite o PIB do pais %s", (char *)pais1);
        scanf("%f", &pib1);
        printf("Digite o PIB do pais %s", (char *)pais2);
        scanf("%f", &pib2);  
        
        char* resultado1 = pib1 > pib2 ? pais1 : pais2;
        printf("%s Venceu a primeira rodada, pois tem pib maior\n", resultado1);

            break;

        case 4:
        printf("Digite a quantidade de pontos turisticos do pais %s", (char *)pais1);
        scanf("%f", &qntPontosTuristicos1);
        printf("Digite a quantidade de pontos turisticos do pais %s", (char *)pais2);
        scanf("%f", &qntPontosTuristicos2);

        char* resultado1 = qntPontosTuristicos1 > qntPontosTuristicos2 ? pais1 : pais2;
        printf("%s Venceu a primeira rodada, pois tem mais pontos turisticos\n", resultado1);

            break;    
           
        case 5:
        printf("Para calcular a densidade populacional é nessário saber a população e a área do país\n");

        if(populacao1 == 0){
            printf("Digite a população do país %s: ", pais1);
            scanf("%lu", &populacao1);
            printf("Digite a população do país %s: ", pais2);
            scanf("%lu", &populacao2);
        } else {printf("Populações dos paises já foram cadastradas!\n");}

        if(area1 == -1.0){
            printf("Digite a área do pais %s: ", (char *)pais1);
            scanf("%f", &area1);
            printf("Digite a área do pais %s: ", (char *)pais2);
            scanf("%f", &area2);
        } else {printf("Áreas dos paises já foram cadastradas!\n");}
        
        densidadePopulacional1 = populacao1 / area1;         
        densidadePopulacional2 = populacao2 / area2;
       
        
        printf("A densidade populacional do país %s é %.2f", pais1, densidadePopulacional1);
        printf("A densidade populacional do país %s é %.2f", pais2, densidadePopulacional2);

        char* resultado1 = densidadePopulacional1 < densidadePopulacional2 ? pais1 : pais2;
        printf("%s Venceu a primeira rodada, pois tem densidade demográfica menor\n", resultado1);

             break;

         case 6:
         printf("Para calcular o PIB Per Capita é nessário saber o PIB e a população dos paises!\n");      
 
         if(pib1 == -1.0){
             printf("Digite o pib do pais %s: ", pais1);
             scanf("%f", &pib1);
             printf("Digite o pib do pais %s: ", pais2);
             scanf("%f", &pib2);
         } else {printf("Os PIBs dos paises já foram cadastrados!\n");}

         if(populacao1 == 0){
            printf("Digite a população do país %s: ", pais1);
            scanf("%lu", &populacao1);
            printf("Digite a população do país %s: ", pais2);
            scanf("%lu", &populacao2);
        } else {printf("Populações dos paises já foram cadastradas!\n");}
         
         pibPerCapita1 = pib1 / populacao1;
         pibPerCapita2 = pib2 / populacao2;
                 
         printf("O PIB Per capita do país %s é %.2f", pais1, pibPerCapita1);
         printf("O PIB Per capita do país %s é %.2f", pais2, pibPerCapita2);  
         
         char* resultado1 = pibPerCapita1 > pibPerCapita2 ? pais1 : pais2;
        printf("%s Venceu a primeira rodada, pois tem pib Per Capita maior\n", resultado1);
             
             break;
    }

    printf("-----------------------------------------------------");
    printf("\nEscolha o segundo atributo para preencher e comparar:\n");
    
    if (escolha1 != 1) printf("1. População\n");
    if (escolha1 != 2) printf("2. Área\n");
    if (escolha1 != 3) printf("3. PIB\n");
    if (escolha1 != 4) printf("4. Quantidade de Pontos Turísticos\n");
    if (escolha1 != 5) printf("5. Densidade Populacional\n");
    if (escolha1 != 6) printf("6. PIB per Capita\n");

    int escolha2;
    scanf("%d", &escolha2);

    if(escolha2 != escolha1){

    switch (escolha2) {
        case 1:
            printf("Digite a população do país %s: ", pais1);
            scanf("%lu", &populacao1);
            printf("Digite a população do país %s: ", pais2);
            scanf("%lu", &populacao2);

            char* resultado1 = populacao1 > populacao2 ? pais1 : pais2;
            printf("%s Venceu a segunda rodada, pois tem população maior\n", resultado1); 

            break;

        case 2:
            printf("Digite a área do pais %s", (char *)pais1);
            scanf("%f", &area1);
            printf("Digite a área do pais %s", (char *)pais2);
            scanf("%f", &area2);

            char* resultado1 = area1 > area2 ? pais1 : pais2;
            printf("%s Venceu a segunda rodada, pois tem area maior\n", resultado1); 

            break;

        case 3:
        printf("Digite o PIB do pais %s", (char *)pais1);
        scanf("%f", &pib1);
        printf("Digite o PIB do pais %s", (char *)pais2);
        scanf("%f", &pib2);     
        
        char* resultado1 = pib1 > pib2 ? pais1 : pais2;
        printf("%s Venceu a segunda rodada, pois tem pib maior\n", resultado1); 

            break;

        case 4:
        printf("Digite a quantidade de pontos turisticos do pais %s", (char *)pais1);
        scanf("%f", &qntPontosTuristicos1);
        printf("Digite a quantidade de pontos turisticos do pais %s", (char *)pais2);
        scanf("%f", &qntPontosTuristicos2);

        char* resultado1 = qntPontosTuristicos1 > qntPontosTuristicos2 ? pais1 : pais2;
        printf("%s Venceu a segunda rodada, pois tem mais pontos turisticos\n", resultado1); 

            break;    
           
        case 5:
        printf("Para calcular a densidade populacional é nessário saber a população e a área do país\n");

        if(populacao1 == 0){
            printf("Digite a população do país %s: ", pais1);
            scanf("%lu", &populacao1);
            printf("Digite a população do país %s: ", pais2);
            scanf("%lu", &populacao2);
        } else {printf("Populações dos paises já foram cadastradas!\n");}

        if(area1 == -1.0){
            printf("Digite a área do pais %s: ", (char *)pais1);
            scanf("%f", &area1);
            printf("Digite a área do pais %s: ", (char *)pais2);
            scanf("%f", &area2);
        } else {printf("Áreas dos paises já foram cadastradas!\n");}
        
        densidadePopulacional1 = populacao1 / area1;         
        densidadePopulacional2 = populacao2 / area2;
       
        
        printf("A densidade populacional do país %s é %.2f", pais1, densidadePopulacional1);
        printf("A densidade populacional do país %s é %.2f", pais2, densidadePopulacional2);

        char* resultado1 = densidadePopulacional1 < densidadePopulacional2 ? pais1 : pais2;
        printf("%s Venceu a segunda rodada, pois tem densidade demográfica menor\n", resultado1);

             break;

         case 6:
         printf("Para calcular o PIB Per Capita é nessário saber o PIB e a população dos paises!\n");      
 
         if(pib1 == -1.0){
             printf("Digite o pib do pais %s: ", pais1);
             scanf("%f", &pib1);
             printf("Digite o pib do pais %s: ", pais2);
             scanf("%f", &pib2);
         } else {printf("Os PIBs dos paises já foram cadastrados!\n");}

         if(populacao1 == 0){
            printf("Digite a população do país %s: ", pais1);
            scanf("%lu", &populacao1);
            printf("Digite a população do país %s: ", pais2);
            scanf("%lu", &populacao2);
        } else {printf("Populações dos paises já foram cadastradas!\n");}
         
         pibPerCapita1 = pib1 / populacao1;
         pibPerCapita2 = pib2 / populacao2;
                 
         printf("O PIB Per capita do país %s é %.2f", pais1, pibPerCapita1);
         printf("O PIB Per capita do país %s é %.2f", pais2, pibPerCapita2);      

        char* resultado1 = pibPerCapita1 > pibPerCapita2 ? pais1 : pais2;
        printf("%s Venceu a segunda rodada, pois tem pib Per Capita maior\n", resultado1);
             
             break;
    }} else {
        printf("Você escolheu o mesmo atributo da rodada anterior!");
    }

    printf("-----------------------------------------------------");

printf("\n\nFim da execução do programa!\n\n");

 
   
}