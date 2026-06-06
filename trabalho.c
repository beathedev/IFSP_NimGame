// Jogo do Nim: 21 palitos na mesa, quem tirar o ultimo perde.
// Jogador e computador se alternam retirando 1, 2 ou 3 palitos por rodada.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

    int palitos = 21;  // total de palitos disponiveis na mesa
    int jogada;        // quantos palitos serao retirados no turno
    int turno = 1;     // 1 = jogador, 2 = computador
    int i;             // contador do for

    srand(time(NULL)); // inicializa o gerador de numeros aleatorios

    printf("=========================================\n");
    printf("           O DESAFIO DO NIM              \n");
    printf("=========================================\n");
    printf("Regra: Quem tirar o ultimo palito, PERDE!\n");
    printf("Voce pode retirar 1, 2 ou 3 palitos por vez.\n");

    // laco principal: roda enquanto houver palitos na mesa
    while(palitos > 0) {

        printf("\n=========================================\n");
        printf("Palitos na mesa (%i restantes):\n", palitos);

        // for usado para desenhar os palitos na tela
        for(i = 0; i < palitos; i++) {
            printf("| ");
        }
        printf("\n\n");

        if(turno == 1) {
            // turno do jogador: le a jogada e valida se esta entre 1 e 3
            printf("Sua vez! Quantos palitos vai retirar (1 a 3)? ");
            scanf("%i", &jogada);

            if(jogada >= 1 && jogada <= 3 && jogada <= palitos) {
                palitos = palitos - jogada;
                printf("=> Voce retirou %i palito(s).\n", jogada);
                turno = 2;
            } else {
                // jogada invalida: turno nao muda, jogador tenta de novo
                printf("=> Jogada Invalida! Tente novamente.\n");
            }

        } else {
            // turno do computador: sorteia entre 1 e 3
            printf("Vez do Computador...\n");

            jogada = (rand() % 3) + 1;

            // garante que o PC nao tente retirar mais do que o disponivel
            if(jogada > palitos) {
                jogada = palitos;
            }

            palitos = palitos - jogada;
            printf("=> O Computador retirou %i palito(s).\n", jogada);
            turno = 1;
        }
    }

    // fim de jogo: verifica quem pegou o ultimo palito pelo valor de turno
    // se turno == 1, o computador jogou por ultimo (virou 1 apos a jogada dele)
    printf("\n=========================================\n");
    printf("FIM DE JOGO! O ultimo palito foi retirado.\n");

    if(turno == 1) {
        printf("O Computador tirou o ultimo palito. VOCE VENCEU!\n");
    } else {
        printf("Voce tirou o ultimo palito. O COMPUTADOR VENCEU!\n");
    }

    printf("=========================================\n");

    return(0);
}