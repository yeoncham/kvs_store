#include "kvs.h"
#include <string.h>
#include <stdlib.h>
char* get(kvs_t* kvs, const char* key) {
    // 주어진 키에 대응하는 값을 찾음
    if (kvs == NULL || key == NULL) 
	    return NULL;
    node_t* current = kvs->head;
    for (int level = MAX_LEVEL - 1; level >= 0; level--) {
        while (current->next[level] && strcmp(current->next[level]->key, key) < 0) {
            current = current->next[level];
        }
    }
    current = current->next[0];
    if (current && strcmp(current->key, key) == 0) {
        return strdup(current->value);
    }
    return NULL;
}

