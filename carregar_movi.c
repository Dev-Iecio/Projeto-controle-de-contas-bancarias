#include "funcoes.h"
void carregar_movi(tipolista_mov *m)
{
    FILE *ptr;
    char *nomearquivo = "movimentacoes.dat";
    char *modo_leitura = "rb"; 
    ptr = fopen(nomearquivo, modo_leitura);

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