#include "funcoes.h"

void gravar(tipolista_conta *l)
{
   
    FILE *ptr;
    char *nomearquivo = "contas.dat";
    char *modo_gravacao = "wb";  

    
    ptr = fopen(nomearquivo, modo_gravacao);

    if (ptr == NULL)
    {
        printf("Erro ao abrir o arquivo para gravação\n");
        exit(1);  
    }

    
    tipoApontador_conta p = l->primeiro;

    
    while (p != NULL)
    {
        fwrite(&p->conteudo, sizeof(reg_contas), 1, ptr);  
        p = p->proximo;  
    }

    fclose(ptr); 
}