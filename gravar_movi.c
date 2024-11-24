#include "funcoes.h"

void gravar_movi(tipolista_mov *m)
{
   
    FILE *ptr;
    char *nomearquivo = "movimentacoes.dat";
    char *modo_gravacao = "wb";  

    
    ptr = fopen(nomearquivo, modo_gravacao);

    if (ptr == NULL)
    {
        printf("Erro ao abrir o arquivo para gravação\n");
        exit(1);  
    }

    
    tipoApontador_mov p = m->primeiro;

    
    while (p != NULL)
    {
        fwrite(&p->conteudo, sizeof(reg_movimentos), 1, ptr);  
        p = p->proximo;  
    }

    fclose(ptr); 
}