#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void menor_base_log(int n, int *b, int *k){
    for (int i = 2; i < n; i++){
        for (int j = 1; j < n; j++){
            if (pow(i, j) == n){
                *b = i;
                *k = j;
                return;
            }
            else if (n == 1) {
                *b = 1;
                *k = 0;
                return;
            }
            else if(n == 0){
                *b = 0;
                *k = 1;
                return;
            }
        }
    }
    return;
}

int main()
{
    int n;
    int *b, *k;
    b = malloc(sizeof(int));
    k = malloc(sizeof(int));
    *b = -1;
    *k = -1;
    printf("Digite o valor n: \n");
    scanf("%d", &n);
    menor_base_log(n, b, k);
    printf("b= %d e k = %d.\n", *b, *k);
}