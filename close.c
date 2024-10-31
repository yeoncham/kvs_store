#include "kvs.h"
#include <stdlib.h>
int close(kvs_t* kvs) {
    // kvs_t 구조체와 연관된 모든 메모리를 해제
    if (kvs == NULL) 
	    return -1;
    node_t* current = kvs->head;
    while (current) {
        node_t* next = current->next[0];
        free(current->value);
        free(current);
        current = next;
    }
    free(kvs);
    return 0;
}
