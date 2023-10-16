#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

No* no(char valor, No* proximo_no) {
    No* no = malloc(sizeof(No));
    no->valor = valor;
    no->proximo_no = proximo_no;
    return no;
}

void lista_inserir_no(No* L, No* no) {
    if (L != NULL) {
        if (L->proximo_no == NULL) {
            L->proximo_no = no;
        } else {
            lista_inserir_no(L->proximo_no, no);
        }
    }
}

void lista_imprimir(No* L) {
    if (L != NULL) {
        printf("%c ", L->valor);
        lista_imprimir(L->proximo_no);
    }
}

int lista_quantidade_nos(No* L) {
    if (L != NULL) {
        return 1 + lista_quantidade_nos(L->proximo_no);
    }
    return 0;
}

No* lista_copiar(No* L) {
    if (L != NULL) {
        return no(L->valor, lista_copiar(L->proximo_no));
    }
    return NULL;
}

void lista_concatenar(No* L, No* Lc) {
    lista_inserir_no(L, Lc);
}

void lista_liberar(No* L) {
    if (L != NULL) {
        lista_liberar(L->proximo_no);
        free(L);
    }
}

int lista_verificar_existencia(No* L, char valor_busca) {
    while (L != NULL) {
        if (L->valor == valor_busca) {
            return 1; // Valor encontrado
        }
        L = L->proximo_no;
    }
    return 0; // Valor não encontrado
}

int lista_verificar_ocorrencias(No* L, char valor_busca) {
    int ocorrencias = 0;
    while (L != NULL) {
        if (L->valor == valor_busca) {
            ocorrencias++;
        }
        L = L->proximo_no;
    }
    return ocorrencias;
}

void lista_imprimir_inversa(No* L) {
    if (L != NULL) {
        lista_imprimir_inversa(L->proximo_no);
        printf("%c ", L->valor);
    }
}

void lista_inserir_no_i(No* L, int i) {
    if (i < 0) {
        printf("Posição inválida\n");
        return;
    }

    while (L != NULL && i > 0) {
        L = L->proximo_no;
        i--;
    }

    if (i == 0) {
        // L está na posição desejada
        // Criar um novo nó e inserir após L
        No* novo_no = no('N', L->proximo_no);
        L->proximo_no = novo_no;
    } else {
        printf("Posição inválida\n");
    }
}

void lista_remover_no_i(No* L, int i) {
    if (i < 0) {
        printf("Posição inválida\n");
        return;
    }

    while (L != NULL && i > 1) {
        L = L->proximo_no;
        i--;
    }

    if (i == 1 && L != NULL && L->proximo_no != NULL) {
        // L está no nó anterior ao desejado
        // Remover o nó seguinte
        No* no_remover = L->proximo_no;
        L->proximo_no = L->proximo_no->proximo_no;
        free(no_remover);
    } else {
        printf("Posição inválida\n");
    }
}

void lista_remover_no(No* L, char valor_busca) {
    No* anterior = NULL;
    No* atual = L;

    while (atual != NULL) {
        if (atual->valor == valor_busca) {
            if (anterior == NULL) {
                // Remover o primeiro nó
                L = atual->proximo_no;
            } else {
                // Remover nó no meio ou final
                anterior->proximo_no = atual->proximo_no;
            }

            free(atual);
            atual = NULL; // Ajustar para evitar problemas de uso após liberar memória
            atual = L; // Mover para o próximo nó após a remoção
        } else {
            anterior = atual;
            atual = atual->proximo_no;
        }
    }
}

void lista_inserir_no_ordenado(No* L, No* no) {
    // Verificar se a lista está vazia ou o valor do primeiro nó é maior que o valor do nó a ser inserido
    if (L == NULL || L->valor > no->valor) {
        no->proximo_no = L;
        L = no;
    } else {
        No* atual = L;
        No* anterior = NULL;

        // Encontrar a posição correta para inserção
        while (atual != NULL && atual->valor < no->valor) {
            anterior = atual;
            atual = atual->proximo_no;
        }

        // Inserir o nó na posição correta
        no->proximo_no = atual;
        anterior->proximo_no = no;
    }
}