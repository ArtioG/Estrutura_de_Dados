#include <stdio.h>
#include <string.h>

int existeStringNoArray(char *array[], int tamanho, char *busca)
{
    for (int i = 0; i < tamanho; i++)
    {
        if (strcmp(array[i], busca) == 0)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    char *nomes[] = {"Alice", "Bob", "Carol", "David", "Eve"};
    int tamanho = sizeof(nomes) / sizeof(nomes[0]);

    char busca[] = "David";
    int resultado = existeStringNoArray(nomes, tamanho, busca);

    if (resultado)
    {
        printf("A string foi encontrada no array.\n");
    }
    else
    {
        printf("A string não foi encontrada no array.\n");
    }
}