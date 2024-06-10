#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double media(double vet[], int n, int *i){
    double soma = 0;
    double mediadovetor = 0;
    double diferenca = 0;
    double diferencamaisproximo = 0;
    int maisproximo = -1;
    for (int k = 0; k < n; k++){
        soma += vet[k];
    }
    mediadovetor = soma / n;

    for (int j = 0; j < n; j++){
        if (vet[j] == mediadovetor){
            *i = j;
            return mediadovetor;
        }
        else if(vet[j] != mediadovetor){

            diferenca = vet[j] - mediadovetor;

            if (diferenca < 0){
                diferenca = diferenca * -1;
            }

            if (maisproximo == -1){
                maisproximo = j;
                diferencamaisproximo = diferenca;
            }
            else if (diferenca < diferencamaisproximo){
                maisproximo = j;
                diferencamaisproximo = diferenca;
            }
        }
    }
    *i = maisproximo;
    return mediadovetor;
}

int main()
{
    int n;
    double *vet;
    int *i;
    double valormedia;
    printf("Digite o tamanho do vetor: \n");
    scanf("%d", &n);
    vet = malloc(sizeof(double)* n);
    i = malloc(sizeof(int));
    printf("Digite os valores do vetor: \n");
    for(int g = 0; g < n; g++){
        scanf("%lf", &vet[g]);
    }
    valormedia = media(vet, n, i);
    printf("Media = %.2lf\nPosição i = %d", valormedia, *i);

    free(vet);
    free(i);

}