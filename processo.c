#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "processo.h"

int contarProcessos(char *nomeArquivo) {
    FILE *fp = fopen(nomeArquivo, "r");
    if (fp == NULL) {
        printf("Erro, nao foi possivel abrir o arquivo %s\n", nomeArquivo);
        return -1;
    }

    char linha[8192]; 
    int contador = 0;
    
    fgets(linha, sizeof(linha), fp);
    while (fgets(linha, sizeof(linha), fp) != NULL) {
        if (linha[0] == '\n' || linha[0] == '\r' || linha[0] == '\0')
            continue; 
        contador++;
    }

    fclose(fp);
    return contador;
    }

    int getUltimoOJ(char *nomeArquivo, char *id_processo_busca) {
    FILE *fp = fopen(nomeArquivo, "r");
    if (fp == NULL) {
        printf("Erro: nao foi possivel abrir o arquivo %s\n", nomeArquivo);
        return -1;
    }

    char linha[8192];
    fgets(linha, sizeof(linha), fp);
    while (fgets(linha, sizeof(linha), fp) != NULL) {
        char *campo;
        int col = 0;
        char id_processo[50];
        int id_ultimo_oj = -1;

        campo = strtok(linha, ";");
        while (campo != NULL) {
            if (col == 0) { 
                strcpy(id_processo, campo);
            }
            if (col == 8) { 
                id_ultimo_oj = atoi(campo);
            }
            campo = strtok(NULL, ";");
            col++;
        }
        if (strcmp(id_processo, id_processo_busca) == 0) {
            fclose(fp);
            return id_ultimo_oj;
        }
    }
    
    fclose(fp);
    return -1;
}
    void processoMaisAntigo(char *nomeArquivo, char *idMaisAntigo) {
    FILE *fp = fopen(nomeArquivo, "r");
    if (fp == NULL) {
        idMaisAntigo[0] = '\0';
        return;
    }

    char linha[8192];
    char dataMaisAntiga[20] = "9999-12-31";
    idMaisAntigo[0] = '\0';

    fgets(linha, sizeof(linha), fp); 
    while (fgets(linha, sizeof(linha), fp) != NULL) {
        char *campo;
        int coluna = 0;
        char id_processo[50] = "";
        char dt_recebimento[20] = "";

        campo = strtok(linha, ";");
        while (campo != NULL) {
            if (coluna == 0) strcpy(id_processo, campo);
            if (coluna == 9) strcpy(dt_recebimento, campo);
            campo = strtok(NULL, ";");
            coluna++;
        }

        if (strlen(dt_recebimento) > 0 && strcmp(dt_recebimento, dataMaisAntiga) < 0) {
            strcpy(dataMaisAntiga, dt_recebimento);
            strcpy(idMaisAntigo, id_processo);
        }
    }
    fclose(fp);
}

int violenciaDomestica(char *nomeArquivo) {
    FILE *fp = fopen(nomeArquivo, "r");
    if (fp == NULL) {
        return -1;
    }
    char linha[8192];
    int contador = 0;

    fgets(linha, sizeof(linha), fp); 
    while (fgets(linha, sizeof(linha), fp) != NULL) {
        char *campo;
        int coluna = 0;
        int flag = 0;

        campo = strtok(linha, ";");
        while (campo != NULL) {
            if (coluna == 11) { 
                flag = atoi(campo);
                break;
            }
            campo = strtok(NULL, ";");
            coluna++;
        }
        if (flag == 1) contador++;
    }

    fclose(fp);
    return contador;
}

int contarFeminicidio(char *nomeArquivo) {
    FILE *fp = fopen(nomeArquivo, "r");
    if (fp == NULL) {
        return -1;
    }
    char linha[8192];
    int contador = 0;

    fgets(linha, sizeof(linha), fp); 
    while (fgets(linha, sizeof(linha), fp) != NULL) {
        char *campo;
        int coluna = 0;
        int flag = 0;

        campo = strtok(linha, ";");
        while (campo != NULL) {
            if (coluna == 12) { 
                flag = atoi(campo);
                break;
            }
            campo = strtok(NULL, ";");
            coluna++;
        }
        if (flag == 1) contador++;
    }

    fclose(fp);
    return contador;
}

int contarAmbiental(char *nomeArquivo) {
    FILE *fp = fopen(nomeArquivo, "r");
    if (fp == NULL) {
        return -1;
    }
    char linha[8192];
    int contador = 0;

    fgets(linha, sizeof(linha), fp); 
    while (fgets(linha, sizeof(linha), fp) != NULL) {
        char *campo;
        int coluna = 0;
        int flag = 0;

        campo = strtok(linha, ";");
        while (campo != NULL) {
            if (coluna == 13) { 
                flag = atoi(campo);
                break;
            }
            campo = strtok(NULL, ";");
            coluna++;
        }
        if (flag == 1) contador++;
    }

    fclose(fp);
    return contador;
}

int contarQuilombolas(char *nomeArquivo) {
    FILE *fp = fopen(nomeArquivo, "r");
    if (fp == NULL) {
        return -1;
    }
    char linha[8192];
    int contador = 0;

    fgets(linha, sizeof(linha), fp); 
    while (fgets(linha, sizeof(linha), fp) != NULL) {
        char *campo;
        int coluna = 0;
        int flag = 0;

        campo = strtok(linha, ";");
        while (campo != NULL) {
            if (coluna == 14) { 
                flag = atoi(campo);
                break;
            }
            campo = strtok(NULL, ";");
            coluna++;
        }
        if (flag == 1) contador++;
    }

    fclose(fp);
    return contador;
}

int contarIndigenas(char *nomeArquivo) {
    FILE *fp = fopen(nomeArquivo, "r");
    if (fp == NULL) {
        return -1;
    }
    char linha[8192];
    int contador = 0;

    fgets(linha, sizeof(linha), fp); 
    while (fgets(linha, sizeof(linha), fp) != NULL) {
        char *campo;
        int coluna = 0;
        int flag = 0;

        campo = strtok(linha, ";");
        while (campo != NULL) {
            if (coluna == 15) {
                flag = atoi(campo);
                break;
            }
            campo = strtok(NULL, ";");
            coluna++;
        }

        if (flag == 1) contador++;
    }

    fclose(fp);
    return contador;
}

int calcularDias(char *nomeArquivo, char *id_processo_busca) {
    FILE *fp = fopen(nomeArquivo, "r");
    if (fp == NULL) {
        return -1;
    }
    char linha[8192];
    fgets(linha, sizeof(linha), fp); 

    while (fgets(linha, sizeof(linha), fp) != NULL) {
        char *campo;
        int coluna = 0;
        char id_processo[50] = "";
        char dt_recebimento[20] = "";
        char dt_resolvido[20] = "";

        campo = strtok(linha, ";");
        while (campo != NULL) {
            if (coluna == 0) strcpy(id_processo, campo);
            if (coluna == 9) strcpy(dt_recebimento, campo);
            if (coluna == 17) strcpy(dt_resolvido, campo);
            campo = strtok(NULL, ";");
            coluna++;
        }

        if (strcmp(id_processo, id_processo_busca) == 0) {
            if (strlen(dt_recebimento) < 10 || strlen(dt_resolvido) < 10) {
                fclose(fp);
                return -1; 
            }

            struct tm tm1 = {0}, tm2 = {0};

            sscanf(dt_recebimento, "%d-%d-%d", &tm1.tm_year, &tm1.tm_mon, &tm1.tm_mday);
            sscanf(dt_resolvido, "%d-%d-%d", &tm2.tm_year, &tm2.tm_mon, &tm2.tm_mday);

            tm1.tm_year -= 1900;
            tm2.tm_year -= 1900;
            tm1.tm_mon -= 1;
            tm2.tm_mon -= 1;

            time_t t1 = mktime(&tm1);
            time_t t2 = mktime(&tm2);

            double diff = difftime(t2, t1);
            fclose(fp);

            return (int)(diff / (60 * 60 * 24)); 
        }
    }

    fclose(fp);
    return -1; 
}

float percentualMeta1(char *nomeArquivo) {
    FILE *fp = fopen(nomeArquivo, "r");
    if (fp == NULL) {
         return -1.0f;
    } 

    char linha[8192];
    long total_cnm1 = 0;
    long total_primeira = 0;

    fgets(linha, sizeof(linha), fp); 

    while (fgets(linha, sizeof(linha), fp) != NULL) {
        char *campo;
        int coluna = 0;
        int cnm1 = 0;
        int primeirasent = 0;

        campo = strtok(linha, ";");
        while (campo != NULL) {
            if (coluna == 19) sscanf(campo, "%d", &cnm1);
            if (coluna == 20) sscanf(campo, "%d", &primeirasent);
            campo = strtok(NULL, ";");
            coluna++;
        }

        total_cnm1 += cnm1;
        total_primeira += primeirasent;
    }

    fclose(fp);

    if (total_cnm1 == 0) {
        return 0.0f;
    }
    return ((float) total_primeira / (float) total_cnm1) * 100.0f;
}

void gerarCSVJulgadosMeta1(char *arquivoEntrada, char *arquivoSaida) {
    FILE *in = fopen(arquivoEntrada, "r");
    if (in == NULL) {
        printf("Erro ao abrir %s\n", arquivoEntrada);
        return;
    }

    FILE *out = fopen(arquivoSaida, "w");
    if (out == NULL) {
        printf("Erro ao criar %s\n", arquivoSaida);
        fclose(in);
        return;
    }

    char linha[8192];
    int col, count = 0;

    if (fgets(linha, sizeof(linha), in) != NULL) {
        fputs(linha, out);
    }

    while (fgets(linha, sizeof(linha), in) != NULL) {
        char buf[8192];
        strncpy(buf, linha, sizeof(buf) - 1);
        buf[sizeof(buf) - 1] = '\0';

        char *campo = strtok(buf, ";");
        col = 0;
        int julgadom1 = 0;

        while (campo != NULL) {
            if (col == 25) { 
                julgadom1 = atoi(campo);
                break;
            }
            campo = strtok(NULL, ";");
            col++;
        }

        if (julgadom1 == 1) {
            fputs(linha, out);
            count++;
        }
    }

    fclose(in);
    fclose(out);

    printf("Arquivo %s gerado com %d processos julgados na Meta 1.\n", arquivoSaida, count);
}