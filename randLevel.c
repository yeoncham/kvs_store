#include "kvs.h"
#include <stdlib.h>
int randLevel() {
    int level = 1;
    float p = 0.5;  // 레벨이 증가할 확률을 50%로 설정
    // 각 레벨에서 무작위 확률을 통해 증가 결정
    while ((float)rand() / RAND_MAX < p && level < MAX_LEVEL) {
        level += 1;
    }
    return level;
}

