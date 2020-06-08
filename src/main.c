#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void)
{
    int escolha_menu;
    char p[2];

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
    
    escolha_menu = 0;

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
        printf("a");
        break;

        case 2:
        printf("a");
        break;
        
        case 3:
        printf("a");
        break;

        case 4:
        printf("Obrigado por Jogar!");
        break;
    }

    system("pause");
    return 0;
}
