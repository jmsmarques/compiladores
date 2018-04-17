#include "structs.h"

table startTable() {
    table symTab;
    symTab = createSymbol("==== Global Symbol Table ====");
    insertInTable(symTab, "putchar\tint(int)");
    insertInTable(symTab, "getchar\tint(void)");
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

void startAuxTable(table root, char* tagValue, char* ret) {
    char* aux = NULL;
    while(root->next) {
        root = root->next;
    }
    aux = (char*)malloc((strlen(ret) + strlen("return ") + 1) * sizeof(char));
    turnLowerCase(ret);
    sprintf(aux, "return\t%s", ret);
    root->next = createSymbol(tagValue);
    root->next->next = createSymbol(aux);
    root->next->next->next = createSymbol("");

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
        char* aux = NULL;
        char* aux1 = NULL;
        char* aux2 = NULL;
        //table tabAux = NULL;

        if(strcmp(root->tag, "FuncDeclaration") == 0) {
            aux1 = getParamList(root->child->sibling->sibling->child);
            aux2 = removeId(root->child->sibling->tag);
            aux = (char*)malloc((strlen(root->child->tag) + strlen(aux2) + strlen(aux1) + 4) * sizeof(char));
            sprintf(aux, "%s\t%s(%s)", aux2, root->child->tag, aux1);
            turnLowerCase(aux);
            insertInTable(symTab, aux);
            if(strcmp(root->child->tag, "void") != 0) {
                aux2 = (char*)realloc(aux2, (strlen(aux2) + 33) * sizeof(char));
                sprintf(aux2, "==== Function %s Symbol Table ====", strdup(aux2));
                startAuxTable(auxSymTab, aux2, root->child->tag);
            }
            free(aux1);
            free(aux2);
        }
        else if(strcmp(root->tag, "FuncDefinition") == 0) {
            /*aux2 = removeId(root->child->sibling->tag);
            tabAux = checkDeclaration(symTab, aux2);
            if(tabAux != NULL) {

            }
            else {

            }
            free(tabAux);*/
        }
    }
}

void printTable(table root) {
    if(root) {
        printf("%s\n", root->tag);
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

table checkDeclaration(table symTab, char* dec) {
    if(symTab == NULL) {
        return NULL;
    }
    else if(strcmp(dec, symTab->tag) == 0) {
        return symTab;
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