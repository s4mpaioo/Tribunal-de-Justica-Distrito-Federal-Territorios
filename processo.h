#ifndef PROCESSO_H
#define PROCESSO_H

typedef struct {
    char id_processo[50];
    char numero_sigilo[50];
    char sigla_grau[10];
    char procedimento[100];
    char ramo_justica[50];
    char sigla_tribunal[10];
    int id_tribunal;
    int recurso;
    int id_ultimo_oj;
    char dt_recebimento[20];
    int id_ultima_classe;
    int flag_violencia_domestica;
    int flag_feminicidio;
    int flag_ambiental;
    int flag_quilombolas;
    int flag_indigenas;
    int flag_infancia;
    char decisao[100];
    char dt_resolvido[20];
    int cnm1;
    int primeirasentm1;
    int baixm1;
    int decm1;
    int mpum1;
    int julgadom1;
    int desm1;
    int susm1;

} Processo;

int contarProcessos(char *nomeArquivo);
int getUltimoOJ(char *nomeArquivo, char *id_processo);
void processoMaisAntigo(char *nomeArquivo, char *idMaisAntigo);
int violenciaDomestica(char *nomeArquivo);
int contarFeminicidio(char *nomeArquivo);
int contarAmbiental(char *nomeArquivo);
int contarQuilombolas(char *nomeArquivo);
int contarIndigenas(char *nomeArquivo);
int calcularDias(char *nomeArquivo, char *id_processo_busca);
float percentualMeta1(char *nomeArquivo);
void gerarCSVJulgadosMeta1(char *arquivoEntrada, char *arquivoSaida);


#endif
