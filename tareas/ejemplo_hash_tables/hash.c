#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

typedef struct {
    char* key;
    int value;
} HashItem;

typedef struct {
    HashItem* items[TABLE_SIZE];
} HashTable;

unsigned int hash(const char* key) {
    unsigned long int value = 0;
    unsigned int i = 0;
    unsigned int key_len = strlen(key);

    for (; i < key_len; ++i) {
        value = value * 37 + key[i];
    }

    printf("%lu - %s - %lu\n", value, key, value % TABLE_SIZE);
    value = value % TABLE_SIZE;
    return value;
}

HashTable* create_table() {
    HashTable* table = (HashTable*) malloc(sizeof(HashTable));
    for (int i = 0; i < TABLE_SIZE; i++) {
        table->items[i] = NULL;
    }
    return table;
}

void insert(HashTable* table, const char* key, int value) {
    unsigned int index = hash(key);

    // TODO: Colocar un sondeo cuadrático

    HashItem* item = (HashItem*) malloc(sizeof(HashItem));
    item->key = strdup(key);
    item->value = value;
    table->items[index] = item;
}

int search(HashTable* table, const char* key) {
    unsigned int index = hash(key);
    HashItem* item = table->items[index];
    if (item != NULL && strcmp(item->key, key) == 0) {
        return item->value;
    }
    return -1;  // Key not found
}

void delete(HashTable* table, const char* key) {
    unsigned int index = hash(key);
    HashItem* item = table->items[index];
    if (item != NULL && strcmp(item->key, key) == 0) {
        free(item->key);
        free(item);
        table->items[index] = NULL;
    }
}

void free_table(HashTable* table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        HashItem* item = table->items[i];
        if (item != NULL) {
            free(item->key);
            free(item);
        }
    }
    free(table);
}

void print_table(HashTable* table) {
    printf("+----------------------+-------+\n");
    printf("| Key                  | Value |\n");
    printf("+----------------------+-------+\n");

    for (int i = 0; i < TABLE_SIZE; i++) {
        HashItem* item = table->items[i];
        if (item != NULL) {
            printf("| %-20s | %5d |\n", item->key, item->value);
        }
    }

    printf("+----------------------+-------+\n");
}

int main() {
    HashTable* table = create_table();
    
    insert(table, "manzana", 5);
    insert(table, "platano", 8);
    insert(table, "durazno", 13);
    insert(table, "naranja", 1);

    print_table(table);

    printf("Value for key2: %d\n", search(table, "manzana2"));
    printf("Value for key3: %d\n", search(table, "platano"));

    delete(table, "manzana");
    printf("Value for key2 after deletion: %d\n", search(table, "manzana"));

    free_table(table);
    return 0;
}