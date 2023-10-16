#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

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

    exit(0);
}