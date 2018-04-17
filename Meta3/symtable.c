#include "structs.h"

table startTable() {
    table symTab;
    symTab = createSymbol("==== Global Symbol Table ====", "");
    insertInTable(symTab, "putchar", "int(int)");
    insertInTable(symTab, "getchar", "int(void)");
    return symTab;
}

table createSymbol(char* tagValue, char* typeValue) {
    table aux = (table)malloc(sizeof(sym_table));
    aux->tag = (char*)malloc((strlen(tagValue) + 1) * sizeof(char));
    strcpy(aux->tag, tagValue);
    aux->type = (char*)malloc((strlen(typeValue) + 1) * sizeof(char));
    strcpy(aux->type, typeValue);
    aux->next = NULL;
    return aux;
}

void insertInTable(table root, char* tagValue, char* typeValue) {
    while(root->next) {
        root = root->next;
    }
    root->next = createSymbol(tagValue, typeValue);
}

void startAuxTable(table root, char* tagValue, char* ret) {
    while(root->next) {
        root = root->next;
    }
    turnLowerCase(ret);
    root->next = createSymbol(tagValue, "");
    root->next->next = createSymbol("return", ret);
    root->next->next->next = createSymbol("", "");
}

table insertInAuxTable(table root, char* tagValue, table node) {
    while(root) {
        if(strcmp(root->tag, tagValue) == 0) {
            while(strcmp(root->next->tag, "") != 0) {
                root = root->next;
            }
            node->next = root->next;
            root->next = node;
            return node;
        }
        root = root->next;
    }
    return NULL;
}

char* getParamList(node root) {
    char* aux;
    aux = (char*)malloc(strlen(root->tag) * sizeof(char) + 1);
    strcpy(aux, root->child->tag);

    if(root->child->sibling) {
        aux = (char*)realloc(aux, (strlen(aux) + strlen(root->child->sibling->tag) + 2) * sizeof(char));
        sprintf(aux, "%s\t%s", aux, removeId(root->child->sibling->tag));
    }
    while(root->sibling) {
        root = root->sibling;
        aux = (char*)realloc(aux, (strlen(aux) + strlen(root->child->tag) + 3) * sizeof(char));
        sprintf(aux, "%s, %s", aux, root->child->tag);
        if(root->child->sibling) {
            aux = (char*)realloc(aux, (strlen(aux) + strlen(root->child->sibling->tag) + 2) * sizeof(char));
            sprintf(aux, "%s\t%s", aux, removeId(root->child->sibling->tag));
        }
    }
    return aux;
}

void checkFuncDec(node root, table symTab, table auxSymTab) {
    if(root) {
        table tabAux = NULL;
        char* aux = NULL;

        if(strcmp(root->tag, "FuncDeclaration") == 0) {
            analiseFuncDec(root, symTab, auxSymTab);
        }
        else if(strcmp(root->tag, "FuncDefinition") == 0) {
            aux = removeId(root->child->sibling->tag);
            if(checkDeclaration(symTab, aux)) {

            }
            else {
                analiseFuncDec(root, symTab, auxSymTab);
            }
            free(tabAux);
        }
    }
}

void analiseFuncDec(node root, table symTab, table auxSymTab) {
    char* aux;
    char* aux1;
    char* aux2;

    aux2 = removeId(root->child->sibling->tag);
    aux1 = getParamList(root->child->sibling->sibling->child);
    aux = (char*)malloc((strlen(root->child->tag) + strlen(aux1) + 4) * sizeof(char));
    sprintf(aux, "%s(%s)", root->child->tag, aux1);
    turnLowerCase(aux);
    turnLowerCase(aux2);
    insertInTable(symTab, aux2, aux);
    if(strcmp(root->child->tag, "void") != 0) {
        aux2 = (char*)realloc(aux2, (strlen(aux2) + 33) * sizeof(char));
        sprintf(aux2, "==== Function %s Symbol Table ====", strdup(aux2));
        startAuxTable(auxSymTab, aux2, root->child->tag);
    }

    free(aux1);
    free(aux2);
}

void printTable(table root) {
    if(root) {
        printf("%s\t%s\n", root->tag, root->type);
        printTable(root->next);
        free(root->tag);
        free(root);
    }
}

void turnLowerCase(char* string) {
    while(*string) {
        if(*string >= 'A' && *string <= 'Z') {
            *string = *string + 32;
        }
        string++;
    }
}

int checkDeclaration(table symTab, char* dec) {
    if(symTab == NULL) {
        return 0;
    }
    else if(strcmp(dec, symTab->tag) == 0) {
        return 1;
    }
    else {
        return checkDeclaration(symTab->next, dec);
    }
}

char* removeId(char* id) {
    char* aux = (char*)malloc((strlen(id) - 3) * sizeof(char));;
    strncpy(aux, id + 3, (strlen(id) - 4) * sizeof(char));
    *(aux + strlen(id) - 4) = '\0';
    return aux;
}

void checkSemantics(node root, table symTab, table auxSymTab) {
    if(!root) {
        return;       
    }
    checkFuncDec(root, symTab, auxSymTab);
    checkSemantics(root->child, symTab, auxSymTab);
    checkSemantics(root->sibling, symTab, auxSymTab);
}