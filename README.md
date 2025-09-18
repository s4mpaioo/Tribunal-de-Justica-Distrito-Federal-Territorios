# Projeto TJDFT – Manipulação de Arquivos em C

## Objetivo
Este projeto em linguagem C tem como objetivo manipular e analisar os dados da base **TJDFT_filtrado.csv**, fornecida em formato CSV (valores separados por `;`).  
O foco é implementar funções que permitam responder às questões propostas em aula, como:  
- Quantos processos estão presentes na base;  
- Obter informações específicas de um processo;  
- Identificar processos relacionados a determinados temas (violência doméstica, feminicídio, etc.);  
- Calcular métricas (diferença entre datas, percentual da Meta 1, etc.);  
- Exportar subconjuntos de dados (como os julgados na Meta 1).  

---

## Funcionalidades Implementadas
O projeto possui um conjunto de funções para manipulação e análise da base **TJDFT_filtrado.csv**:

- **Contagem de processos:** função que lê o arquivo linha a linha e retorna o número total de processos.
- **Busca por processo:** consulta pelo `id_processo` para obter informações como `id_ultimo_oj`.
- **Diferença entre datas:** calcula o número de dias entre `dt_recebimento` e `dt_resolvido`.
- **Estatísticas por caso:** conta processos relacionados a violência doméstica, feminicídio, causas ambientais, quilombolas e indígenas.
- **Meta 1:** cálculo do percentual de cumprimento da meta 1.
- **Exportação de CSV:** geração de um novo arquivo com todos os processos julgados (mérito) na Meta 1.

---

## Estrutura dos Dados
A base de dados está em formato **CSV** com campos separados por `;`.  
Os principais atributos de cada processo são:

- `id_processo` → Identificador único do processo  
- `dt_recebimento` → Data de início do processo  
- `dt_resolvido` → Data de resolução do processo (quando existente) 
- `id_ultimo_oj` → Último tribunal/órgão relacionado ao processo 
- Flags temáticas:  
  - `flag_violencia_domestica`  
  - `flag_feminicidio`  
  - `flag_ambiental`  
  - `flag_quilombolas`  
  - `flag_indigenas`
 
  ---
  
## Autoria 
 Desenvolvido por: 
 - Pedro Henrique Sampaio
 - Marina Albertim Lopes
 - Paulo Henrique Cabral
 - Paulo Vitor Macedo
 - Cauã Charles


