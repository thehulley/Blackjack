#include <stdio.h>
#include <stdlib.h>

int main()
{
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
