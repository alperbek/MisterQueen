#include <stdlib.h>
#include <string.h>
#include "table.h"

void table_alloc(Table *table, int bits) {
    table->size = 1 << bits;
    table->mask = table->size - 1;
    table->data = calloc(table->size, sizeof(Entry));
}

void table_free(Table *table) {
    free(table->data);
}

Move *table_get_move(Table *table, bb key) {
    Entry *entry = TABLE_ENTRY(table, key);
    if (entry->key == key) {
        return &entry->move;
    }
    return NULL;
}

void table_set_move(Table *table, bb key, int depth, Move *move) {
    Entry *entry = TABLE_ENTRY(table, key);
    if (entry->depth <= depth) {
        entry->key = key;
        entry->depth = depth;
        memcpy(&entry->move, move, sizeof(Move));
    }
}

void table_set(Table *table, bb key, int depth, int value, int flag) {
    Entry *entry = TABLE_ENTRY(table, key);
    if (entry->depth <= depth) {
        entry->key = key;
        entry->depth = depth;
        entry->value = value;
        entry->flag = flag;
    }
}

int table_get(Table *table, bb key, int depth, int alpha, int beta, int *value) {
    Entry *entry = TABLE_ENTRY(table, key);
    if (entry->key == key && entry->depth >= depth) {
        // if ((entry->flag == TABLE_EXACT) ||
        //     (entry->flag == TABLE_ALPHA && entry->value <= alpha) ||
        //     (entry->flag == TABLE_BETA && entry->value >= beta))
        if (entry->flag == TABLE_EXACT) {
            *value = entry->value;
            return 1;
        }
    }
    return 0;
}
