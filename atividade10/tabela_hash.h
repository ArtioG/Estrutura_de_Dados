// tabela_hash.h
#ifndef TABELA_HASH_H
#define TABELA_HASH_H

#define TABLE_SIZE 100 // Tamanho da tabela hash, você pode ajustar conforme necessário

typedef struct {
    char* chave;
    char* dado;
} EntradaTabelaHash;

void inicializar_tabela_hash();
char* hash_table_get(char* chave);
void hash_table_put(char* chave, char* dado);
int hash_table_contains(char* chave);
void hash_table_remove(char* chave);

#endif
