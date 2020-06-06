#include <stdio.h>
#include <string.h>

int main ()
{
    char nome[10], pontuacao[4], rodadas[3], ranking[17], i=1;

    while (i<=10)  //COLETA AS INFORMAÇÕES, AS STRINGS NO CASO
    {
        printf ("\nDigite o seu nome\n");
        scanf ("%s", nome);
        scanf ("%s", pontuacao);
        scanf ("%s", rodadas);

        if (i == 1)  //SE I=1 A STRING TESTE COPIA A STRING PONTUAÇÃO, PARA "INICIAR"
        {
            strcpy (ranking, pontuacao);
        }
        else  //SE I>I CONTINUA A CONCATENAÇÃO NORMALMENTE
        {
            strcat (ranking, pontuacao);
        }

        strcat (ranking, "|");
        strcat (ranking, rodadas);
        strcat (ranking, "|");
        strcat (ranking, nome);
        strcat (ranking, "\n");

        printf ("%s", ranking);

        i += 5;
    }
    
    FILE *fp;;
    fp = fopen("ranking.txt", "w"); //ABRE O ARQUIVO, CASO O ARQUIVO NÃO EXISTA CRIA UM

    for(i=0; ranking[i]; i++)
    {    
        fputc(ranking[i], fp);  //ESCREVE A STRING NO ARQUIVO (SUBSTITUINDO TODO O CONTEUDO DO ARQUIVO)
    }

    fclose(fp);
    return 0;
}
