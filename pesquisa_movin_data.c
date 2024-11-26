/*Autor......: Gabriel Dalecio
  Data.......: 24/11/2024
  Equipe.....: RA10002691 - Gabriel Dalecio 1
               RA165808-2024 - Gabriel Ribeiro 2
  Objetivo...: Pesquisa de movimentaçoes */
#include "funcoes.h"
// Função que pesquisa a data do movimento para um código de conta específico
char *pesquisa_movin_data(tipolista_mov *m, int cod)
{

    tipoApontador_mov aux;
    aux = m->primeiro;
    char *dt_movi = malloc(sizeof(char) * 11);
    strcpy(dt_movi, "");
    // Enquanto não atingir o fim da lista de movimentos
    while (aux != NULL)
    {   // Se o código da conta do movimento atual for igual ao código procurado
        if (aux->conteudo.codigo_conta == cod)
        {
            strcpy(dt_movi, aux->conteudo.dt_movimento);
        }
        aux = aux->proximo;
    }
    
    //inverte_data(dt_movi);
    
    return dt_movi;
}

// Função que conta o número de movimentos de um código de conta específico
int conta_movi(tipolista_mov *m, int cod)
{
    char *data;
    tipoApontador_mov aux;
    int contador = 0;
    aux = m->primeiro;
    // Enquanto não atingir o fim da lista de movimentos
    while (aux != NULL)
    {
        // Se o código da conta do movimento atual for igual ao código procurado
        if (aux->conteudo.codigo_conta == cod)
        {
            contador++;
        }
        aux = aux->proximo;
    }

    return contador;
}

/*int verifica_maior_data(char *data1, char *data2)
{
    int dia1, mes1, ano1;
    int dia2, mes2, ano2;

    // Extrair dia, mês e ano das duas datas
    sscanf(data1, "%2d/%2d/%4d", &dia1, &mes1, &ano1);
    sscanf(data2, "%2d/%2d/%4d", &dia2, &mes2, &ano2);

    // Comparar ano, mês e dia
    if (ano1 > ano2)
    {
        return 1; // data1 é maior
    }
    else if (ano1 < ano2)
    {
        return 0; // data2 é maior
    }
    else
    {
        if (mes1 > mes2)
        {
            return 1; // data1 é maior
        }
        else if (mes1 < mes2)
        {
            return 0; // data2 é maior
        }
        else
        {
            if (dia1 > dia2)
            {
                return 1; // data1 é maior
            }
            else if (dia1 < dia2)
            {
                return 0; // data2 é maior
            }
            else
            {
                return -1; // As datas são iguais
            }
        }
    }
}*/
