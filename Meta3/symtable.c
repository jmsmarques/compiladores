#include "structs.h"

table createSymbol(char* tagValue) {
    table aux = (table)malloc(sizeof(sym_table));
    aux->tag = (char*)malloc((strlen(tagValue) + 1) * sizeof(char));
    strcpy(aux->tag, tagValue);
    return aux;
}

void printTable(table root, char* type) {
    printf("%s\n", type);
    while(root) {
        printf("%s\n", root->tag);
        root = root->next;
    }
}