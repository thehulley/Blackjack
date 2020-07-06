#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>

//VARIÁVEIS DE PONTOS DA PARTIDA E RODADA
struct pontos
{
    int player_pontos, pc_pontos, ranking_pontos;
    int placar_player, placar_bot;
};

//IMPRIME AS CARTAS SORTEADAS
int naipes (int carta) {
    int i = 0, x = 0;
    char naipes[4][4] = {"♠", "♣", "♥", "♦"};
    char valor_carta[4][2] = {"Q", "J", "K"};
    srand(time(NULL));

    //SORTEIO DE NAIPES
    i = rand() % 4;
    x = rand() % 4;

    printf ("█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█\n");
    if (carta == 10 || carta == 11 || carta == 1) {
            if (carta == 10)
            {
                if (i == 3)
                {
                    printf ("█ 10            █\n");
                }
                else
                {
                    printf ("█ %s             █\n", valor_carta[i]);
                }
            }
            else if (carta == 11 || carta == 1) {
                printf ("█ A             █\n");
            }
        }
        else
        {
            printf ("█ %d             █\n", carta);
        }
    printf ("█ %s             █\n", naipes[x]);
    printf ("█               █\n");
    printf ("█               █\n");
    printf ("█               █\n");
    printf ("█               █\n");
    printf ("█               █\n");
    printf ("█             %s █\n", naipes[x]);
    if (carta == 10 || carta == 11 || carta == 1) {
            if (carta == 10)
            {
                if (i == 3)
                {
                    printf ("█            10 █\n");
                }
                else
                {
                    printf ("█             %s █\n", valor_carta[i]);
                }
            }
            else if (carta == 11 || carta == 1) {
                printf ("█             A █\n");
            }
        }
        else
        {
            printf ("█             %d █\n", carta);
        }
    printf ("█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█\n\n");
    
    system("sleep 01");

    return 0;
}

int ranking(int opcao, int pontuacao, int rodadas, char *nome[6]) // FUNÇÃO PARA LER E GRAVAR O ARQUIVO RANKING.TXT
{
    char ranking[200], *aux[5][1], *matriz[5][3], *mat[5][3]; 
    char* token;
    int c, i, n;
    
    char pts[3], atualizado[500];
    char desc[] = "Não altere esse arquivo! Alteração do mesmo poderá ocasionar em mau funcionamento\n|";
    
    FILE *fl; // ABRE O ARQUIVO E COMEÇA A PASSAR TODOS OS CARACTERES PARA O VETOR
    fl = fopen("ranking.txt", "r");
        for (i = 0; (c = fgetc(fl))!= EOF; i++){
            ranking[i] = c;
        }
    fclose(fl);

    i = 0;

    token = strtok(ranking, "|"); // REALIZA UMA FILTRAGEM DOS CARACTERES, SEPARANDO EM 5 STRINGS NA MATRIZ AUX
    while (token != NULL) {
        token = strtok(NULL, "|");
        aux[i][0] = token;

        i += 1;
    }

    for (c=0; c<5; c++){  // REALIZA OUTRA FILTRAGEM SEPARANDO DESSA VEZ OS PONTOS, RODADAS E NOMES DE CADA PLAYER
        i=0;
        token = strtok(aux[c][0], "-");

        while (token != NULL) {
            token = strtok(NULL, "-");
            matriz[c][i] = token;

            i += 1;
        }
    }

    for (c=0; c<5; c++){  // REPASSA OS VALORES DE MATRIZ PARA MAT
        for (i=0; i<3; i++){
            mat[c][i] = matriz[c][i];
        }
    }

    if (opcao == 1){  // SE FOR PASSADO O VALOR 1 POR REFERENCIA PELA OPCAO REESCREVE O ARQUIVO PASSANDO OS DADOS DO PLAYER
        for (c=0; c<5; c++){  // PROGRAMA CHECA A POSIÇÃO O PLAYER FICARÁ E GRAVA A POSIÇÃO COMO N
            if (pontuacao > atoi(mat[c][1])){
                n = c;
                break;
            }
        }

        for (c=4; c>n; c--){  // PROGRAMA "JOGA" OS VALORES PARA BAIXO ATÉ A POSIÇÃO N
            mat[c][0] = mat[c-1][0];
            mat[c][1] = mat[c-1][1];
            mat[c][2] = mat[c-1][2];
        }

        if (rodadas == 1){  // CONFIGURAÇÃO "VISUAL"
            mat[n][0] = "01";
        }
        else if (rodadas == 2){
            mat[n][0] = "02";
        }
        else if (rodadas == 3){
            mat[n][0] = "03";
        }
        else if (rodadas == 4){
            mat[n][0] = "04";
        }
        else if (rodadas == 5){
            mat[n][0] = "05";
        }
        else if (rodadas == 6){
            mat[n][0] = "06";
        }
        else if (rodadas == 7){
            mat[n][0] = "07";
        }
        else if (rodadas == 8){
            mat[n][0] = "08";
        }
        else if (rodadas == 9){
            mat[n][0] = "09";
        }
        else if (rodadas == 10){
            mat[n][0] = "10";
        }

        sprintf(pts, "%i", pontuacao);  // TRANSFORMA A PONTUACAO EM UMA STRING COM O NOME PTS

        mat[n][1] = pts;
        mat[n][2] = *nome;

        for (i=0; i<5; i++){  // PROGRAMA COMEÇA A CONCATENAR A STRING ATUALIZADO, QUE SERÁ ESCRITA NO ARQUIVO DO RANKING
            if (i == 0){
                strcpy (atualizado, desc);
                strcat (atualizado, "1");
            }
            else if (i == 1){
                strcat (atualizado, "2");
            }
            else if (i == 2){
                strcat (atualizado, "3");
            }
            else if (i == 3){
                strcat (atualizado, "4");
            }
            else{
                strcat (atualizado, "5");
            }

            strcat (atualizado, "-");
            strcat (atualizado, mat[i][0]);
            strcat (atualizado, "-");

            if((pontuacao < 10) && (i == n)){
                strcat (atualizado, "00");
            }
            else if((pontuacao >= 10) && (pontuacao < 100) && (i == n)){
                strcat (atualizado, "0");
            }

            strcat (atualizado, mat[i][1]);
            strcat (atualizado, "-");
            strcat (atualizado, mat[i][2]);
            strcat (atualizado, "|");
        }

        FILE *fp;;
        fp = fopen("ranking.txt", "w"); //ABRE O ARQUIVO, CASO O ARQUIVO NÃO EXISTA CRIA UM

        for(i=0; atualizado[i]; i++)
        {    
            fputc(atualizado[i], fp);  //ESCREVE A STRING ATUALIZADO NO ARQUIVO RANKING.TXT (SUBSTITUINDO TODO O CONTEUDO DO ARQUIVO)
        }

        fclose(fp);
    }
    else if (opcao == 2){  // SE FOR PASSADO O VALOR 1 POR REFERENCIA PELA OPCAO PRINTA O RANKING
        printf ("█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█\n");
        printf ("█                                                                             █\n");
        printf ("█                              -=-[ Ranking ]-=-                              █\n");
        printf ("█                                                                             █\n");
        printf ("█                        Rodadas | Pontuação | Nome                           █\n");
        printf ("█                                                                             █\n");

        // PRIMEIRO

        printf ("█        1 - ");

        for (i=0; i<3; i++){
            printf("%s ", mat[0][i]);
        }
        
        printf ("                                                    █\n");

        // SEGUNDO 

        printf ("█        2 - ");

        for (i=0; i<3; i++){
            printf("%s ", mat[1][i]);
        }
        
        printf ("                                                    █\n");

        // TERCEIRO

        printf ("█        3 - ");

        for (i=0; i<3; i++){
            printf("%s ", mat[2][i]);
        }
        
        printf ("                                                    █\n");

        // QUARTO

        printf ("█        4 - ");

        for (i=0; i<3; i++){
            printf("%s ", mat[3][i]);
        }
        
        printf ("                                                    █\n");

        // QUINTO

        printf ("█        5 - ");

        for (i=0; i<3; i++){
            printf("%s ", mat[4][i]);
        }
        
        printf ("                                                    █\n");


        printf ("█                                                                             █\n");
        printf ("█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█\n");
    }

    c = atoi(mat[4][1]);

    return c; // RETORNA A ULTIMA PONTUACAO DO RANKING PARA COMPARAÇÃO DE PONTOS
}

int contarcaracteres(char nome[6]){
    int i;

    for(i=0;i<10;i++)
    {
      if(nome[i+1] == '\0'){
          break;
      }
    }

    return i;
}

int main(void) // FUNÇÃO PRINCIPAL
{
    int escolha_menu, sair_outros_menus, i, c, menor;
    int baralho[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10}, carta, rodada, escolha_as;
    char prot[2], mais_uma, j;

    int n;
    char nome[6], *nm[6];

    menor = ranking(0, 0, 0, nm);

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
            scanf("%s", prot);

            escolha_menu = atoi(prot);

            if (escolha_menu < 1 || escolha_menu > 4){
                printf("\nResposta Inválida\n\n");
            }
        }

        switch (escolha_menu)
        {
            case 1:
            system ("clear");

            srand(time(NULL));

            struct pontos p; //CHAMA AS VARIÁVEIS DE PONTOS
            p.ranking_pontos = p.placar_bot = p.placar_player = 0;
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
                        scanf(" %s", prot);

                        escolha_as = atoi(prot);

                        while (escolha_as != 1 && escolha_as != 11)
                        {
                            printf("\nEscolha inválida. Tente novamente!\n\n");
                            printf("Você tirou o ás!\n\nEscolha o valor [1] ou [11]: ");
                            scanf(" %s", prot);

                            escolha_as = atoi(prot);
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
                        p.placar_player++;
                        break;
                    }
                    else if (p.player_pontos > 21)
                    {
                        printf("\n\nA soma das cartas foi maior que 21! \n\nVocê estorou! :(\n");
                        p.placar_bot++;
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
                        if (p.pc_pontos + 11 <= 21)
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
                        p.placar_bot++;
                        break;
                    }
                    else if (p.pc_pontos > 21)
                    {
                        printf("Estourei!\nVocê venceu. :(\n");
                        p.placar_player++;
                        break;
                    }
                    else if (p.pc_pontos < 21 && p.pc_pontos > p.player_pontos)
                    {
                        printf("Fiz mais pontos que você. Venci!! :D");
                        p.placar_bot++;
                        break;
                    }
                }

                if (p.player_pontos <= 21){
                    if ((p.player_pontos > p.pc_pontos) & (p.pc_pontos < 21)){
                        i = p.player_pontos - 16;
                        p.ranking_pontos += i;
                    }
                    else if (p.pc_pontos > 21){
                        i = p.player_pontos - 16;
                        p.ranking_pontos += i;
                    }
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

            if (p.ranking_pontos > menor){  // PARTE QUE VERIFICA SE O PLAYER POSSUI PONTUAÇÃO PARA ENTRAR NO RANKING
                printf("\nParabéns, você possui pontos suficientes para entrar no ranking\nDigite abaixo o seu nome - (máximo 5 caracteres)\n");
                scanf("%s", nome);

                j = contarcaracteres(nome);

                if (j > 4){ // PROTEÇÃO CONTA NOMES MAIORES QUE 5 CARACTERES
                    printf("\nDigite um nome com até 5 caracteres\n");
                    scanf("%s", nome);

                    j = contarcaracteres(nome);
                }
                *nm = nome;

                ranking(1, p.ranking_pontos, p.placar_player, nm);
            }
            else{ // SE NÃO POSSUIR PONTUAÇÃO ESPERA O USUARIO RETORNAR AO MENU
                printf ("Insira qualquer coisa para retornar ao menu\n");
                scanf("%d", &i);
            }
            break;

            case 2:
            system ("clear");
            ranking(2, 0, 0, nm);
            printf ("Insira qualquer coisa para retornar ao menu\n");
            scanf("%d", &i);
            break;
            
            case 3:
            system ("clear");
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
