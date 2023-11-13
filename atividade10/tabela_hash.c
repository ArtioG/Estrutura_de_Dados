// tabela_hash.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela_hash.h"

EntradaTabelaHash tabela[TABLE_SIZE];

void inicializar_tabela_hash() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        tabela[i].chave = NULL;
        tabela[i].dado = NULL;
    }
}

int hash(char* chave) {
    // Função de hash simples para converter a chave em um índice
    int hash = 0;
    for (int i = 0; chave[i] != '\0'; i++) {
        hash += chave[i];
    }
    return hash % TABLE_SIZE;
}

char* hash_table_get(char* chave) {
    int indice = hash(chave);
    if (tabela[indice].chave != NULL && strcmp(tabela[indice].chave, chave) == 0) {
        return tabela[indice].dado;
    }
    return NULL;
}

void hash_table_put(char* chave, char* dado) {
    int indice = hash(chave);
    tabela[indice].chave = strdup(chave);
    tabela[indice].dado = strdup(dado);
}

int hash_table_contains(char* chave) {
    int indice = hash(chave);
    return (tabela[indice].chave != NULL && strcmp(tabela[indice].chave, chave) == 0);
}

void hash_table_remove(char* chave) {
    int indice = hash(chave);
    if (tabela[indice].chave != NULL) {
        free(tabela[indice].chave);
        free(tabela[indice].dado);
        tabela[indice].chave = NULL;
        tabela[indice].dado = NULL;
    }
}
