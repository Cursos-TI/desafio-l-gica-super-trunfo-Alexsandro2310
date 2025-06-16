#include <stdio.h>
#include <string.h> // Biblioteca necessária para comparar strings(biblioteca adicionada por conta propria)

//ALTERAÇOES E CODIGO FEITO E TESTADO NO VISUAL STUDIO CODE

int main() {
    //VARIAVEIS DA PRIMEIRA CARTA DO JOGO
    char estado1;
    int codigo1;
    char cidade1[50];
    unsigned long int populacao1; 
    float areakm1;
    float pib1;
    int pontosturisticos1;
    float densidade1;
    float pibPerCapita1;
    float superPoder1; 

    //VARIAVEIS DA SEGUNDA CARTA DO JOGO
    char estado2;
    int codigo2;
    char cidade2[50];
    unsigned long int populacao2; 
    float areakm2;
    float pib2;
    int pontosturisticos2;
    float densidade2;
    float pibPercapita2;
    float superPoder2; 

    //ENTRADA DE DADOS DA PRIMEIRA CARTA
    printf("Digite a letra do estado da primeira carta (A-H): \n");
    scanf(" %c", &estado1);

    printf("Digite o codigo da primeira carta (01-04): \n");
    scanf("%d", &codigo1);

    printf("Digite o nome da cidade:\n");
    scanf("%s", cidade1);

    printf("Informe a população da cidade: \n");
    scanf("%lu", &populacao1);

    printf("Informe a area da cidade (km²): \n");
    scanf("%f", &areakm1);

    printf("Informe o PIB da cidade: \n");
    scanf("%f", &pib1);

    printf("Informe quantos pontos turisticos tem na cidade: \n");
    scanf("%d", &pontosturisticos1);

    getchar(); // Limpeza do buffer

    //ENTRADA DE DADOS DA SEGUNDA CARTA
    printf("---------------------------------------------\n\n");

    printf("Digite a letra do estado da segunda carta (A-H): \n");
    scanf(" %c", &estado2);

    printf("Digite o codigo da segunda carta (01-04): \n");
    scanf("%d", &codigo2);

    printf("Digite o nome da cidade:\n");
    scanf("%s", cidade2);

    printf("Informe a população da cidade: \n");
    scanf("%lu", &populacao2);

    printf("Informe a area da cidade (km²): \n");
    scanf("%f", &areakm2);

    printf("Informe o PIB da cidade: \n");
    scanf("%f", &pib2);

    printf("Informe quantos pontos turisticos tem na cidade: \n");
    scanf("%d", &pontosturisticos2);

    // Cálculo de Densidade Populacional e PIB per Capita
    densidade1 = populacao1 / areakm1;
    pibPerCapita1 = pib1 / populacao1;

    densidade2 = populacao2 / areakm2;
    pibPercapita2 = pib2 / populacao2;

    // Cálculo do Super Poder
    superPoder1 = populacao1 + areakm1 + pib1 + pontosturisticos1 + pibPerCapita1 + (1.0 / densidade1);
    superPoder2 = populacao2 + areakm2 + pib2 + pontosturisticos2 + pibPercapita2 + (1.0 / densidade2);

    //ADICIONADO O MENU DE ESCOLHA

       int opcao;
    printf("\nEscolha um atributo para comparar:\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turisticos\n");
    printf("5 - Densidade Demografica\n");
    printf("Escolha (1-5): ");
    scanf("%d", &opcao);

    printf("\nComparando %s com %s:\n", cidade1, cidade2); // ADICIONADO

    // Escolha do atributo para comparação (Definido diretamente no código)
    char atributoEscolhido[] = "População"; // Troque por "Área", "PIB", etc.

    // Comparação das cartas
    printf("\nComparação de Cartas (Atributo: %s):\n", atributoEscolhido);

    // Estrutura de decisão para comparar as cartas com base no atributo escolhido
    if (strcmp(atributoEscolhido, "População") == 0) { // Comparação baseada na População
        printf("Carta 1 - %s: %lu\n", cidade1, populacao1);
        printf("Carta 2 - %s: %lu\n", cidade2, populacao2);

        if (populacao1 > populacao2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
        } else {
            printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
        }
    } else if (strcmp(atributoEscolhido, "Área") == 0) { // Comparação baseada na Área
        printf("Carta 1 - %s: %.2f km²\n", cidade1, areakm1);
        printf("Carta 2 - %s: %.2f km²\n", cidade2, areakm2);

        if (areakm1 > areakm2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
        } else {
            printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
        }
    } else if (strcmp(atributoEscolhido, "PIB") == 0) { // Comparação baseada no PIB
        printf("Carta 1 - %s: %.2f bilhões de reais\n", cidade1, pib1);
        printf("Carta 2 - %s: %.2f bilhões de reais\n", cidade2, pib2);

        if (pib1 > pib2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
        } else {
            printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
        }
    } else if (strcmp(atributoEscolhido, "Densidade Populacional") == 0) { // Comparação baseada na Densidade Populacional
        printf("Carta 1 - %s: %.2f hab/km²\n", cidade1, densidade1);
        printf("Carta 2 - %s: %.2f hab/km²\n", cidade2, densidade2);

        if (densidade1 < densidade2) { // Menor densidade vence
            printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
        } else {
            printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
        }
    } else if (strcmp(atributoEscolhido, "PIB per Capita") == 0) { // Comparação baseada no PIB per Capita
        printf("Carta 1 - %s: %.2f reais\n", cidade1, pibPerCapita1);
        printf("Carta 2 - %s: %.2f reais\n", cidade2, pibPercapita2);

        if (pibPerCapita1 > pibPercapita2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
        } else {
            printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
        }
    }

    return 0;
}