/*Autor......: Gabriel Dalecio
  Data.......: 24/11/2024
  Equipe.....: RA10002691 - Gabriel Dalecio 1
               RA165808-2024 - Gabriel Ribeiro 2
  Objetivo...: Funcao para carregar as movi*/
#include "funcoes.h"
// Funcao para carregar Movi
void carregar_movi(tipolista_mov *m)
{
    FILE *ptr;
    char *nomearquivo = "movimentacoes.dat";
    char *modo_leitura = "rb"; 
    ptr = fopen(nomearquivo, modo_leitura);
    // Verifica se o arquivo foi aberto corretamente
    if (ptr == NULL)
    {
        printf("ERRO AO ABRIR O ARQUIVO PARA LEITURA\n");
        return;  
    }

    reg_movimentos contas;
    
   
    tipoApontador_mov p = m->primeiro;
    while (p != NULL)
    {
        tipoApontador_mov temp = p;
        p = p->proximo;
        free(temp);  
    }
    m->primeiro = NULL;
    m->ultimo = NULL;

    // Lê as movimentações do arquivo e insere-as na lista ligada
    while (fread(&contas, sizeof(reg_movimentos), 1, ptr) == 1)
    {
        tipoApontador_mov novo = (tipoApontador_mov)malloc(sizeof(tipoitem_mov));
        if (novo == NULL)
        {
            printf("ERRO AO ALLOCAR MEMÓRIA PARA NOVO ELEMENTO\n");
            fclose(ptr);
            return;
        }

        novo->conteudo = contas;
        novo->proximo = NULL;
        novo->anterior = NULL;

        // Se a lista estiver vazia, o novo nó se torna o primeiro e o último da lista
        if (m->primeiro == NULL)
        {
            m->primeiro = novo;
            m->ultimo = novo;  
        }
        else
        {
            novo->anterior = m->ultimo;
            m->ultimo->proximo = novo;
            m->ultimo = novo;
        }
    }

    fclose(ptr);  
}