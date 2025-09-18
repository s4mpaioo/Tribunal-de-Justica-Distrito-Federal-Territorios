#include <stdio.h>
#include <stdlib.h>
#include "processo.h"

int main() {
    char arquivo[] = "TJDFT_filtrado.csv";

    int total = contarProcessos("TJDFT_filtrado.csv");

    if (total >= 0) {
        printf("Numero total de processos encontrados: %d\n", total);
    }

    char codigo[50];
    printf("Digite o id_processo para buscar o id_ultimo_oj: ");
    scanf("%s", codigo);

    int idOJ = getUltimoOJ(arquivo, codigo);
    if (idOJ != -1) {
        printf("O ultimo Orgao Julgador do processo %s eh %d\n", codigo, idOJ);
    } else {
        printf("Processo %s nao encontrado\n", codigo);
    }

    char idAntigo[50];
    processoMaisAntigo(arquivo, idAntigo);
    if (idAntigo[0] != '\0')
        printf("Processo mais antigo: %s\n", idAntigo);
    else
        printf("Nenhum processo com data encontrada.\n");

    int qtdVD = violenciaDomestica(arquivo);
        if (qtdVD >= 0)
            printf("Processos relacionados a violencia domestica: %d\n", qtdVD);
        else
            printf("Erro ao abrir o arquivo para contar violencia domestica\n");

    int qtdFem = contarFeminicidio(arquivo);
    if (qtdFem >= 0)
        printf("Processos relacionados a feminicidio: %d\n", qtdFem);
    else
        printf("Erro ao abrir o arquivo para contar feminicidio.\n");

    int qtdAmb = contarAmbiental(arquivo);
    if (qtdAmb >= 0)
        printf("Processos relacionados a causas ambientais: %d\n", qtdAmb);
    else
        printf("Erro ao abrir o arquivo para contar causas ambientais.\n");

    int qtdQuil = contarQuilombolas(arquivo);
    if (qtdQuil >= 0)
        printf("Processos relacionados a causas quilombolas: %d\n", qtdQuil);
    else
        printf("Erro ao abrir o arquivo para contar causas quilombolas.\n");
    
    int qtdInd = contarIndigenas(arquivo);
    if (qtdInd >= 0)
        printf("Processos relacionados a causas indigenas: %d\n", qtdInd);
    else
        printf("Erro ao abrir o arquivo para contar causas indigenas.\n");
    
    char codigo2[50];
    printf("Digite o id processo para calcular dias entre data de recebimento e data resolvido: ");
    scanf("%s", codigo2);
    int dias = calcularDias(arquivo, codigo2);
    if (dias >= 0)
        printf("Diferença entre datas: %d dias\n", dias);
    else if (dias == -2)
        printf("Processo encontrado mas sem data resolvida\n");
    else
        printf("Nao foi possivel calcular, processo nao encontrado ou datas ausentes.\n");

    float pct = percentualMeta1(arquivo);
    printf("Percentual de cumprimento da Meta 1: %.2f%%\n", pct);

    gerarCSVJulgadosMeta1("TJDFT_filtrado.csv", "processos_julgados_meta1.csv");

    return 0;
}

