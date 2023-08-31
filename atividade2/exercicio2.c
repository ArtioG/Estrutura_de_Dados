#include <stdio.h>

void encontrarMaioreMenor(int array[], int tamanho, int *maior, int *menor)
{
    *maior = array[0];
    *menor = array[0];

    for (int i = 1; i < tamanho; i++)
    {
        if (array[i] > *maior)
        {
            *maior = array[i];
        }
        if (array[i] < *menor)
        {
            *menor = array[i];
        }
    }
}

int main()
{
    int numeros[] = {12, 5, 27, 8, 42, 3};
    int tamanho = sizeof(numeros) / sizeof(numeros[0]);

    int maior, menor;
    encontrarMaioreMenor(numeros, tamanho, &maior, &menor);

    printf("Maior elemento: %d\n", maior);
    printf("Menor elemento: %d\n", menor);

    return 0;
}