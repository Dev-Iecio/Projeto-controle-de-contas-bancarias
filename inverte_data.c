/*Autor......: Gabriel Ribeiro
  Data.......: 24/11/2024
  Equipe.....: RA10002691 - Gabriel Dalecio 1
               RA165808-2024 - Gabriel Ribeiro 2
  Objetivo...: Funçao de inverter data */
  
#include "funcoes.h"


// Funcao inverter data
char *inverte_data(char *dt_data) {
    static char dt_data_inv[11];  // Declara um vetor estático para armazenar a data invertida (ano-mês-dia)
    char dia[3], mes[3], ano[5];  // Vetores para armazenar o dia, mês e ano da data original

    // Copia os primeiros 2 caracteres de dt_data (dia) para a variável dia
    strncpy(dia, dt_data, 2); 
    dia[2] = '\0';   // Adiciona o caractere nulo no final para garantir que ano seja uma string válida

    // Copia os caracteres de posição 3 e 4 de dt_data (mês) para a variável mes
    strncpy(mes, dt_data + 3, 2);  
    mes[2] = '\0';  // Adiciona o caractere nulo no final para garantir que ano seja uma string válida

    // Copia os caracteres de posição 6 a 9 de dt_data (ano) para a variável ano
    strncpy(ano, dt_data + 6, 4);  
    ano[4] = '\0'; // Adiciona o caractere nulo no final para garantir que ano seja uma string válida 

    // Formata a nova data no formato "ano-mês-dia" e armazena em dt_data_inv
    sprintf(dt_data_inv, "%s-%s-%s", ano, mes, dia);

    // Retorna o ponteiro para o array com a data invertida
    return dt_data_inv;  
}

