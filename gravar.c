/*Autor......: Gabriel Dalecio
  Data.......: 24/11/2024
  Equipe.....: RA10002691 - Gabriel Dalecio 1
               RA165808-2024 - Gabriel Ribeiro 2
  Objetivo...: Gravar */
#include "funcoes.h"
// Funcao para gravar
void gravar(tipolista_conta *l)
{
    // Exibe uma tela informando que os cadastros e movimentações foram gravados
    tela();
    vaiparaxy(07,23);
    printf("Cadastros e movimentacoes foram gravados");
    getch();
    
   
    FILE *ptr;
    char *nomearquivo = "contas.dat";
    char *modo_gravacao = "wb";  

    // Abre o arquivo para gravação em modo binário ("wb")
    ptr = fopen(nomearquivo, modo_gravacao);
    // Verifica se houve erro ao abrir o arquivo
    if (ptr == NULL)
    {
        printf("Erro ao abrir o arquivo para gravação\n");
        exit(1);  
    }

    // Ponteiro para percorrer a lista de contas
    tipoApontador_conta p = l->primeiro;

    
    while (p != NULL)
    {   
        // Escreve os dados da conta no arquivo
        fwrite(&p->conteudo, sizeof(reg_contas), 1, ptr);  
        p = p->proximo;  
    }

    fclose(ptr); 
}