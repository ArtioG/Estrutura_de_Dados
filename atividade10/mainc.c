// main.c
#include <stdio.h>
#include "tabela_hash.h"

int main() {
    inicializar_tabela_hash();

    hash_table_put("chave1", "dado1");
    hash_table_put("chave2", "dado2");
    hash_table_put("chave3", "dado3");

    printf("Dado associado à chave1: %s\n", hash_table_get("chave1"));

    if (hash_table_contains("chave2")) {
        printf("A tabela contém a chave2.\n");
    } else {
        printf("A tabela não contém a chave2.\n");
    }

    hash_table_remove("chave3");

    if (hash_table_contains("chave3")) {
        printf("A tabela contém a chave3.\n");
    } else {
        printf("A tabela não contém a chave3.\n");
    }

    return 0;
}
