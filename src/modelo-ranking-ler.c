#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c, i=1;
    char ranking[200];

    FILE *fl;
    fl = fopen("ranking.txt", "r"); //ABRE O ARQUIVO

    while((c = fgetc(fl)) != EOF) // REALIZA ENQUANTO EXISTIR CARACTER E ATRIBUI O CARACTER ATUAL A VARIAVEL C
    {
        ranking[i] = c;
        printf ("%c", ranking[i]);
        i += 1;
    }

    fclose(fl);
    return 0;
}
