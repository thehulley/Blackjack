#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void)
{
    int escolha_menu;

    setlocale(LC_ALL, "Portuguese");
    printf("================================================================\n");
    printf("|    ____                 ___        ______         ___        |\n");
    printf("|   |    \\ |        ^    /    |  /      |     ^    /    |  /   |\n");
    printf("|   |____/ |       / \\  |     |_/       |    / \\  |     |_/    |\n");
    printf("|   |    | |      /___\\ |     | \\       |   /___\\ |     | \\    |\n");
    printf("|   |____/ |____ /     \\ \\___ |  \\  \\___/  /     \\ \\___ |  \\   |\n");
    printf("|                                                              |\n");
    printf("================================================================\n");
    printf("|                          1-JOGAR                             |\n");
    printf("|                          2-RANKING                           |\n");
    printf("|                          3-SAIR                              |\n");
    printf("================================================================\n");
    printf("Digite sua escolha: ");
    scanf(" %d", &escolha_menu);

    switch (escolha_menu)
    {
        case 1:
        printf("a");
        break;

        case 2:
        printf("a");
        break;

        case 3:
        printf("Obrigado por Jogar!");
        break;

        default:
        printf("Resposta Inválida");
        break;
    }

    system("pause");
    return 0;
}
