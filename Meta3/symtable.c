#include "structs.h"

table startTable() {
    table symTab;
    symTab = createSymbol("==== Global Symbol Table ====");
    insertInTable(symTab, "putchar int(int)");
    insertInTable(symTab, "getchar int(void)");
    return symTab;
}

table createSymbol(char* tagValue) {
    table aux = (table)malloc(sizeof(sym_table));
    aux->tag = (char*)malloc((strlen(tagValue) + 1) * sizeof(char));
    strcpy(aux->tag, tagValue);
    aux->next = NULL;
    return aux;
}

void insertInTable(table root, char* tagValue) {
    while(root->next) {
        root = root->next;
    }
    root->next = createSymbol(tagValue);
}

void printTable(table root) {
    while(root) {
        printf("%s\n", root->tag);
        root = root->next;
    }
}