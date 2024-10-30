#include "kvs.h"
#include <stdlib.h>
#include <string.h>
int put(kvs_t* kvs, const char* key, const char* value) {
    // 주어진 키와 값을 저장소에 삽입하거나, 이미 존재하는 키라면 값을 업데이트
    if (!kvs || !key || !value) 
	    return -1;
    node_t* current = kvs->head;
    node_t* update[MAX_LEVEL];
    for (int level = MAX_LEVEL - 1; level >= 0; level--) {
        while (current->next[level] && strcmp(current->next[level]->key, key) < 0) {
            current = current->next[level];
        }
        update[level] = current;
    }
    current = current->next[0];
    if (current && strcmp(current->key, key) == 0) {
        free(current->value);
        current->value = strdup(value);
        return 0;
    }
    int level = randLevel();
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    if (!new_node) 
	    return -1;
    strcpy(new_node->key, key);
    new_node->value = strdup(value);
    new_node->level = level;
    for (int i = 0; i < level; i++) {
        new_node->next[i] = update[i]->next[i];
        update[i]->next[i] = new_node;
    }
    kvs->items++;
    return 0;
}


