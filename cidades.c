#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cidades.h"

// Função auxiliar para comparar cidades pelo campo Posicao
int compararCidades(const void *a, const void *b) {
    Cidade *cidadeA = (Cidade *)a;
    Cidade *cidadeB = (Cidade *)b;
    return cidadeA->Posicao - cidadeB->Posicao;
}

// Inicializa cidades no TAD Cidade
Estrada *getEstrada(const char *nomeArquivo) {
    FILE *arquivo = fopen("arquivo_teste01.txt", "r");
    if (arquivo == NULL) {
        return NULL;
    }

    Estrada *estrada = (Estrada *)malloc(sizeof(Estrada));
    if (estrada == NULL) {
        fclose(arquivo);
        return NULL;
    }

    fscanf(arquivo, "%d", &(estrada->T));
    fscanf(arquivo, "%d", &(estrada->N));

    estrada->C = (Cidade *)malloc(estrada->N * sizeof(Cidade));
    if (estrada->C == NULL) {
        fclose(arquivo);
        free(estrada);
        return NULL;
    }

    for (int i = 0; i < estrada->N; i++) {
        fscanf(arquivo, "%d %s", &(estrada->C[i].Posicao), estrada->C[i].Nome);
    }

    fclose(arquivo);

    // Ordena as cidades pela posição
    qsort(estrada->C, estrada->N, sizeof(Cidade), compararCidades);

    return estrada;
}

// Calcula e retorna a menor vizinhança
double calcularMenorVizinhanca(const char *nomeArquivo) {
    Estrada *estrada = getEstrada(nomeArquivo);
    if (estrada == NULL) {
        return -1.0;
    }

    double menorVizinhanca = estrada->T;  // Inicializa com o valor máximo possível

    for (int i = 1; i < estrada->N; i++) {
        double vizinhanca = (estrada->C[i].Posicao - estrada->C[i - 1].Posicao) / 2.0;
        if (vizinhanca < menorVizinhanca) {
            menorVizinhanca = vizinhanca;
        }
    }

    free(estrada->C);
    free(estrada);
    return menorVizinhanca;
}

// Retorna o nome da cidade com a menor vizinhança
char *cidadeMenorVizinhanca(const char *nomeArquivo) {
    Estrada *estrada = getEstrada(nomeArquivo);
    if (estrada == NULL) {
        return NULL;
    }

    double menorVizinhanca = estrada->T;  // Inicializa com o valor máximo possível
    int indiceMenorVizinhanca = -1;

    for (int i = 1; i < estrada->N; i++) {
        double vizinhanca = (estrada->C[i].Posicao - estrada->C[i - 1].Posicao) / 2.0;
        if (vizinhanca < menorVizinhanca) {
            menorVizinhanca = vizinhanca;
            indiceMenorVizinhanca = i;
        }
    }

    char *cidade = (char *)malloc(256 * sizeof(char));
    if (cidade == NULL) {
        free(estrada->C);
        free(estrada);
        return NULL;
    }

    strcpy(cidade, estrada->C[indiceMenorVizinhanca].Nome);

    free(estrada->C);
    free(estrada);
    return cidade;
}
