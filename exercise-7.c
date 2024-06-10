#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void frequencia (int vet[], int n, int *f1, int *f2){
    int elemento;
    int maior = -1;
    int menor = n + 1;
    int contador;

    for (int i = 0; i < n; i++){
        elemento = vet[i];
        contador = 0;
        for (int j = 0; j < n; j++){
            if (elemento == vet[j]){
                contador++;
            }
        }

        if (contador > maior){
            maior = contador;
            *f2 = elemento;
        }
        if (contador < menor){
            menor = contador;
            *f1 = elemento;
        }
    }
}

int main()
{
    int n, *vet, *f1, *f2;
    printf("Digite o tamanho do vetor: \n");
    scanf("%d", &n);
    vet = malloc(sizeof(int)*n);
    f1 = malloc(sizeof(int));
    f2 = malloc(sizeof(int));
    printf("Digite os valores do vetor: \n");
    for (int i = 0; i < n; i++){
        scanf("%d", &vet[i]);
    }
    frequencia(vet, n, f1, f2);
    printf("f1 = %d\nf2 = %d", *f1, *f2);
    free(vet);
    free(f1);
    free(f2);

    return 0;
}