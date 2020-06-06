#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct pontos
{
    int player_pontos, pc_pontos;
};

int main (void) {
    int baralho[4][13], preenchimento[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10}, carta;
    int i, j, escolha_as;
    char mais_uma, n[2];

    srand(time(NULL));
    struct pontos p; //CHAMA AS VARIÁVEIS DE PONTOS
    p.player_pontos = 0;
    //CARTAS DO PLAYER
    
    for (i=0 ; i<4 ; i++)
    {
      for (j=0 ; j<13 ; j++) 
      {
        baralho[i][j] = preenchimento[j];
      }
    }
    
    do
    {
        i = rand() % 4;
        j = rand() % 13;

        while (baralho[i][j] == 0)
        {
            i = rand() % 4;
            j = rand() % 13;
        }

        carta = baralho[i][j];
        baralho[i][j] = 0;

        //CASO O ÁS SEJA SORTEADO
        if (carta == 1)
        {
            printf("Escolha o valor [1] ou [11]:");
            scanf(" %d", &escolha_as);

            while (escolha_as != 1 && escolha_as != 11)
            {
                printf("Escolha inválida. Tente novamente!\n");
                printf("Escolha o valor [1] ou [11]:");
                scanf(" %s", n);

                escolha_as = atoi(n);  //TRANSFORMAR A STRING EM INTEIRO
            }

            if (escolha_as == 1 || escolha_as == 11)
            {
                carta = escolha_as;
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
            printf("\n\nVocê possui %d pontos.\n\n", p.player_pontos);
            printf("Quer mais uma carta? [S/N] ");
            scanf(" %c", &mais_uma);

            while (mais_uma != 'S' && mais_uma != 's' && mais_uma != 'N' && mais_uma != 'n')
            {
                printf("Resposta inválida. Tente novamente!\n");
                printf("Quer mais uma carta? [S/N] ");
                scanf(" %c", &mais_uma);
            }  

            if ((mais_uma == 'N' || mais_uma == 'n') && (p.player_pontos < 17))
            {
                printf ("\nVocê não pode parar enquanto seus pontos forem menores que 17\n\n");
                mais_uma = 'S';
            }  
        }   
    } while (mais_uma == 'S' || mais_uma == 's');

    system("pause");
    return 0;
}
