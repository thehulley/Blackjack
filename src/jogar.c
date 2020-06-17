#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

struct pontos
{
    int player_pontos, pc_pontos, rankig_pontos;
    int placar_player, placar_bot;
};

int naipes (int carta) {
    int i = 0;

    //SORTEIO DE NAIPES
    i = rand() % 3;
    if (i == 0)
    {
        printf ("█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█\n");
        if (carta == 10 || carta == 11)
        {
            printf ("█ %d            █\n", carta);
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
            printf ("█            %d █\n", carta);
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
            printf ("█ %d            █\n", carta);
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
            printf ("█            %d █\n", carta);
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
            printf ("█ %d            █\n", carta);
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
            printf ("█            %d █\n", carta);
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
            printf ("█ %d            █\n", carta);
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
            printf ("█            %d █\n", carta);
        }
        else
        {
            printf ("█             %d █\n", carta);
        }
        printf ("█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█\n\n");
    }
    system("sleep 01");

    return 0;
}


int main (void) {
    int baralho[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10}, carta;
    int rodada, escolha_as;
    char mais_uma;

    setlocale(LC_ALL, "pt-br");

    srand(time(NULL));

    struct pontos p; //CHAMA AS VARIÁVEIS DE PONTOS
    p.rankig_pontos = p.placar_bot = p.placar_player = 0;
    for (rodada = 0; rodada < 10; rodada++)
    {
        p.pc_pontos = 0;
        p.player_pontos = 0;
        printf("\n\n===================================================\n");
        printf("|                    RODADA %d                     |\n", rodada + 1);
        printf("|             Player [%d] x [%d] Bot                |\n", p.placar_player, p.placar_bot);
        printf("===================================================\n\n");
        //CARTAS DO PLAYER
        do
        {
            carta = baralho[rand() % 12];
            //CASO O ÁS SEJA SORTEADO
            if (carta == 1)
            {
                printf("Você tirou o ás!\n\n Escolha o valor [1] ou [11]: ");
                scanf(" %d", &escolha_as);

                while (escolha_as != 1 && escolha_as != 11)
                {
                    printf("\nEscolha inválida. Tente novamente!\n\n");
                    printf("Você tirou o ás!\n\n Escolha o valor [1] ou [11]: ");
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
                printf("\n\nA soma das cartas foi maior que 21! \n\n Você estorou! :(\n");
                break;
            }
            else
            {
                printf("\n\nVocê tirou a carta:\n\n");
                
                //IMPRIME AS CARTAS
                naipes(carta);

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

        printf("\n\n");
        //COÓDIGO DO PC
        while (p.player_pontos < 21)
        {

            //CARTAS DO PC
            carta = baralho[rand() % 12];
            if (carta == 1)
            {
                if (p.pc_pontos + 11 < 21)
                {
                    carta = 11;
                }
                else
                {
                    carta = 1;
                }
            }
                    printf("Eu tirei a carta:\n\n");

            //IMPRIME AS CARTAS
            naipes(carta);

            p.pc_pontos += carta;

            if (p.pc_pontos == 21)
            {
                printf("A soma dos pontos deu Vinte e Um. Ganhei!! :D\n");
                break;
            }
            else if (p.pc_pontos > 21)
            {
                printf("Estourei! Você venceu. :(\n");
                break;
            }
            else if (p.pc_pontos < 21 && p.pc_pontos > p.player_pontos)
            {
                printf("Fiz mais pontos que você. Venci!! :D");
                break;
            }
            
        }
        
        //PLCAR DA RODADA
        if (p.player_pontos > 21)
        {
            p.placar_bot++;
        }
        else if (p.pc_pontos > 21)
        {
            p.placar_player++;
        }
        else if (p.pc_pontos > p.player_pontos && p.pc_pontos <= 21)
        {
            p.placar_bot++;
        }
        else if (p.player_pontos > p.pc_pontos && p.player_pontos <= 21)
        {
            p.placar_player++;
        }
        
        //PONTOS PARA O RANKING
        if (p.player_pontos > p.pc_pontos && p.player_pontos == 21)
        {
            p.rankig_pontos += 5;
        }
        else if (p.player_pontos > p.pc_pontos && p.player_pontos == 20)
        {
            p.rankig_pontos += 4;
        }
        else if (p.player_pontos > p.pc_pontos && p.player_pontos == 19)
        {
            p.rankig_pontos += 3;
        }
        else if (p.player_pontos > p.pc_pontos && p.player_pontos == 18)
        {
            p.rankig_pontos += 2;
        }
        else if (p.player_pontos > p.pc_pontos && p.player_pontos <= 17)
        {
            p.rankig_pontos += 1;
        }
    }
    //INFORMA SE VENCEU A PARTIDA
    if (p.placar_player > p.placar_bot)
    {
        printf("Placar Final -> Player [%d] x Bot [%d]", p.placar_player, p.placar_bot);
        printf("\n\nParabéns, você venceu a partida!!\n\n");
    }
    else
    {
        printf("Placar Final -> Player [%d] x Bot [%d]", p.placar_player, p.placar_bot);
        printf("\n\nVocê perdeu a partida tente novamente.\n\n");
    }
    
    return 0;
}
