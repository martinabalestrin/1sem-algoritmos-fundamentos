#include <stdio.h>
#include <stdlib.h>

int main()
{
    // variável do número de jogadores
    int num_jogadores = 0;
    // variável do número de partidas
    int num_partidas = 0;
    // variável de jogadores que marcaram gol todos jogos
    int golTodosJogos = 0;

    // entrada do número de jogadores
    printf("Informe o numero de jogadores: ");
    scanf("%d", &num_jogadores);

    // entrada do número de partidas
    printf("Informe o numero de partidas: ");
    scanf("%d", &num_partidas);

    // declaração da matriz
    int matriz[num_jogadores][num_partidas];

    // entrada de dados na matriz
    for(int i = 0; i < num_jogadores; i++) {
        printf("Gols do jogador %d: ", i+1);

        for(int j = 0; j < num_partidas; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    // verificar quantos jogadores marcaram gol em todos jogos
    for(int i = 0; i < num_jogadores; i++) {
        int jogosComGol = 0;

        for(int j = 0; j < num_partidas; j++) {
            if(matriz[i][j] > 0) {
                jogosComGol++;
            }
        }

        if(jogosComGol == num_partidas) {
            golTodosJogos++;
        }
    }

    // imprime a quantidade de jogadores que marcaram gol todos jogos
    printf("RESULTADO: %d", golTodosJogos);

    return 0;
}
