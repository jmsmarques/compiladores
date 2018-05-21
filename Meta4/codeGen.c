#include "structs.h"

void codeGeneration(node root, gTable symTab, table auxSymTab) {
    if(!root)
        return;
    int aux;
    aux = generateCode(root, symTab, auxSymTab);
    if(aux) //only goes to child if node didnt correspond to any if in generateCode
        codeGeneration(root->child, symTab, auxSymTab);
    codeGeneration(root->sibling, symTab, auxSymTab);

}

int generateCode(node root, gTable symTab, table auxSymTab) {
    if(strcmp(root->tag, "Declaration") == 0) {
        genGlobalDeclaration(root);   
    }
    else if(strcmp(root->tag, "FuncDeclaration") == 0) {
        printf("declare\n");
    }
    else if(strcmp(root->tag, "FuncDefinition") == 0) {
        printf("define\n");
    }
    else {
        return 1;
    }
    return 0;
}

void genGlobalDeclaration(node root) {
    char* code = NULL;
    char* type = getLlvmType(root->child->tag);
    
    code = (char*)malloc((strlen(root->child->sibling->tag) + strlen(type) + 30) * sizeof(char));
    if(!root->child->sibling->sibling) { //if declaration doesnt have definition
        sprintf(code, "@%s = common global %s 0, align %c", removeId(root->child->sibling->tag), type, getLlvmSize(root->child->tag));
    }
    else { //declaration has definition
sprintf(code, "@%s = global %s %s, align %c", removeId(root->child->sibling->tag), type, genDecAtribution(root->child->sibling->sibling), getLlvmSize(root->child->tag));
    }
    printf("%s\n", code);
    free(code);
}

char* genDecAtribution(node root) {
    return extractLiteral(root->tag);
}

char* getLlvmType(char* string) {
    char* aux = NULL;
    if(!string)
        return NULL;

    string = lowerCase(string);

    if(strncmp(string, "int", 3) == 0) {
        aux = strdup("i32");
    }
    else if(strncmp(string, "double", 6) == 0 || strncmp(string, "void", 4) == 0) {
        aux = strdup(string);
    }
    else if(strncmp(string, "char", 4) == 0) {
        aux = strdup("i8");
    }
    else if(strncmp(string, "short", 5) == 0) {
        aux = strdup("i16");
    }
  
    return aux;
}

char getLlvmSize(char* string) {
    char aux = '0';
    if(!string)
        return '0';

    string = lowerCase(string);

    if(strncmp(string, "int", 3) == 0) {
        aux = '4';
    }
    else if(strncmp(string, "double", 6) == 0) {
        aux = '8';
    }
    else if(strncmp(string, "char", 4) == 0) {
        aux = '1';
    }
    else if(strncmp(string, "short", 5) == 0) {
        aux = '2';
    }
  
    return aux;
}

char* extractLiteral(char* string) {
    char* aux = NULL;
    int len = 0;

    if(!string)
        return NULL;

    if(strncmp(string, "Real", 4) == 0) {
        len = 8;
        aux = reduceString(string, len, len + 1);
    }
    else if(strncmp(string, "Int", 3) == 0) {
        len = 7;
        aux = reduceString(string, len, len + 1);
    }
    else if(strncmp(string, "Chr", 3) == 0) {
        len = 8;
        aux = reduceString(string, len, len + 2);
        //transforms char to ascii
        int transform = *aux;
        sprintf(aux, "%d", transform);
    }

    return aux;
}

char* reduceString(char* string, int len, int end) {
    char* aux = (char*)malloc((strlen(string) - len) * sizeof(char));
    strncpy(aux, string + len, (strlen(string) - end) * sizeof(char));
    *(aux + strlen(string) - end) = '\0';

    return aux;
}