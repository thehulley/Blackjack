#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>


/*
    Preview em https://repl.it/@hulley/main-blackjack#main.c
*/


char *mat[5][2];

struct pontos
{
    int player_pontos, pc_pontos, rankig_pontos;
    int placar_player, placar_bot;
};


int regras() // FUNÇÃO PARA NÃO POLUIR O CÓDIGO PRINCIPAL
{
    printf ("█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█\n");
    printf ("█                                                                             █\n");
    printf ("█                               -=-[ Regras ]-=-                              █\n");
    printf ("█                                                                             █\n");
    printf ("█                                                                             █\n");
    printf ("█  Pontuação das cartas:                                                      █\n");
    printf ("█                                                                             █\n");
    printf ("█  Ás → 1 ou 11 pontos (usuário decide);                                      █\n");
    printf ("█  Valete, rainha, rei → 10 pontos;                                           █\n");
    printf ("█  Números de 2 a 10 → valor indicado nas cartas;                             █\n");
    printf ("█                                                                             █\n");
    printf ("█                                                                             █\n");
    printf ("█  O Jogo:                                                                    █\n");
    printf ("█                                                                             █\n");
    printf ("█  O computador irá distribuir cartas aleatórias. O jogador poderá pedir uma  █\n");
    printf ("█  carta enquanto a soma da pontuação das cartas na sua mão é menor ou igual  █\n");
    printf ("█  a 21. Caso o jogador tenha uma pontuação menor que 21 e maior ou igual a   █\n");
    printf ("█  17 ele poderá passar a vez, com isso o computador terá a chance de bater   █\n");
    printf ("█  o adversário. Se o jogador tiver uma pontuação de cartas maior que 21 ele  █\n");
    printf ("█  perde. O jogo terá pontuação por rodada, sendo uma melhor de 10 (quem      █\n");
    printf ("█  atingir 10 primeiro, ganha).                                               █\n");
    printf ("█                                                                             █\n");
    printf ("█                                                                             █\n");
    printf ("█  Ranking e pontuação por rodada:                                            █\n");
    printf ("█                                                                             █\n");
    printf ("█  Se ocorrer do jogador perder (e o mesmo tenha pontuação suficiente para    █\n");
    printf ("█  entrar no ranking), o seu nome juntamente com sua pontuação total serão    █\n");
    printf ("█  adicionadas ao ranking inicial (apresentada no menu), sendo que a          █\n");
    printf ("█  classificação será baseada na pontuação total do jogador.                  █\n");
    printf ("█  Caso o jogador ganhe será adicionada a sua pontuação total uma pontuação   █\n");
    printf ("█  X que será definida com base em uma das situações citadas abaixo.          █\n");
    printf ("█                                                                             █\n");
    printf ("█  ● 1 ponto – Se o jogador tiver um total de cartas somadas totalizando 17.  █\n");
    printf ("█  ● 2 ponto – Se o jogador tiver um total de cartas somadas totalizando 18.  █\n");
    printf ("█  ● 3 ponto – Se o jogador tiver um total de cartas somadas totalizando 19.  █\n");
    printf ("█  ● 4 ponto – Se o jogador tiver um total de cartas somadas totalizando 20.  █\n");
    printf ("█  ● 5 ponto – Se o jogador tiver um total de cartas somadas totalizando 21.  █\n");
    printf ("█                                                                             █\n");
    printf ("█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█\n");

    return 0;
}


int ranking_ler(){

    int c, i;
    char ranking[78], *aux[5][1], *matriz[5][2];
    char* token;

    FILE *fl;
    fl = fopen("ranking.txt", "r");
      for (i = 0; (c = fgetc(fl))!= EOF; i++){
          ranking[i] = c;
      }
    fclose(fl);

    i = 0;

    token = strtok(ranking, "|");
    while (token != NULL) {
        token = strtok(NULL, "|");
        aux[i][0] = token;

        i += 1;
    }

    for (c=0; c<5; c++){
      
        i=0;
        token = strtok(aux[c][0], "-");

        while (token != NULL) {
            token = strtok(NULL, "-");
            matriz[c][i] = token;
            i += 1;
        }
    }
    
    printf ("\n");

    for (c=0; c<5; c++){
        for (i=0; i<2; i++){
            mat[c][i] = matriz[c][i];
        }
    }

    //IMPRIME O RANKING

    printf ("█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█\n");
    printf ("█                                                                             █\n");
    printf ("█                              -=-[ Ranking ]-=-                              █\n");
    printf ("█                                                                             █\n");
    printf ("█                                Pontos | Nome                                █\n");
    printf ("█                                                                             █\n");

    // PRIMEIRO

    printf ("█        1 - ");

    for (i=0; i<2; i++){
        printf("%s ", matriz[0][i]);
    }
    
    printf ("                                                       █\n");

    // SEGUNDO 

    printf ("█        2 - ");

    for (i=0; i<2; i++){
        printf("%s ", matriz[1][i]);
    }
    
    printf ("                                                       █\n");

    // TERCEIRO

    printf ("█        3 - ");

    for (i=0; i<2; i++){
        printf("%s ", matriz[2][i]);
    }
    
    printf ("                                                       █\n");

    // QUARTO

    printf ("█        4 - ");

    for (i=0; i<2; i++){
        printf("%s ", matriz[3][i]);
    }
    
    printf ("                                                       █\n");

    // QUINTO

    printf ("█        5 - ");

    for (i=0; i<2; i++){
        printf("%s ", matriz[4][i]);
    }
    
    printf ("                                                       █\n");


    printf ("█                                                                             █\n");
    printf ("█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█\n");

    return 0;
}


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


int main(void) // FUNÇÃO PRINCIPAL
{
    int escolha_menu, sair_outros_menus, i, pontos;
    int baralho[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10}, carta, rodada, escolha_as;
    char n[2], c, mais_uma, nome[5];

    escolha_menu = 0;

    while (escolha_menu != 4){

        system ("clear"); //SE PRECISAR OLHAR OS ERROS NO TERMINAL, APAGUE ISSO
        escolha_menu = 0;

        setlocale(LC_ALL, "Portuguese");
        printf ("█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█\n");
        printf ("█                                                                             █\n");
        printf ("█                                                                             █\n");
        printf ("█                                                                             █\n");
        printf ("█                                                                             █\n");
        printf ("█                   █▀▀█ █   █▀▀█ █▀▀ █ █    █ █▀▀█ █▀▀ █ █                   █\n");
        printf ("█                   █▀▀▄ █   █▄▄█ █   █▀▄ ▄  █ █▄▄█ █   █▀▄                   █\n");
        printf ("█                   █▄▄█ ▀▀▀ ▀  ▀ ▀▀▀ ▀ ▀ █▄▄█ ▀  ▀ ▀▀▀ ▀ ▀                   █\n");
        printf ("█                                                                             █\n");
        printf ("█                                                                             █\n");
        printf ("█                                                                             █\n");
        printf ("█                                                                             █\n");
        printf ("█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█\n");
        printf ("█                                                                             █\n");
        printf ("█                                                                             █\n");
        printf ("█                                1 - Jogar                                    █\n");
        printf ("█                                2 - Ranking                                  █\n");
        printf ("█                                3 - Regras                                   █\n");    
        printf ("█                                4 - Sair                                     █\n");
        printf ("█                                                                             █\n");
        printf ("█                                                                             █\n");
        printf ("█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█\n");
        
        while (escolha_menu < 1 || escolha_menu > 4){
            printf("Digite sua escolha: ");
            scanf("%s", n);

            escolha_menu = atoi(n);

            if (escolha_menu < 1 || escolha_menu > 4){
                printf("\nResposta Inválida\n\n");
            }
        }

        switch (escolha_menu)
        {
            case 1:
            ranking_ler();
            system ("clear");

            srand(time(NULL));

            struct pontos p; //CHAMA AS VARIÁVEIS DE PONTOS
            p.rankig_pontos = p.placar_bot = p.placar_player = 0;
            for (rodada = 0; rodada < 10; rodada++)
            {
                p.pc_pontos = 0;
                p.player_pontos = 0;
                printf("\n\n█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█\n");
                printf("█                                  RODADA %d                                   █\n", rodada + 1);
                printf("█                             Player [%d] x [%d] Bot                            █\n", p.placar_player, p.placar_bot);
                printf("█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█\n\n");
                //CARTAS DO PLAYER
                do
                {
                    carta = baralho[rand() % 12];
                    //CASO O ÁS SEJA SORTEADO
                    if (carta == 1)
                    {
                        printf("Você tirou o ás!\n\nEscolha o valor [1] ou [11]: ");
                        scanf(" %s", n);

                        escolha_as = atoi(n);

                        while (escolha_as != 1 && escolha_as != 11)
                        {
                            printf("\nEscolha inválida. Tente novamente!\n\n");
                            printf("Você tirou o ás!\n\nEscolha o valor [1] ou [11]: ");
                            scanf(" %s", n);

                            escolha_as = atoi(n);
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

                        if ((mais_uma == 'N' || mais_uma == 'n') && p.player_pontos < 17){
                            printf ("\nVocê só pode parar se a soma das cartas que possui for maior ou igual a 17!\n");
                            mais_uma = 'S';
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

                    naipes(carta);

                    p.pc_pontos += carta;

                    if (p.pc_pontos == 21)
                    {
                        printf("A soma dos pontos deu Vinte e Um. Ganhei!! :D\n");
                        break;
                    }
                    else if (p.pc_pontos > 21)
                    {
                        printf("Estourei!\nVocê venceu. :(\n");
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
            printf("\n\n█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█\n");
            printf("█                                PLACAR FINAL                                 █\n");
            printf("█                             Player [%d] x [%d] Bot                            █\n", p.placar_player, p.placar_bot);
            
            if (p.placar_player > p.placar_bot)
            {
                printf("█                       Parabéns, você venceu a partida!!                     █\n");
            }
            else if (p.placar_player == p.placar_bot)
            {
                printf("█                       Ops.. Parece que ocorreu um empate                    █\n");
            }
            else
            {
                printf("█                     Você perdeu a partida tente novamente.                  █\n");
            }
            printf("█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█\n\n");
            

            printf ("Insira qualquer coisa para retornar ao menu\n");
            scanf("%d", &i);

            pontos = p.rankig_pontos;

            if (pontos > atoi(mat[4][0])){
                printf ("\nParabéns, você tem os pontos necessários para entrar no ranking\nDigite o seu nome (maximo 5 caracteres)\n");
                scanf ("%s", nome);

            }
            break;

            case 2:
            system ("clear");
            ranking_ler();
            printf ("Insira qualquer coisa para retornar ao menu\n");
            scanf("%d", &i);
            break;
            
            case 3:
            system ("clear");
            regras();
            printf ("Insira qualquer coisa para retornar ao menu\n");
            scanf("%d", &i);
            break;

            case 4:
            system ("clear");
            printf ("\n\nObrigado por Jogar!\n\n");
            break;
        }
    }
    
    return 0;
}
