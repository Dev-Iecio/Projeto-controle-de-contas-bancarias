#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <string.h>

#include "funcoes.h"

//Funçao para colocar as coordenadas onde o mouse ira
void vaiparaxy(int x, int y)
{
    COORD cord;
    cord.X = (short)x;
    cord.Y = (short)y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cord);
}

int main()
{
    int opc;
    tipolista_conta l;
    l.primeiro = NULL;
    l.ultimo = NULL;
    carregar(&l);
    
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
            menu_contas_bancarias(&l);

            break;
        case 2:
            
            break;
        }
    } while (opc != 3);
    gravar(&l);
    return 0;
}