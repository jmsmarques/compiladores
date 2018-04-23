#include "structs.h"

char* checkVarType(char* string) {
    char* aux = NULL;
    if(*string == 'I' || *string == 'i') {
        if(*(string + 1) == 'd') {
            aux = strdup("Id");
        }
        else {
            aux = strdup("int");
        }
    }
    else if(*string == 'C' || *string == 'c') {
        aux = strdup("int");
    }
    else if(*string == 'R' || *string == 'r') {
        aux = strdup("real");
    }
    if(aux)
        return aux;
    else
        return string;
}

void annoteTree(node root, gTable symTab, table auxSymTab) {
    if(root && !root->type) {
        if(strcmp(checkVarType(root->tag), "Id") == 0) {
            if(analiseFuncId(root, root->tag, symTab)) {
                analiseVarId(root, symTab, auxSymTab);
            }
        }
        else if(strcmp(root->tag, "Call") == 0 || strcmp(root->tag, "Store") == 0){
            annoteTree(root->child, symTab, auxSymTab);
            root->type = checkVarType(root->child->type);
        }
    }       
}

int analiseFuncId(node root, char* id, gTable symTab) {
    char* aux;
    aux = removeId(id);
    
    while(symTab) {
        if(strcmp(symTab->tag, aux) == 0) {
            if(symTab->params) {
                root->type = annoteFuncParams(symTab);
                return 0;
            }
            else {
                free(aux);
                return 1;
            }
        }
        symTab = symTab->next;
    }
    free(aux);
    return 1;
}   

void analiseVarId(node root, gTable symTab, table auxSymTab) {
    char* aux;
    aux = removeId(root->tag);

    while(auxSymTab) {
        if(strcmp(auxSymTab->tag, aux) == 0) {
            root->type = strdup(auxSymTab->type);
            return;
        }
        auxSymTab = auxSymTab->next;
    }

    while(symTab) {
        if(strcmp(symTab->tag, aux) == 0) {
            root->type = strdup(symTab->type);
            return;
        }
        symTab = symTab->next;
    }

    //id nao declarado
}

char* annoteFuncParams(gTable symTab) {
    char* aux;
    table auxParam = symTab->params;
    aux = (char*)malloc((strlen(symTab->type) + 2) * sizeof(char));
    sprintf(aux, "%s(", symTab->type);
    while(auxParam) {
        aux = (char*)realloc(aux, (strlen(aux) + strlen(auxParam->type) + 4) * sizeof(char));
        if(auxParam->next) {
        sprintf(aux, "%s%s, ", aux, auxParam->type);
        }
        else {
            sprintf(aux, "%s%s", aux, auxParam->type);
        }
        auxParam = auxParam->next;
    }
    sprintf(aux, "%s)", aux);
    
    return aux;
}

void printAnnotedTree(node root, int level) {
    int aux;
    if(root == NULL) {
        return;
    }
    else {
        for(aux = 0; aux < level; aux++) {
            printf("..");
        }
        if(root->type) {
            printf("%s - %s\n", root->tag, root->type);
        }
        else {
            printf("%s\n", root->tag);
        }
    }
    printAnnotedTree(root->child, level + 1);
    printAnnotedTree(root->sibling, level);

    free(root->tag);
    free(root->type);
    free(root->child);
    free(root->sibling);
}