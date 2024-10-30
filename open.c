#include "kvs.h"
#include <stdlib.h>
#include <stdio.h>
// 키-값 저장소를 초기화하고 kvs_t 구조체의 포인터를 반환:
kvs_t* open() {
    kvs_t* kvs = (kvs_t*)malloc(sizeof(kvs_t));
    if (!kvs) {
        return NULL;
    }
    kvs->head = (node_t*)malloc(sizeof(node_t));
    if (!kvs->head) {
        free(kvs);
        return NULL;
    }
    kvs->head->level = MAX_LEVEL;
    for (int i = 0; i < MAX_LEVEL; i++) {
        kvs->head->next[i] = NULL;
    }
    kvs->items = 0;
    return kvs;
}
