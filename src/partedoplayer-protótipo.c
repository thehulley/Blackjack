#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

struct pontos
{
    int player_pontos, pc_pontos;
};


int main (void) {
    int baralho[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10}, carta;
    int i, escolha_as;
    char mais_uma, naipe;

    setlocale(LC_ALL, "pt-br");

    srand(time(NULL));
    struct pontos p; //CHAMA AS VARIÁVEIS DE PONTOS
    p.player_pontos = 0;
    //CARTAS DO PLAYER
    do
    {
        carta = baralho[rand() % 12];
        //CASO O ÁS SEJA SORTEADO
        if (carta == 1)
        {
            printf("Escolha o valor [1] ou [11]:");
            scanf(" %d", &escolha_as);

            while (escolha_as != 1 && escolha_as != 11)
            {
                printf("Escolha inválida. Tente novamente!\n");
                printf("Escolha o valor [1] ou [11]:");
                scanf(" %d", &escolha_as);
            }

            if (escolha_as == 1)
            {
                carta = 1;
            }
            else if (escolha_as == 11)
            {
                carta = 11;
            }  
        }
        p.player_pontos += carta;

        if (p.player_pontos == 21)
        {
            printf("Vinte e UM!! Você venceu a rodada!!\n");
            break;
        }
        else if (p.player_pontos > 21)
        {
            printf("Você estorou! :(\n");
            break;
        }
        else
        {
            printf("\n\nVocê tirou a carta:\n\n");
            //SORTEIO DE NAIPES
            i = rand() % 3;
            if (i == 0)
            {
                printf ("█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█\n");
                if (carta == 10 || carta == 11)
                {
                    printf ("█ 10            █\n");
                }
                else
                {
                    printf ("█ %d             █\n", carta);
                }
                printf ("█ ♠             █\n");
                printf ("█               █\n");
                printf ("█               █\n");
                printf ("█               █\n");
                printf ("█               █\n");
                printf ("█               █\n");
                printf ("█             ♠ █\n");
                if (carta == 10 || carta == 11)
                {
                    printf ("█            10 █\n");
                }
                else
                {
                    printf ("█             %d █\n", carta);
                }
                printf ("█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█\n\n");
            }
            else if (i == 1)
            {
                printf ("█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█\n");
                if (carta == 10 || carta == 11)
                {
                    printf ("█ 10            █\n");
                }
                else
                {
                    printf ("█ %d             █\n", carta);
                }
                printf ("█ ♣             █\n");
                printf ("█               █\n");
                printf ("█               █\n");
                printf ("█               █\n");
                printf ("█               █\n");
                printf ("█               █\n");
                printf ("█             ♣ █\n");
                if (carta == 10 || carta == 11)
                {
                    printf ("█            10 █\n");
                }
                else
                {
                    printf ("█             %d █\n", carta);
                }
                printf ("█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█\n\n");
            }
            else if (i == 2)
            {
                printf ("█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█\n");
                if (carta == 10 || carta == 11)
                {
                    printf ("█ 10            █\n");
                }
                else
                {
                    printf ("█ %d             █\n", carta);
                }
                printf ("█ ♥             █\n");
                printf ("█               █\n");
                printf ("█               █\n");
                printf ("█               █\n");
                printf ("█               █\n");
                printf ("█               █\n");
                printf ("█             ♥ █\n");
                if (carta == 10 || carta == 11)
                {
                    printf ("█            10 █\n");
                }
                else
                {
                    printf ("█             %d █\n", carta);
                }
                printf ("█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█\n\n");
            }
            else if (i == 3)
            {
                printf ("█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█\n");
                if (carta == 10 || carta == 11)
                {
                    printf ("█ 10            █\n");
                }
                else
                {
                    printf ("█ %d             █\n", carta);
                }
                printf ("█ ♦             █\n");
                printf ("█               █\n");
                printf ("█               █\n");
                printf ("█               █\n");
                printf ("█               █\n");
                printf ("█               █\n");
                printf ("█             ♦ █\n");
                if (carta == 10 || carta == 11)
                {
                    printf ("█            10 █\n");
                }
                else
                {
                    printf ("█             %d █\n", carta);
                }
                printf ("█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█\n\n");
            }
            //VERIFICA SE VAI HAVER UMA CONTINUIDADE
            printf("Quer mais uma carta? [S/N] ");
            scanf(" %c", &mais_uma);
            while (mais_uma != 'S' && mais_uma != 's' && mais_uma != 'N' && mais_uma != 'n')
            {
                printf("Resposta inválida. Tente novamente!\n");
                printf("Quer mais uma carta? [S/N] ");
                scanf(" %c", &mais_uma);
            }    
        }   
    } while (mais_uma == 'S' || mais_uma == 's');

    //COÓDIGO DO PC
    if (p.player_pontos < 21)
    {
        do
        {
            carta = baralho[rand() %12];
            i = rand() % 3;
            if (i == 0)
            {
                printf ("█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█\n");
                if (carta == 10 || carta == 11)
                {
                    printf ("█ 10            █\n");
                }
                else
                {
                    printf ("█ %d             █\n", carta);
                }
                printf ("█ ♠             █\n");
                printf ("█               █\n");
                printf ("█               █\n");
                printf ("█               █\n");
                printf ("█               █\n");
                printf ("█               █\n");
                printf ("█             ♠ █\n");
                if (carta == 10 || carta == 11)
                {
                    printf ("█            10 █\n");
                }
                else
                {
                    printf ("█             %d █\n", carta);
                }
                printf ("█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█\n\n");
            }
            else if (i == 1)
            {
                printf ("█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█\n");
                if (carta == 10 || carta == 11)
                {
                    printf ("█ 10            █\n");
                }
                else
                {
                    printf ("█ %d             █\n", carta);
                }
                printf ("█ ♣             █\n");
                printf ("█               █\n");
                printf ("█               █\n");
                printf ("█               █\n");
                printf ("█               █\n");
                printf ("█               █\n");
                printf ("█             ♣ █\n");
                if (carta == 10 || carta == 11)
                {
                    printf ("█            10 █\n");
                }
                else
                {
                    printf ("█             %d █\n", carta);
                }
                printf ("█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█\n\n");
            }
            else if (i == 2)
            {
                printf ("█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█\n");
                if (carta == 10 || carta == 11)
                {
                    printf ("█ 10            █\n");
                }
                else
                {
                    printf ("█ %d             █\n", carta);
                }
                printf ("█ ♥             █\n");
                printf ("█               █\n");
                printf ("█               █\n");
                printf ("█               █\n");
                printf ("█               █\n");
                printf ("█               █\n");
                printf ("█             ♥ █\n");
                if (carta == 10 || carta == 11)
                {
                    printf ("█            10 █\n");
                }
                else
                {
                    printf ("█             %d █\n", carta);
                }
                printf ("█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█\n\n");
            }
            else if (i == 3)
            {
                printf ("█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█\n");
                if (carta == 10 || carta == 11)
                {
                    printf ("█ 10            █\n");
                }
                else
                {
                    printf ("█ %d             █\n", carta);
                }
                printf ("█ ♦             █\n");
                printf ("█               █\n");
                printf ("█               █\n");
                printf ("█               █\n");
                printf ("█               █\n");
                printf ("█               █\n");
                printf ("█             ♦ █\n");
                if (carta == 10 || carta == 11)
                {
                    printf ("█            10 █\n");
                }
                else
                {
                    printf ("█             %d █\n", carta);
                }
                printf ("█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█\n\n");
                p.pc_pontos += carta;
                if (p.pc_pontos == 21)
                {
                    printf("21 Você Perdeu!! Ha Ha.\n");
                    break;
                }
                if (p.pc_pontos > 21)
                {
                    printf("Estourei, você ganhou a rodada. :(\n");
                }
                
            }
        } while (p.pc_pontos < 21);
    }
    
    system("pause");
    return 0;
}