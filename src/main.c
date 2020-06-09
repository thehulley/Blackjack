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


int ranking_ler(){

    FILE *fl;
    int c, i;
    char ranking[55], pessoa1[10], pessoa2[10], pessoa3[10], pessoa4[10], pessoa5[10];

    fl = fopen("ranking.txt", "r");

    for (i = 0; (c = fgetc(fl))!= EOF; i++){
        ranking[i] = c;
    }

    fclose(fl);

    // 10, 21, 32, 43, 54 - ONDE ACONTECE A DIVISAO ENTRE OS DADOS (|)
    // PARTE ONDE OS DADOS DO RANKING SAO DIVIDIDOS EM 5 STRINGS

    for (c=0; c<10; c++){
        pessoa1[c] = ranking[c];
    }

    i = 0;
    for (c=11; c<21; c++){
        pessoa2[i] = ranking[c];
        i += 1;
    }

    i = 0;
    for (c=22; c<32; c++){
        pessoa3[i] = ranking[c];
        i += 1;
    }

    i = 0;
    for (c=33; c<43; c++){
        pessoa4[i] = ranking[c];
        i += 1;
    }

    i = 0;
    for (c=44; c<54; c++){
        pessoa5[i] = ranking[c];
        i += 1;
    }


    //IMPRIME O RANKING

    printf ("█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█\n");
    printf ("█                                                                             █\n");
    printf ("█                              -=-[ Ranking ]-=-                              █\n");
    printf ("█                                                                             █\n");
    printf ("█                          Pontos | Rodadas | Nome                            █\n");
    printf ("█                                                                             █\n");

    // PRIMEIRO

    printf ("█        1 - ");

    for (c=0; c<10; c++){
        if ((c == 3) || (c == 5)){
            printf (" ");
        }
        printf("%c", pessoa1[c]);
    }
    
    printf ("                                                     █\n");

    // SEGUNDO 

    printf ("█        2 - ");

    for (c=0; c<10; c++){
        if ((c == 3) || (c == 5)){
            printf (" ");
        }
        printf("%c", pessoa2[c]);
    }
    
    printf ("                                                     █\n");

    // TERCEIRO

    printf ("█        3 - ");

    for (c=0; c<10; c++){
        if ((c == 3) || (c == 5)){
            printf (" ");
        }
        printf("%c", pessoa3[c]);
    }
    
    printf ("                                                     █\n");

    // QUARTO

    printf ("█        4 - ");

    for (c=0; c<10; c++){
        if ((c == 3) || (c == 5)){
            printf (" ");
        }
        printf("%c", pessoa4[c]);
    }
    
    printf ("                                                     █\n");

    // QUINTO

    printf ("█        5 - ");

    for (c=0; c<10; c++){
        if ((c == 3) || (c == 5)){
            printf (" ");
        }
        printf("%c", pessoa5[c]);
    }
    
    printf ("                                                     █\n");


    printf ("█                                                                             █\n");
    printf ("█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█\n");

    return 0;
}



int main(void) // FUNÇÃO PRINCIPAL
{
    int escolha_menu, sair_outros_menus;
    char p[2];

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
            system ("clear");
            ranking_ler();
            printf ("Insira qualquer coisa para retornar ao menu\n");
            scanf ("%s", p);
            break;
            
            case 3:
            system ("clear");
            regras();
            printf ("Insira qualquer coisa para retornar ao menu\n");
            scanf ("%s", p);
            break;

            case 4:
            system ("clear");
            printf ("\n\nObrigado por Jogar!\n\n");
            break;
        }
    }

    system("pause");
    return 0;
}
