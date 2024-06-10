#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void primo(int n, int *p1, int *p2) {
    int ehprimo;
    *p1 = -1; // Inicializar p1 com um valor inválido
    *p2 = -1; // Inicializar p2 com um valor inválido

    for (int i = 2; i < n; i++) {
        ehprimo = 1;
        for (int j = 2; j <= sqrt(i); j++) { // Verificação correta de número primo
            if (i % j == 0) {
                ehprimo = 0;
                break; // Sair do loop assim que encontrar um divisor
            }
        }

        if (ehprimo == 1) {
            if (*p1 == -1 && *p2 == -1) {
                *p1 = i;
                *p2 = i;
            } else {
                if (i > *p1) {
                    *p1 = i;
                }
                if (i < *p2) {
                    *p2 = i;
                }
            }
        }
    }
}

int main() {
    int n;
    int *p1, *p2;
    p1 = malloc(sizeof(int));
    p2 = malloc(sizeof(int));
    *p1 = -1; // Inicializar p1 com um valor inválido
    *p2 = -1; // Inicializar p2 com um valor inválido

    printf("Digite o valor n: \n");
    scanf("%d", &n);

    primo(n, p1, p2);

    if (*p1 == -1 || *p2 == -1) {
        printf("Nenhum número primo encontrado.\n");
    } else {
        printf("Menor valor = %d.\nMaior valor = %d", *p2, *p1);
    }

    free(p1);
    free(p2);

    return 0;
}