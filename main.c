#include "kvs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    kvs_t* kvs = open();
    if (kvs == NULL) {
        return -1;
    }
    FILE *inputFile = fopen("query.dat", "r");
    FILE *outputFile = fopen("answer.dat", "w");
    if (inputFile == NULL || outputFile == NULL) {
        close(kvs);
        return -1;
    }
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), inputFile)) {
        char operation[10], key[100], value[100];
        int result;
        operation[0] = '\0';
	key[0] = '\0'; 
	value[0] = '\0';
        int tokenCount = sscanf(buffer, "%9[^,],%99[^,],%99s", operation, key, value);
        if (tokenCount < 2) {
            continue;
        }
        if (strcmp(operation, "set") == 0 && tokenCount == 3) {
            result = put(kvs, key, value);
            if (result == -1) {
                fprintf(outputFile, "%s\n", key);
            }
        } else if (strcmp(operation, "get") == 0 && tokenCount >= 2) {
            char* returnValue = get(kvs, key);
            if (returnValue) {
                fprintf(outputFile, "%s\n", returnValue);
                free(returnValue);
            } else {
                fprintf(outputFile, "-1\n");
            }
        }
    }
    fclose(inputFile);
    fclose(outputFile);
    close(kvs);
    return 0;
}

