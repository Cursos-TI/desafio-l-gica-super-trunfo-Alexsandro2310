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

    // ADICIONADO MENU DE ESCOLHA DUPLA
    int primeiraEscolha, segundaEscolha;
    float valor1_carta1 = 0, valor1_carta2 = 0;
    float valor2_carta1 = 0, valor2_carta2 = 0;
    float soma1, soma2;

    printf("\nEscolha o primeiro atributo para comparar:\n");
    printf("1 - Populacao\n2 - Area\n3 - PIB\n4 - Pontos Turisticos\n5 - Densidade Demografica\n");
    printf("Escolha (1-5): ");
    scanf("%d", &primeiraEscolha);

    printf("\nEscolha o segundo atributo para comparar:\n");
    for (int i = 1; i <= 5; i++) {
        if (i != primeiraEscolha) {
            switch (i) {
                case 1: printf("1 - Populacao\n"); break;
                case 2: printf("2 - Area\n"); break;
                case 3: printf("3 - PIB\n"); break;
                case 4: printf("4 - Pontos Turisticos\n"); break;
                case 5: printf("5 - Densidade Demografica\n"); break;
            }
        }
    }
    printf("Escolha (1-5): ");
    scanf("%d", &segundaEscolha);

    printf("\nComparando %s com %s:\n\n", cidade1, cidade2);


       // Captura os valores dos atributos escolhidos
    switch (primeiraEscolha) {
        case 1: valor1_carta1 = populacao1; valor1_carta2 = populacao2; break;
        case 2: valor1_carta1 = areakm1; valor1_carta2 = areakm2; break;
        case 3: valor1_carta1 = pib1; valor1_carta2 = pib2; break;
        case 4: valor1_carta1 = pontosturisticos1; valor1_carta2 = pontosturisticos2; break;
        case 5: valor1_carta1 = densidade1; valor1_carta2 = densidade2; break;
        default: printf("Atributo invalido\n"); return 1;
    }

    switch (segundaEscolha) {
        case 1: valor2_carta1 = populacao1; valor2_carta2 = populacao2; break;
        case 2: valor2_carta1 = areakm1; valor2_carta2 = areakm2; break;
        case 3: valor2_carta1 = pib1; valor2_carta2 = pib2; break;
        case 4: valor2_carta1 = pontosturisticos1; valor2_carta2 = pontosturisticos2; break;
        case 5: valor2_carta1 = densidade1; valor2_carta2 = densidade2; break;
        default: printf("Atributo invalido\n"); return 1;
    }

    printf("Atributo %d - %s: %.2f | %s: %.2f\n", primeiraEscolha, cidade1, valor1_carta1, cidade2, valor1_carta2);
    printf("Atributo %d - %s: %.2f | %s: %.2f\n", segundaEscolha, cidade1, valor2_carta1, cidade2, valor2_carta2);


      // Ajuste da lógica para Densidade Demográfica (menor vence)
    valor1_carta1 = (primeiraEscolha == 5) ? (1 / valor1_carta1) : valor1_carta1;
    valor1_carta2 = (primeiraEscolha == 5) ? (1 / valor1_carta2) : valor1_carta2;
    valor2_carta1 = (segundaEscolha == 5) ? (1 / valor2_carta1) : valor2_carta1;
    valor2_carta2 = (segundaEscolha == 5) ? (1 / valor2_carta2) : valor2_carta2;

    soma1 = valor1_carta1 + valor2_carta1;
    soma2 = valor1_carta2 + valor2_carta2;

    printf("\nSoma dos Atributos - %s: %.2f | %s: %.2f\n", cidade1, soma1, cidade2, soma2);

    if (soma1 > soma2) printf("\nVencedora: %s\n", cidade1);
    else if (soma2 > soma1) printf("\nVencedora: %s\n", cidade2);
    else printf("\nEmpate!\n");

    return 0;
}



}