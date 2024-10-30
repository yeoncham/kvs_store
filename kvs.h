#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_LEVEL 15

typedef struct node {
    char key[100]; // 노드의 키 값을 저장(최대 100자)
    char* value; // 노드의 값을 저장(동적 메모리 할당된 문자열 포인터)
    struct node* next[MAX_LEVEL]; // 각 레벨에서 다음 노드를 가리키는 포인터 배열
    int level; // 현재 노드가 속한 레벨의 수
} node_t;

typedef struct kvs {
    struct node* head; // skip list의 헤드 노드를 가리키는 포인터
    int items; // 현재 저장소에 저장된 키-값 쌍의 개수
} kvs_t;

kvs_t* open();
int close(kvs_t* kvs);
int put(kvs_t* kvs, const char* key, const char* value);
char* get(kvs_t* kvs, const char* key);
int randLevel();
