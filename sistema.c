/*Autor......: Gabriel Ribeiro
  Data.......: 24/11/2024
  Equipe.....: RA10002691 - Gabriel Dalecio 1
               RA165808-2024 - Gabriel Ribeiro 2
  Objetivo...: Tela Principal */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <string.h>

#include "funcoes.h"

void vaiparaxy(int x, int y)
{
    COORD cord;
    cord.X = (short)x;
    cord.Y = (short)y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cord);
}

int main()
{
    int opc;            // Variável para armazenar a opção do menu
    tipolista_conta l;  // Lista de contas bancárias
    l.primeiro = NULL;  // Inicializa a lista de contas com NULL        
    l.ultimo = NULL;
    carregar(&l);       // Carrega os dados de contas (provavelmente de um arquivo ou banco de dados)
    tipolista_mov m;    // Lista de movimentações bancárias
    m.primeiro = NULL;  // Inicializa a lista de movimentações com NULL
    m.ultimo = NULL;
    carregar_movi(&m);  // Carrega os dados das movimentações
    
    do
    {
        tela();
        vaiparaxy(35, 3);
        printf("||  MENU PRINCIPAL");
        vaiparaxy(30, 12);
        printf("(1) Contas Bancarias");
        vaiparaxy(30, 14);
        printf("(2) Movimentacao Bancaria");
        vaiparaxy(30, 16);
        printf("(3) Sair");

        

        vaiparaxy(07, 23);
        printf("Digite sua opcao: ");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            menu_contas_bancarias(&l,&m);

            break;
        case 2:
            menu_movimentacao(&l,&m);
            break;
        }
    } while (opc != 3);
    gravar(&l);
    gravar_movi(&m);
    return 0;
}