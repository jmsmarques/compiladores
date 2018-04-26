#include "structs.h"

char* checkVarType(char* string) {
    char* aux = NULL;
    if(!string)
        return NULL;
    if((strncmp(string, "IntLit", 6) == 0) || (strncmp(string, "int", 3) == 0)) {
        aux = strdup("int");
    }
    else if(strncmp(string, "ChrLit", 6) == 0) {
        aux = strdup("int");
    }
    else if(strncmp(string, "RealLit", 7) == 0 || strncmp(string, "double", 6) == 0) {
        aux = strdup("double");
    }
    else if(strncmp(string, "char", 4) == 0) {
        aux = strdup("char");
    }
    else if(strncmp(string, "void", 4) == 0) {
        aux = strdup("void");
    }
    if(aux)
        return aux;
    return NULL;
}

void annoteTree(node root, gTable symTab, table auxSymTab) {
    if(root && !root->type) {
        if(checkIfId(root->tag)) {
            if(analiseFuncId(root, root->tag, symTab)) {
                analiseVarId(root, symTab, auxSymTab);
            }
        }
        else if(strcmp(root->tag, "Call") == 0 || strcmp(root->tag, "Store") == 0) {
            annoteTree(root->child, symTab, auxSymTab);
            root->type = checkVarType(root->child->type);
        }
        else if(checkIfOperation(root->tag)) {
            root->type = strdup("int");
        }
        else {
            root->type = checkVarType(root->tag);
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
            free(aux);
            return;
        }
        auxSymTab = auxSymTab->next;
    }

    while(symTab) {
        if(strcmp(symTab->tag, aux) == 0) {
            root->type = strdup(symTab->type);
            free(aux);
            return;
        }
        symTab = symTab->next;
    }
    free(aux);
    //id nao declarado
}

char* annoteFuncParams(gTable symTab) { //anota parametros de uma funcao
    char* aux;
    table auxParam = symTab->params;
    aux = (char*)malloc((strlen(symTab->type) + 2) * sizeof(char));
    sprintf(aux, "%s(", symTab->type);
    while(auxParam) {
        aux = (char*)realloc(aux, (strlen(aux) + strlen(auxParam->type) + 4) * sizeof(char));
        if(auxParam->next) {
        sprintf(aux, "%s%s,", aux, auxParam->type);
        }
        else {
            sprintf(aux, "%s%s", aux, auxParam->type);
        }
        auxParam = auxParam->next;
    }
    sprintf(aux, "%s)", aux);
    
    return aux;
}

int checkIfOperation(char* string) {
    if((strcmp(string, "Mul") == 0) || (strcmp(string, "Add") == 0) 
    || (strcmp(string, "Sub") == 0) || (strcmp(string, "Minus") == 0) 
    || (strcmp(string, "Mod") == 0) || (strcmp(string, "Div") == 0)
    || (strcmp(string, "Plus") == 0) || (strcmp(string, "Not") == 0)
    || (strcmp(string, "And") == 0) || (strcmp(string, "Or") == 0)
    || (strcmp(string, "BitWiseOr") == 0) || (strcmp(string, "BitWiseXor") == 0)
    || (strcmp(string, "BitWiseAnd") == 0) || (strcmp(string, "Comma") == 0)
    || (strcmp(string, "Le") == 0) || (strcmp(string, "Ge") == 0)
    || (strcmp(string, "Eq") == 0) || (strcmp(string, "Ne") == 0)
    || (strcmp(string, "Lt") == 0) || (strcmp(string, "Gt") == 0)
    || (strcmp(string, "Le") == 0) || (strcmp(string, "Ge") == 0)) {
        return 1;
    }
    else {
        return 0;
    }
}

int checkIfId(char* string) {
    if(strncmp(string, "Id", 2) == 0) {
        return 1;
    }
    return 0;
}

void annotedDecOp(node root, gTable symTab, table auxSymTab) {
    if(!root)
        return;
    if(checkIfOperation(root->tag)) {
        root->type = strdup("int");
        annotedDecOp(root->child, symTab, auxSymTab);
        annotedDecOp(root->child->sibling, symTab, auxSymTab);
    }
    else if(checkIfId(root->tag)) {
        if(analiseFuncId(root, root->tag, symTab)) {
            analiseVarId(root, symTab, auxSymTab);
        }
    }
    else if(strcmp(root->tag, "Call") == 0 || strcmp(root->tag, "Store") == 0) {
        annoteTree(root->child, symTab, auxSymTab);
        root->type = checkVarType(root->child->type);
        annotedDecOp(root->child, symTab, auxSymTab);
        annotedDecOp(root->child->sibling, symTab, auxSymTab);
    }
    else {
        root->type = checkVarType(root->tag);
    }
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