#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
            printf("\n\n");
            printf("  _   _            ___       _   _   __         \n"); 
            printf(" |_) |_ |\\/|   \\  / |  |\\ | | \\ / \\ (_     \n");
            printf(" |_) |_ |  |    \\/ _|_ | \\| |_/ \\_/ __)      \n");
            printf("                                                \n");
            printf("AO NOSSO JOGO DE ADIVINHAÇÃO!!!!!\n");
            printf("       _   _        _         _   _       _     _       \n");
            printf("  /\\  |_) |_   \\_/ / \\ | |   |_) |_  /\\  | \\ \\_/ )\n");
            printf(" /--\\ | \\ |_    |  \\_/ |_|   | \\ |_ /--\\ |_/  | o  \n");
            printf("                                                        \n");
            printf("\n\n");
                                                                     

    int segundos = time(0);
    srand(segundos);

    int numerogrande = rand();
    int numerosecreto = numerogrande % 100;
    int chute;
    int tentativas = 1;
    double pontos = 1000;

    int acertou = 0;
    int nivel;

    printf("Qual o nivel de dificuldade?\n");
    printf("[1] Fácil [2] Médio [3] Dificil\n\n");
    printf("Escolha: ");
    scanf("%d", &nivel);

    int numerodetentativas;

    switch (nivel) {
        case 1:
            numerodetentativas = 20;
            break;
            case 2:
            numerodetentativas = 15;
            break;
            default:
            numerodetentativas = 6;
            break;
    }

    for(int i = 1; i <= numerodetentativas; i++){

        printf("Tentativa %d\n", tentativas);    
        printf("Adivinhe o número secreto: \n");

        scanf("%d", &chute);//& comercial
        printf("Seu chute foi %d \n", chute);

        if (chute < 0){
         printf("Você não pode chutar numenos negativos...Tente chutar um numero acima de 0! \n");
         continue;
    }

    acertou = (chute == numerosecreto);//true or false
    int maior = chute > numerosecreto;
    
    if(acertou){
      break;
    }
    else if(maior){
            printf("Dica: Seu numero foi maior que o Numero secreto...\n");
        } 
    else {
            printf("Dica: Seu numero foi menor que o Numero Secreto...\n");
         }
         tentativas++;

         double pontosperdidos = abs(chute - numerosecreto) / 2.0; // casting:colocando o (double)antes do n inteiro para calculo de n flutuantes
         pontos = pontos - pontosperdidos;
        } 
        printf("Fim de jogo...\n");
        if(acertou){
        printf("UHUL! Você acertou!\n");
        printf("Você acertou em %d tentativas!", tentativas);
        printf("Total de pontos: %.1f\n", pontos);
        } else {
            printf("Você perdeu! Tente novamente!!\n");
        }
}   
  