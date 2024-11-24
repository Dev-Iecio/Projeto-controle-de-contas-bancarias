#include "funcoes.h"



char *le_movi(int col, int lin)
{
    char *dt_movi = malloc(sizeof(char) * 15);
    int valid;

    // Verificar se a alocação de memória foi bem-sucedida
    if (dt_movi == NULL)
    {
        // Caso falhe, retorna NULL
        return NULL;
    }

    do
    {
        valid = 1;
        vaiparaxy(07, 23);  // Posiciona o cursor na linha 7, coluna 23
        printf("Data da Movimentacao (dd/mm/yyyy): ");
        vaiparaxy(col, lin);  // Posiciona o cursor onde o usuário vai digitar
        printf("                                ");  // Limpa a linha

        // Move o cursor para o ponto de entrada da data
        vaiparaxy(col, lin);
        fflush(stdin);  // Limpa o buffer de entrada
        fgets(dt_movi, 11, stdin);  // Lê até 10 caracteres

        // Limpa o caractere de nova linha (\n) que o fgets pode adicionar
        dt_movi[strcspn(dt_movi, "\n")] = 0;

        limpa_msg();  // Limpa mensagens anteriores, se houver

        // Verificação básica do formato (dd/mm/yyyy)
        if (strlen(dt_movi) != 10 || dt_movi[2] != '/' || dt_movi[5] != '/')
        {
            valid = 0;
        }
        else
        {
            dt_movi[2] = '\0';  // Separa o dia, mês e ano
            dt_movi[5] = '\0';
            int dia = atoi(dt_movi);
            int mes = atoi(dt_movi + 3);
            int ano = atoi(dt_movi + 6);

            // Verifica se o dia, mês e ano são válidos
            if (dia < 1 || dia > 31 || mes < 1 || mes > 12 || ano < 2024 || ano > 2100)
            {
                valid = 0;
            }
            else
            {
                // Valida os dias nos meses (levando em conta os meses com 30 dias)
                if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30)
                    valid = 0;
                else if (mes == 2 && dia > 29)  // Valida o mês de fevereiro
                    valid = 0;
                else if (mes == 2 && dia == 29 && !(ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0)))  // Verifica ano bissexto
                    valid = 0;
            }

            dt_movi[2] = '/';  // Restaura as barras
            dt_movi[5] = '/';
        }

        // Se a data for inválida, exibe a mensagem de erro
        if (!valid)
        {
            vaiparaxy(07, 23);  // Posiciona o cursor
            printf("Data da Movimentacao invalida. Formato: dd/mm/yyyy");
            getch();  // Espera o usuário pressionar uma tecla
            limpa_msg();  // Limpa a mensagem
        }

    } while (!valid);  // Repete até que a data seja válida

    return dt_movi;  // Retorna a data válida
}

