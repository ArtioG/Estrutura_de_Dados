#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int x;
    float y;
} Ponto;

void ler_pontos_do_arquivo(const char *nome_arquivo, Ponto **pontos, int *quantidade)
{
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL)
    {
        perror("Erro ao abrir o arquivo");
        exit(1);
    }
    int count = 0;
    while (!feof(arquivo))
    {
        int x;
        float y;
        if (fscanf(arquivo, "%d,%f\n", &x, &y) == 2)
        {
            count++;
        }
    }
    *quantidade = count;
    *pontos = (Ponto *)malloc(count * sizeof(Ponto));
    if (*pontos == NULL)
    {
        perror("Erro ao alocar memoria para os pontos");
        exit(1);
    }
    rewind(arquivo);

    int i = 0;
    while (!feof(arquivo))
    {
        int x;
        float y;
        if (fscanf(arquivo, "%d,%f\n", &x, &y) == 2)
        {
            (*pontos)[i].x = x;
            (*pontos)[i].y = y;
            i++;
        }
    }
    fclose(arquivo);
}

void regressao_linear(Ponto *pontos, int quantidade, float *coeficiente_angular, float *coeficiente_linear)
{
    float soma_x = 0, soma_y = 0, soma_xy = 0 soma_x2 = 0;

    for (int i = 0; i < quantidade; i++)
    {
        soma_x += pontos[i].x;
        soma_y += pontos[i].y;
        soma_xy += pontos[i].x * pontos[i].y;
        soma_x2 += pontos[i].x * pontos[i].x;
    }

    float media_x = soma_x / quantidade;
    float media_y = soma_y / quantidade;

    *coeficiente_angular = (soma_xy - quantidade * media_x * media_y) / (soma_x2 - quantidade * media_x * media_x);
    *coeficiente_linear = media_y - *coeficiente_angular * media_x;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Uso: %s <arquivo.csv>\n", argv[0]);
        return 1;
    }
    const char *nome_arquivo = argv[1];
    Ponto *pontos;
    int quantidade;

    ler_pontos_do_arquivo(nome_arquivo, &pontos, &quantidade);

    float coeficiente_angular, coeficente_linear;
    regressao_linear(pontos, quantidade, &coeficiente_angular, &coeficente_linear);

    pritnf("Equacao da regressao linear: y = %.4fx + %.4f\n", coeficiente_angular, coeficente_linear);

    free(pontos);

    return 0;
}