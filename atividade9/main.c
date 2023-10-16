#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include <time.h>

#define FILENAME "1kk_rand_float.csv"


int main(int argc, char* argv[]){

    No* n0 = no('C', NULL);
    No* n1 = no('E', NULL);
    No* n2 = no('A', no('D', no('B', no('X', no('Z', NULL)))));
    No* n3 = no('U', NULL);
    lista_inserir_no(n0, n2);
    lista_inserir_no(n0, n1);
    lista_inserir_no(n0, n3);
    lista_imprimir(n0);
    printf("\nqtd nos: %d", lista_quantidade_nos(n0));
    No* n_copia = lista_copiar(n0);
    printf("\n");
    lista_imprimir(n_copia);
    lista_concatenar(n0, n_copia);
    printf("\n");
    lista_imprimir(n0);
    lista_liberar(n0);
    n0 = NULL;
    lista_imprimir(n0);

    char busca = 'D';
    printf("\nExistencia de %c na lista: %s", busca, lista_verificar_existencia(n0, busca) ? "Sim" : "Não");

    busca = 'E';
    printf("\nOcorrencias de %c na lista: %d", busca, lista_verificar_ocorrencias(n0, busca));

    printf("\nImprimir inverso:\n");
    lista_imprimir_inversa(n0);

    int posicao = 2;
    lista_inserir_no_i(n0, posicao);
    printf("\nInserir nó na posição %d:\n", posicao);
    lista_imprimir(n0);

    posicao = 1;
    lista_remover_no_i(n0, posicao);
    printf("\nRemover nó na posição %d:\n", posicao);
    lista_imprimir(n0);

    busca = 'X';
    printf("\nRemover todos os nós com valor %c:\n", busca);
    lista_remover_no(n0, busca);
    lista_imprimir(n0);

    double calcular_tempo_medio_insercao(No* lista) {
    clock_t inicio, fim;
    double tempo_total = 0;

    FILE* arquivo = fopen(FILENAME, "r");
    float valor;

    while (fscanf(arquivo, "%f", &valor) == 1) {
        inicio = clock();
        lista_inserir_no_ordenado(lista, no(valor, NULL));
        fim = clock();
        tempo_total += ((double)fim - inicio) / CLOCKS_PER_SEC;
    }

    fclose(arquivo);

    return tempo_total / lista_quantidade_nos(lista);
}

int main(int argc, char* argv[]) {
    No* lista_nao_ordenada = NULL;
    No* lista_ordenada = NULL;

    // Leitura do arquivo e inserção nas listas
    FILE* arquivo = fopen(FILENAME, "r");
    float valor;

    while (fscanf(arquivo, "%f", &valor) == 1) {
        lista_inserir_no(&lista_nao_ordenada, no(valor, NULL));
        lista_inserir_no_ordenado(&lista_ordenada, no(valor, NULL));
    }

    fclose(arquivo);

    // Cálculo e exibição do tempo médio de inserção
    double tempo_medio_nao_ordenada = calcular_tempo_medio_insercao(lista_nao_ordenada);
    double tempo_medio_ordenada = calcular_tempo_medio_insercao(lista_ordenada);

    printf("Tempo médio de inserção em lista não ordenada: %lf segundos\n", tempo_medio_nao_ordenada);
    printf("Tempo médio de inserção em lista ordenada: %lf segundos\n", tempo_medio_ordenada);

    // Liberação de memória
    lista_liberar(lista_nao_ordenada);
    lista_liberar(lista_ordenada);

    return 0;
}

    exit(0);
}