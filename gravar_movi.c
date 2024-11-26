/*Autor......: Gabriel Dalecio
  Data.......: 24/11/2024
  Equipe.....: RA10002691 - Gabriel Dalecio 1
               RA165808-2024 - Gabriel Ribeiro 2
  Objetivo...: Gravar movimentacoes */
#include "funcoes.h"
// Funcao para gravar movimentacoes
void gravar_movi(tipolista_mov *m)
{
   
    FILE *ptr;
    char *nomearquivo = "movimentacoes.dat";
    char *modo_gravacao = "wb";  

    // Abre o arquivo para gravação em modo binário ("wb")
    ptr = fopen(nomearquivo, modo_gravacao);
    // Verifica se houve erro ao abrir o arquivo
    if (ptr == NULL)
    {
        printf("Erro ao abrir o arquivo para gravação\n");
        exit(1);  
    }

    // Ponteiro para percorrer a lista de movimentações
    tipoApontador_mov p = m->primeiro;

    // Percorre a lista de movimentações e grava cada movimentação no arquivo
    while (p != NULL)
    {
        // Escreve os dados da movimentação no arquivo
        fwrite(&p->conteudo, sizeof(reg_movimentos), 1, ptr);  
        p = p->proximo;  
    }

    fclose(ptr); 
}