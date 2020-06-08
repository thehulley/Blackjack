#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int regras() // FUNÇÃO PARA NÃO POLUIR O CÓDIGO PRINCIPAL
{
    printf ("\n\n█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█\n");
    printf ("█                                                                             █\n");
    printf ("█                               -=-[ Regras ]-=-                              █\n");
    printf ("█                                                                             █\n");
    printf ("█                                                                             █\n");
    printf ("█  Pontuação das cartas:                                                      █\n");
    printf ("█                                                                             █\n");
    printf ("█  Ás → 1 ou 11 pontos(usuário decide);                                       █\n");
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
    printf ("█  Se ocorrer do jogador perder, a quantidade de rodadas vencidas juntamente  █\n");
    printf ("█  com pontuação total será adicionada ao ranking inicial (apresentada no     █\n");
    printf ("█  menu), sendo que a classificação será baseada na pontuação total do        █\n");
    printf ("█  jogador. Caso o jogador ganhe será adicionada a sua pontuação total uma    █\n");
    printf ("█  pontuação X que será definida com base em uma das situações citadas        █\n");
    printf ("█  abaixo.                                                                    █\n");
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



int main(void) // FUNÇÃO PRINCIPAL
{
    int escolha_menu, sair_regras;
    char p[2];

    escolha_menu = 0;

    while (escolha_menu != 4){

        system ("clear"); //SE PRECISAR OLHAR OS ERROS NO TERMINAL, APAGUE ISSO

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
            scanf(" %s", p);

            escolha_menu = atoi(p);

            if (escolha_menu < 1 || escolha_menu > 4){
                printf("\nResposta Inválida\n\n");
            }
        }

        switch (escolha_menu)
        {
            case 1:
            printf("\n\nJogar selecionado\n\n");
            break;

            case 2:
            printf("\n\nRanking selecionado\n\n");
            break;
            
            case 3:
            regras();
            printf ("\n\nInsira qualquer coisa para retornar ao menu\n");
            scanf ("%s", p);

            sair_regras = atoi(p);
            break;

            case 4:
            printf("\n\nObrigado por Jogar!\n\n");
            break;
        }

        escolha_menu = 0;
    }

    system("pause");
    return 0;
}
