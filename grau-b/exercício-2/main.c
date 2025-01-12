#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {

    char fabricante[20];
    char modelo[20];
    int ano;
    int tanque;
    float consumo;
    float autonomia;

} Veiculo;

void exercicioA(Veiculo v[]);

void exercicioB(Veiculo v[]);

void exercicioC(Veiculo v[]);

int main() {

    FILE *file;
    char line[100];

    file = fopen("veículos.txt", "r");

    if(file == NULL) {
        printf("Ocorreu um erro ao abrir o arquivo.");
        return 0;
    }

    Veiculo veiculo[20];
    int i = 0;

    while(fgets(line, sizeof(line), file)) {

        fscanf(file, "%s %s %d %d %f",  veiculo[i].fabricante, veiculo[i].modelo,
                                        &veiculo[i].ano, &veiculo[i].tanque, &veiculo[i].consumo);

        i++;
    }

    exercicioA(veiculo);

    exercicioB(veiculo);

    exercicioC(veiculo);

    return 0;
}

void exercicioA(Veiculo v[]) {

    // imprime os fabricantes e modelos dos veículos fabricados entre 2015 e 2018;

    printf("Fabricados entre 2015 e 2018\n\n");
    printf("%-20s %-20s\n", "Fabricantes", "Modelos");

    for(int i = 0; i < 20; i++) {

        if(v[i].fabricante != NULL && v[i].modelo != NULL && v[i].ano != 0 && v[i].tanque != 0 && v[i].consumo != 0) {

            if(v[i].ano >= 2015 && v[i].ano <= 2018) {

                printf("%-20s %-20s\n", v[i].fabricante, v[i].modelo);
            }
        }
    }
}

void exercicioB(Veiculo v[]) {

    // imprime somente os modelos dos veículos que iniciam com vogal ou terminem com consoante

    printf("\nModelos de veiculos que iniciam com vogal ou terminam com consoante\n\n");

    for(int i = 0; i < 20; i++) {

        if(v[i].fabricante != NULL && v[i].modelo != NULL && v[i].ano != 0 && v[i].tanque != 0 && v[i].consumo != 0) {

            int tam = strlen(v[i].modelo);

            if(v[i].modelo[0] == 'A' || v[i].modelo[0] == 'E' || v[i].modelo[0] == 'I' ||
               v[i].modelo[0] == 'O' || v[i].modelo[0] == 'U') {

                printf("%-20s\n", v[i].modelo);
            }

            else if(v[i].modelo[tam-1] == 'b' || v[i].modelo[tam-1] == 'c' || v[i].modelo[tam-1] == 'd' ||
                    v[i].modelo[tam-1] == 'f' || v[i].modelo[tam-1] == 'g' || v[i].modelo[tam-1] == 'h' ||
                    v[i].modelo[tam-1] == 'j' || v[i].modelo[tam-1] == 'k' || v[i].modelo[tam-1] == 'l' ||
                    v[i].modelo[tam-1] == 'm' || v[i].modelo[tam-1] == 'n' || v[i].modelo[tam-1] == 'p' ||
                    v[i].modelo[tam-1] == 'q' || v[i].modelo[tam-1] == 'r' || v[i].modelo[tam-1] == 's' ||
                    v[i].modelo[tam-1] == 't' || v[i].modelo[tam-1] == 'v' || v[i].modelo[tam-1] == 'w' ||
                    v[i].modelo[tam-1] == 'x' || v[i].modelo[tam-1] == 'y' || v[i].modelo[tam-1] == 'z') {

                printf("%-20s\n", v[i].modelo);
            }
        }
    }
}

void exercicioC(Veiculo v[]) {

    //  imprime o modelo, ano e a autonomia dos veículos com menor e maior autonomia, calculada pela
    //  fórmula: autonomia = tanque * consumo

    float menorConsumo = 999;
    float maiorConsumo = 0;
    int idMaior;
    int idMenor;

    for(int i = 0; i < 20; i++) {

        if(v[i].fabricante != NULL && v[i].modelo != NULL && v[i].ano != 0 && v[i].tanque != 0 && v[i].consumo != 0) {

            v[i].autonomia = v[i].tanque * v[i].consumo;

            if(v[i].autonomia > maiorConsumo) {
                maiorConsumo = v[i].autonomia;
                idMaior = i;
            }

            if(v[i].autonomia < menorConsumo) {
                menorConsumo = v[i].autonomia;
                idMenor = i;
            }
        }
    }

    printf("\n-- Menor autonomia --\n");
    printf("\n%-20s %-10s %-10s\n", "Modelo", "Ano", "Autonomia");
    printf("%-20s %-10d %-10.2f", v[idMenor].modelo, v[idMenor].ano, v[idMenor].autonomia);
    printf("\n\n-- Maior autonomia --\n");
    printf("\n%-20s %-10s %-10s\n", "Modelo", "Ano", "Autonomia");
    printf("%-20s %-10d %-10.2f\n", v[idMaior].modelo, v[idMaior].ano, v[idMaior].autonomia);
}
