#include <stdio.h>

int main() {
    // Dados das duas cartas (pré-cadastradas)
    int populacao1 = 214000000;
    float area1 = 8515767.0;
    float pib1 = 2.05;
    int pontos1 = 30;
    float densidade1 = populacao1 / area1;

    int populacao2 = 125000000;
    float area2 = 377975.0;
    float pib2 = 5.15;
    int pontos2 = 25;
    float densidade2 = populacao2 / area2;

    int atributo1, atributo2;

    printf("===== SUPER TRUNFO FINAL - COMPARADOR DE DOIS ATRIBUTOS =====\n");
    printf("Carta 1: País A\n");
    printf("Carta 2: País B\n\n");

    // MENU PARA O PRIMEIRO ATRIBUTO
    printf("Escolha o PRIMEIRO atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("----------------------------------\n");
    printf("Opção: ");
    scanf("%d", &atributo1);

    if (atributo1 < 1 || atributo1 > 5) {
        printf("Opção inválida!\n");
        return 0;
    }

    // MENU DINÂMICO (segundo atributo, sem repetir o primeiro)
    printf("\nEscolha o SEGUNDO atributo (diferente do primeiro):\n");
    for (int i = 1; i <= 5; i++) {
        if (i != atributo1) {
            switch (i) {
                case 1: printf("1 - População\n"); 
                break;
                case 2: printf("2 - Área\n"); 
                break;
                case 3: printf("3 - PIB\n"); 
                break;
                case 4: printf("4 - Pontos Turísticos\n"); 
                break;
                case 5: printf("5 - Densidade Demográfica\n"); 
                break;
            }
        }
    }
    printf("----------------------------------\n");
    printf("Opção: ");
    scanf("%d", &atributo2);

    if (atributo2 < 1 || atributo2 > 5 || atributo2 == atributo1) {
        printf("Opção inválida ou repetida!\n");
        return 0;
    }

    printf("\n=============================================\n");

    // Função auxiliar para comparar um atributo e retornar pontos
    float valorA1 = 0, valorA2 = 0, valorB1 = 0, valorB2 = 0;

    // --- Comparação do primeiro atributo ---
    switch (atributo1) {
        case 1: valorA1 = populacao1; valorB1 = populacao2; printf("Atributo 1: População\n"); 
        break;
        case 2: valorA1 = area1; valorB1 = area2; printf("Atributo 1: Área\n"); 
        break;
        case 3: valorA1 = pib1; valorB1 = pib2; printf("Atributo 1: PIB\n"); 
        break;
        case 4: valorA1 = pontos1; valorB1 = pontos2; printf("Atributo 1: Pontos Turísticos\n"); 
        break;
        case 5: valorA1 = densidade1; valorB1 = densidade2; printf("Atributo 1: Densidade Demográfica\n"); 
        break;
    }

    // --- Comparação do segundo atributo ---
    switch (atributo2) {
        case 1: valorA2 = populacao1; valorB2 = populacao2; printf("Atributo 2: População\n"); break;
        case 2: valorA2 = area1; valorB2 = area2; printf("Atributo 2: Área\n"); break;
        case 3: valorA2 = pib1; valorB2 = pib2; printf("Atributo 2: PIB\n"); break;
        case 4: valorA2 = pontos1; valorB2 = pontos2; printf("Atributo 2: Pontos Turísticos\n"); break;
        case 5: valorA2 = densidade1; valorB2 = densidade2; printf("Atributo 2: Densidade Demográfica\n"); break;
    }

    // Exibir valores
    printf("\nValores dos atributos:\n");
    printf("País A: %.2f e %.2f\n", valorA1, valorA2);
    printf("País B: %.2f e %.2f\n", valorB1, valorB2);

    // --- Aplicar regra de comparação ---
    // Densidade Demográfica é invertida (menor vence)
    float pontosA = 0, pontosB = 0;

    // Primeiro atributo
    if (atributo1 == 5)
        (valorA1 < valorB1) ? (pontosA++) : (valorA1 > valorB1 ? pontosB++ : 0);
    else
        (valorA1 > valorB1) ? (pontosA++) : (valorA1 < valorB1 ? pontosB++ : 0);

    // Segundo atributo
    if (atributo2 == 5)
        (valorA2 < valorB2) ? (pontosA++) : (valorA2 > valorB2 ? pontosB++ : 0);
    else
        (valorA2 > valorB2) ? (pontosA++) : (valorA2 < valorB2 ? pontosB++ : 0);

    // Soma dos atributos
    float somaA = valorA1 + valorA2;
    float somaB = valorB1 + valorB2;

    printf("\nSoma dos atributos:\n");
    printf("País A: %.2f\n", somaA);
    printf("País B: %.2f\n", somaB);

    // --- Resultado final ---
    printf("\nRESULTADO FINAL:\n");
    if (somaA > somaB)
        printf("Vencedor: País A \n");
    else if (somaA < somaB)
        printf("Vencedor: País B \n");
    else
        printf("Empate!\n");

    printf("=============================================\n");

    return 0;
}