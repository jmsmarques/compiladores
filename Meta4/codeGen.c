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
        //genFuncDec(root, "declare");
        //printf("\n\n");
    }
    else if(strcmp(root->tag, "FuncDefinition") == 0) {
        genFuncDef(root);
    }
    else {
        return 1;
    }
    return 0;
}

void genGlobalDeclaration(node root) {
    /*char* code = NULL;
    char* type = getLlvmType(root->child->tag);
    
    code = (char*)malloc((strlen(root->child->sibling->tag) + strlen(type) + 30) * sizeof(char));
    */
    if(!root->child->sibling->sibling) { //if declaration doesnt have definition
        //sprintf(code, "@%s = common global %s 0, align %c", removeId(root->child->sibling->tag), type, getLlvmSize(root->child->tag));
        printf("@%s = common global %s 0, align %c\n", removeId(root->child->sibling->tag),
        getLlvmType(root->child->tag), getLlvmSize(root->child->tag));
    }
    else { //declaration has definition
        //sprintf(code, "@%s = global %s %s, align %c", removeId(root->child->sibling->tag), type, genDecAtribution(root->child->sibling->sibling), getLlvmSize(root->child->tag));
        printf("@%s = global %s %s, align %c\n", removeId(root->child->sibling->tag), getLlvmType(root->child->tag), 
        extractLiteral(root->child->sibling->sibling->tag, root->child->sibling->sibling->type), 
        getLlvmSize(root->child->tag));
    }
    /*printf("%s\n", code);
    free(code);*/
}

int genFuncBody(node root, int tabs, int variable, char* funcType, int flag) {
    if(!root) 
        return variable;
    int variable1 = variable;
    int variable2 = variable1;
    int aux = 1;
    if(strcmp(root->tag, "Declaration") == 0) {
        doTabs(tabs);
        printf("%%%s = alloca %s, align %c\n", removeId(root->child->sibling->tag), getLlvmType(root->child->tag), getLlvmSize(root->child->tag));
        if(root->child->sibling->sibling)
            variable = genStore(root->child->sibling, getLlvmType(root->child->tag), variable, tabs);
    }
    else if(strcmp(root->tag, "Call") == 0) {
        variable = genCall(root, variable, tabs);            
    }
    else if(strcmp(root->tag, "Store") == 0) {
        variable = genStore(root->child, getLlvmType(root->type), variable, tabs);
    }
    else if(strcmp(root->tag, "If") == 0) {
        variable = generateIf(root, variable, tabs, funcType);
    }
    else if(strcmp(root->tag, "While") == 0) {
        variable = generateWhile(root, variable, tabs, funcType);
    }
    else if(strcmp(root->tag, "Return") == 0) { //esta mal int nao consegue retornar short
        if(strcmp(root->child->tag, "Null") != 0) {
            doTabs(tabs);
            if(checkIfId(root->child->tag) || checkIfUnary(root->child)) {
                variable = genVarToTemp(root->child, getLlvmType(root->child->type), funcType, variable, tabs);
                printf("ret %s %%%d\n", funcType, variable);
                variable++;
            }
            else if(checkIfLiteral(root->child)) {
                printf("ret %s %s\n", funcType, genVariable(root->child, funcType));
            }
            else {
                variable = genExpr(root->child, variable, tabs, getLlvmType(funcType));
                doTabs(tabs);
                printf("ret %s %%%d\n", funcType, variable);
                variable++;
            }
        }
        else {
            if(root->sibling) {
                doTabs(tabs);
                printf("ret void\n");
            }
        }
        return variable * -1;
    }
    else {
        variable1 = genFuncBody(root->child, tabs, variable, funcType, 1);
        aux = 0;
    }
    if(flag)
        variable2 = genFuncBody(root->sibling, tabs, variable, funcType, 1);
    else if(aux) {
        return variable;
    }
    if(variable1 > variable2) {
        return variable1;
    }
    else {
        return variable2;
    }
}

void genFuncDef(node root) {
    genFuncDec(root, "define");
    printf(" {\n");
    label = 1;
    genFuncBody(root->child->sibling->sibling->sibling->child, 1, 1, getLlvmType(root->child->tag), 1);
    if(strcmp(root->child->tag, "Void") == 0) {
        doTabs(1);
        printf("ret void\n");
    }
    
    printf("}\n\n");
}

void genFuncDec(node root, char* type) {
    /*char* code = NULL;
    char* aux = genFuncParams(root->child->sibling->sibling);
    code = (char*)malloc((7 + strlen(root->child->sibling->tag) + strlen(aux)) * sizeof(char));
    sprintf(code, "define %s @%s(%s) #0 {", getLlvmType(root->child->tag), removeId(root->child->sibling->tag), aux);

    printf("%s\n", code);
    free(code);*/
    printf("%s %s @%s(", type, getLlvmType(root->child->tag), removeId(root->child->sibling->tag));
    genFuncParams(root->child->sibling->sibling->child);
    printf(")");
}

void genFuncParams(node root) {
    /*char* params = NULL;

    params = (char*)malloc((strlen(root->child->sibling->tag) + 6) * sizeof(char));
    sprintf(params, "%s %s", getLlvmType(root->child->tag), removeId(root->child->sibling->tag));
    while(root) {
        params = (char*)realloc(params, (strlen(params) + strlen(root->child->sibling->tag) + 7) * sizeof(char));
        sprintf(params, "%s, %s %s", params, getLlvmType(root->child->tag), removeId(root->child->sibling->tag));
        root = root->sibling;
    }
    
    return params;*/
    if(strcmp(root->child->tag, "Void") == 0)
        return;

    if(root->child->sibling)
        printf("%s %%%s", getLlvmType(root->child->tag), removeId(root->child->sibling->tag));
    else
        printf("%s", getLlvmType(root->child->tag));
    root = root->sibling;
    while(root) {
        if(root->child->sibling)
            printf(", %s %%%s", getLlvmType(root->child->tag), removeId(root->child->sibling->tag));
        else
            printf(", %s", getLlvmType(root->child->tag));
        root = root->sibling;
    }
    return;
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

    if(strncmp(string, "int", 3) == 0 || strncmp(string, "i32", 3) == 0) {
        aux = '4';
    }
    else if(strncmp(string, "double", 6) == 0) {
        aux = '8';
    }
    else if(strncmp(string, "char", 4) == 0 || strncmp(string, "i8", 2) == 0) {
        aux = '1';
    }
    else if(strncmp(string, "short", 5) == 0 || strncmp(string, "i16", 3) == 0) {
        aux = '2';
    }
  
    return aux;
}

char* extractLiteral(char* string, char* type) {
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
        if(strcmp(type, "double") == 0) {
            sprintf(aux, "%s.0", aux);
        }
    }
    else if(strncmp(string, "Chr", 3) == 0) {
        len = 8;
        aux = reduceString(string, len, len + 2);
        //transforms char to ascii
        
        int transform = trasformToAscii(aux);
        sprintf(aux, "%d", transform);
        if(strcmp(type, "double") == 0) {
            sprintf(aux, "%s.0", aux);
        }
    }
    else if(strncmp(string, "Id", 2) == 0) {
        aux = removeId(string);
    }

    return aux;
}

char* reduceString(char* string, int len, int end) {
    char* aux = (char*)malloc((strlen(string)) * sizeof(char));
    strncpy(aux, string + len, (strlen(string) - end) * sizeof(char));
    *(aux + strlen(string) - end) = '\0';

    return aux;
}

void genLogicOperation(char* operatorTag) {
    if(strcmp(operatorTag, "Eq") == 0) {
        printf("eq");
    }
    else if(strcmp(operatorTag, "Gt") == 0) {
        printf("sgt");
    }
    else if(strcmp(operatorTag, "Lt") == 0) {
        printf("slt");
    }
    else if(strcmp(operatorTag, "Ge") == 0) {
        printf("sge");
    }
    else if(strcmp(operatorTag, "Le") == 0) {
        printf("sle");
    }
    else if(strcmp(operatorTag, "Ne") == 0) {
        printf("ne");
    }
}

char* genVariable(node root, char* type) {
    char* aux = NULL;

    if(strcmp(root->tag, "Minus") == 0) {
        if(checkIfId(root->child->tag)) {
            return genVariable(root->child, type);
        }
        else {
            aux = (char*)malloc((strlen(root->child->tag)) * sizeof(char));
            sprintf(aux, "-%s", genVariable(root->child, type));
        }
    }
    else if(strcmp(root->tag, "Plus") == 0) {
        return genVariable(root->child, type);
    }
    else if(strcmp(root->tag, "Not") == 0) {
        if(checkIfId(root->child->tag)) {
            return genVariable(root->child, type);
        }
        else {
            //aux = (char*)malloc((strlen(root->child->tag)) * sizeof(char));
            aux = genVariable(root->child, type);
            if(strcmp(aux, "0") == 0) {
                sprintf(aux, "1");
            }
            else {
                sprintf(aux, "0");
            }
        }
    }
    else if(checkIfId(root->tag)) {
        aux = (char*)malloc((strlen(root->tag) + 8) * sizeof(char));
        sprintf(aux, "%c%s", root->scope, removeId(root->tag));
    }
    else {
        aux = extractLiteral(root->tag, type); //falta tratar doubles
        if(*aux == '0' && strlen(aux) > 1) {
            //printf("octal\n");
            aux = generateOctal(aux);
        }
            
    }

    return aux;
}

void doTabs(int nr) {
    for(int n = 0; n < nr; n++)
        printf("\t");
}

int genStore(node root, char* type, int variable, int tabs) {
    if(!checkIfLiteral(root->sibling)) {
        /*printf("%%%d = load %s, %s* %s, align %c\n", variable, type, 
        type, genVariable(root->sibling), getLlvmSize(type));

        if(checkIfUnary(root->sibling)) {
            variable = genMinusConversion(variable, tabs, type);
        }*/

        variable = genExpr(root->sibling, variable, tabs, type);

        doTabs(tabs);
        printf("store %s %%%d, %s* %s, align %c\n", type, 
        variable, type, genVariable(root, type), getLlvmSize(type));
        variable++;
    }
    else {
        doTabs(tabs);
        printf("store %s %s, %s* %s, align %c\n", type, genVariable(root->sibling, type), 
        type, genVariable(root, type), getLlvmSize(type));
    }
    return variable;
}

int genMinusConversion(int variable, int tabs, char* type) {
    variable++;
    if(strcmp(type, "double") == 0) {
        doTabs(tabs);
        printf("%%%d = fsub double -0.000000e+00, %%%d\n", variable, variable - 1);
    }
    else if(strcmp(type, "i32") == 0) {
        doTabs(tabs);
        printf("%%%d = sub nsw i32 0, %%%d\n", variable, variable - 1);
    }
    else {
        doTabs(tabs);
        printf("%%%d = sext %s %%%d to i32\n", variable, type, variable - 1);
        variable++;
        doTabs(tabs);
        printf("%%%d = sub nsw i32 0, %%%d\n", variable, variable - 1);
        variable++;
        doTabs(tabs);
        printf("%%%d = trunc i32 %%%d to %s\n", variable, variable - 1, type);
    }
    return variable;
}

int genNotConversion(int variable, int tabs, char* type) {
    variable++;
    if(strcmp(type, "double") == 0) {
        doTabs(tabs);
        printf("%%%d = fcmp une double %%%d, 0.0\n", variable, variable - 1);
        variable++;
        doTabs(tabs);
        printf("%%%d = xor i1 %%%d, true\n", variable, variable - 1);
    }
    else {
        doTabs(tabs);
        printf("%%%d = icmp ne %s %%%d, 0\n", variable, type, variable - 1);
        variable++;
        doTabs(tabs);
        printf("%%%d = xor i1 %%%d, true\n", variable, variable - 1);
    }
    return variable;
}

int checkIfUnary(node root) {
    if(strcmp(root->tag, "Minus") == 0 || strcmp(root->tag, "Plus") == 0 || strcmp(root->tag, "Not") == 0) {
        if(checkIfId(root->child->tag)) {
            return 1;
        }
    }
    return 0;
}

int genCall(node root, int variable, int tabs) {
    node params = root->child->sibling;
    char* aux = strdup("");
    doTabs(tabs);
    while(params) {
        if(checkIfId(params->tag) || checkIfUnary(params)) {
            variable = genVarToTemp(params, getLlvmType(params->type), "i32"/*mudar isto*/,variable, tabs);
            aux = (char*)realloc(aux, (strlen(aux) + strlen(params->type) + strlen(params->tag) + 2) * sizeof(char));
            sprintf(aux, "%s%s %%%d", aux, "i32"/*mudar isto -> getLlvmType(params->type)*/, variable);
            variable++;
        }
        else if(checkIfLiteral(params)){
            aux = (char*)realloc(aux, (strlen(aux) + strlen(params->type) + strlen(params->tag)) * sizeof(char));
            sprintf(aux, "%s%s %s", aux, getLlvmType(params->type), genVariable(params, root->type)); //esta mal
        }
        else {
            variable = genExpr(params, variable, tabs, getLlvmType(params->type));
            aux = (char*)realloc(aux, (strlen(aux) + strlen(params->type) + strlen(params->tag) + 5) * sizeof(char));
            sprintf(aux, "%s%s %%%d", aux, getLlvmType(params->type), variable); //esta mal
            variable++;
        }
        
        if(params->sibling)
            sprintf(aux, "%s,", aux);
        params = params->sibling;
    }
    doTabs(tabs);
    printf("%%%d = call %s @%s(%s)\n", variable, getLlvmType(root->type), removeId(root->child->tag), aux);
    variable++;
    free(aux);
    return variable;
}

int genVarToTemp(node root, char* type, char* newType, int variable, int tabs) {
    if(strcmp(root->tag, "Not") == 0) {
        type = getLlvmType(root->child->type);
    }
    printf("%%%d = load %s, %s* %s, align %c\n", variable, type, 
    type, genVariable(root, type), getLlvmSize(type));
    
    if(checkIfUnary(root)) {
        if(strcmp(root->tag, "Minus") == 0) {
            variable = genMinusConversion(variable, tabs, type);
        }
        else if(strcmp(root->tag, "Not") == 0) {
            variable = genNotConversion(variable, tabs, type);
            type = strdup("i1");
        }
    }

    variable = convertSize(type, newType, variable, tabs);

    return variable;
}

int convertSize(char* type, char* newType, int variable, int tabs) {
    if(strcmp(newType, "double") == 0 && strcmp(type, "double") != 0) {
        doTabs(tabs);
        variable++;
        printf("%%%d = sitofp %s %%%d to %s\n", variable, type, variable - 1, newType);
    }
    else if(cmpSize(type, newType) == -1) {
        doTabs(tabs);
        variable++;
        if(strcmp(type, "i1") == 0) {
            printf("%%%d = zext %s %%%d to %s\n", variable, type, variable - 1, newType);
        }
        else {
            printf("%%%d = sext %s %%%d to %s\n", variable, type, variable - 1, newType);
        }
    }
    else if(cmpSize(type, newType) == 1) {
        doTabs(tabs);
        variable++;
        printf("%%%d = trunc %s %%%d to %s\n", variable, type, variable - 1, newType);
    }

    return variable;
}

int genExpr(node root, int variable, int tabs, char* type) {
    char* aux1 = NULL;
    char* aux2 = NULL;
    char* operation = NULL;
    if((strcmp(root->tag, "Add") == 0) || (strcmp(root->tag, "Sub") == 0) || (strcmp(root->tag, "Mul") == 0)
    || (strcmp(root->tag, "Div") == 0) || (strcmp(root->tag, "Mod") == 0) || (strcmp(root->tag, "BitWiseXor") == 0)
    || (strcmp(root->tag, "BitWiseOr") == 0) || (strcmp(root->tag, "BitWiseAnd") == 0)) {
        operation = genOperationCommand(root->tag, root->type);
        if(checkIfLiteral(root->child)) {
            aux1 = genVariable(root->child, root->type);
        }
        else {
            aux1 = (char*)malloc(4 * sizeof(char));
            variable = genExpr(root->child, variable, tabs, getLlvmType(root->type));
            //variable = convertSize(root->child->type, type, variable, tabs);
            sprintf(aux1, "%%%d", variable);
            variable++;
        }
        if(checkIfLiteral(root->child->sibling)) {
            aux2 = genVariable(root->child->sibling, root->type);
        }
        else {
            aux2 = (char*)malloc(4 * sizeof(char));
            variable = genExpr(root->child->sibling, variable, tabs, getLlvmType(root->type));
            //variable = convertSize(root->child->sibling->type, type, variable, tabs);
            sprintf(aux2, "%%%d", variable);
            variable++;
        }
        doTabs(tabs);
        printf("%%%d = %s %s %s, %s\n", variable, operation, getLlvmType(root->type), aux1, aux2);
        variable = convertSize(getLlvmType(root->type), type, variable, tabs);
        free(aux1);
        free(aux2);
    }
    else if(checkIfLogicalOperation(root->tag)) {
        char* realType = checkType(root->child->type, root->child->sibling->type);
        operation = genOperationCommand(root->tag, realType);
        if(checkIfLiteral(root->child)) {
            aux1 = genVariable(root->child, realType);
        }
        else {
            aux1 = (char*)malloc(4 * sizeof(char));
            variable = genExpr(root->child, variable, tabs, getLlvmType(realType));
            //variable = convertSize(root->child->type, type, variable, tabs);
            sprintf(aux1, "%%%d", variable);
            variable++;
        }
        
        if(checkIfLiteral(root->child->sibling)) {
            aux2 = genVariable(root->child->sibling, realType);
        }
        else {
            aux2 = (char*)malloc(4 * sizeof(char));
            variable = genExpr(root->child->sibling, variable, tabs, getLlvmType(realType));
            //variable = convertSize(root->child->sibling->type, type, variable, tabs);
            sprintf(aux2, "%%%d", variable);
            variable++;
        }
        
        doTabs(tabs);
        printf("%%%d = %s %s %s, %s\n", variable, operation, getLlvmType(realType), aux1, aux2);
        variable = convertSize("i1", type, variable, tabs);
        free(aux1);
        free(aux2);
    }
    else if(strcmp(root->tag, "And") == 0) {
        //char* realType = checkType(root->child->type, root->child->sibling->type);
        if(checkIfLiteral(root->child)) {
            aux1 = genVariable(root->child, root->child->type);
        }
        else {
            aux1 = (char*)malloc(4 * sizeof(char));
            variable = genExpr(root->child, variable, tabs, getLlvmType(root->child->type));
            sprintf(aux1, "%%%d", variable);
            variable++;
        }
        doTabs(tabs);
        if(strcmp(root->child->type, "double") == 0) {
            printf("%%%d = fcmp une double %s, 0.0\n", variable, aux1);
        }
        else {
            printf("%%%d = icmp ne %s %s, 0\n", variable, getLlvmType(root->child->type), aux1);
        }
        label++;
        doTabs(tabs);
        printf("br i1 %%%d, label %%label%d, label %%label%d\n\n", variable, label - 1, label);
        variable++;
        doTabs(tabs);
        printf("label%d:\n", label - 1);

        if(checkIfLiteral(root->child->sibling)) {
            aux2 = genVariable(root->child->sibling, root->child->sibling->type);
        }
        else {
            aux2 = (char*)malloc(4 * sizeof(char));
            variable = genExpr(root->child->sibling, variable, tabs, getLlvmType(root->child->sibling->type));
            sprintf(aux2, "%%%d", variable);
            variable++;
        }
        doTabs(tabs);
        if(strcmp(root->child->sibling->type, "double") == 0) {
            printf("%%%d = fcmp une double %s, 0.0\n", variable, aux2);
        }
        else {
            printf("%%%d = icmp ne %s %s, 0\n", variable, getLlvmType(root->child->sibling->type), aux2);
        }
        variable++;
        doTabs(tabs);
        printf("br label %%label%d\n\n", label);
        
        doTabs(tabs);
        printf("label%d:\n", label); //true condition
        doTabs(tabs);
        int help = label - 2;
        if(help == 0) {
            printf("%%%d = phi i1 [ false, %%0 ], [ %%%d, %%label%d ]\n", variable, variable - 1, label - 1);
        }
        else {
            printf("%%%d = phi i1 [ false, %%label%d ], [ %%%d, %%label%d ]\n", variable, help, variable - 1, label - 1);
        }
        
        variable = convertSize("i1", type, variable, tabs);
        
        label++;
    
    }
    else if(strcmp(root->tag, "Or") == 0) {
        //char* realType = checkType(root->child->type, root->child->sibling->type);
        if(checkIfLiteral(root->child)) {
            aux1 = genVariable(root->child, root->child->type);
        }
        else {
            aux1 = (char*)malloc(4 * sizeof(char));
            variable = genExpr(root->child, variable, tabs, getLlvmType(root->child->type));
            sprintf(aux1, "%%%d", variable);
            variable++;
        }
        doTabs(tabs);
        if(strcmp(root->child->type, "double") == 0) {
            printf("%%%d = fcmp une double %s, 0.0\n", variable, aux1);
        }
        else {
            printf("%%%d = icmp ne %s %s, 0\n", variable, getLlvmType(root->child->type), aux1);
        }
        label++;
        doTabs(tabs);
        printf("br i1 %%%d, label %%label%d, label %%label%d\n\n", variable, label, label - 1);
        variable++;
        doTabs(tabs);
        printf("label%d:\n", label - 1);
        if(checkIfLiteral(root->child->sibling)) {
            aux2 = genVariable(root->child->sibling, root->child->sibling->type);
        }
        else {
            aux2 = (char*)malloc(4 * sizeof(char));
            variable = genExpr(root->child->sibling, variable, tabs, getLlvmType(root->child->sibling->type));
            sprintf(aux2, "%%%d", variable);
            variable++;
        }
        doTabs(tabs);
        if(strcmp(root->child->sibling->type, "double") == 0) {
            printf("%%%d = fcmp une double %s, 0.0\n", variable, aux2);
        }
        else {
            printf("%%%d = icmp ne %s %s, 0\n", variable, getLlvmType(root->child->sibling->type), aux2);
        }
        variable++;
        doTabs(tabs);
        printf("br label %%label%d\n\n", label);
        
        doTabs(tabs);
        printf("label%d:\n", label); //true condition
        doTabs(tabs);
        int help = label - 2;
        if(help == 0) {
            printf("%%%d = phi i1 [ true, %%0 ], [ %%%d, %%label%d ]\n", variable, variable - 1, label - 1);
        }
        else {
            printf("%%%d = phi i1 [ true, %%label%d ], [ %%%d, %%label%d ]\n", variable, help, variable - 1, label - 1);
        }
        
        variable = convertSize("i1", type, variable, tabs);
        
        label++;
    }
    else if(strcmp(root->tag, "Store") == 0) {
        variable = genStore(root->child, getLlvmType(root->type), variable, tabs);
        doTabs(tabs);
        printf("%%%d = load %s, %s* %s, align %c\n", variable, getLlvmType(root->child->type), getLlvmType(root->child->type),
        genVariable(root->child, getLlvmType(root->child->type)), getLlvmSize(getLlvmType(root->child->type)));
    }
    else {
        if(checkIfId(root->tag) || checkIfUnary(root)) {
            doTabs(tabs);
            variable = genVarToTemp(root, getLlvmType(root->type), type, variable, tabs);
        }
        else if(strcmp(root->tag, "Minus") == 0) {
            variable = genExpr(root->child, variable, tabs, type);
            variable = genMinusConversion(variable, tabs, type);
        }
        else if(strcmp(root->tag, "Not") == 0) {
            variable = genExpr(root->child, variable, tabs, type);
            variable = genNotConversion(variable, tabs, type);
            variable = convertSize("i1", type, variable, tabs);
        }
    }

    return variable;
}

int generateIf(node root, int variable, int tabs, char* funcType) {
    if(!(checkIfLogicalOperation(root->child->tag) || strcmp(root->child->tag, "And") == 0 || strcmp(root->child->tag, "Or") == 0)) {
        if(strcmp(root->child->type, "double") == 0) {
            variable = genExpr(root->child, variable, tabs, "double");
            variable++;
            doTabs(tabs);
            printf("%%%d = fcmp une double %%%d, 0\n", variable, variable - 1);
        }
        else {
            variable = genExpr(root->child, variable, tabs, "i32");
            variable++;
            doTabs(tabs);
            printf("%%%d = icmp ne i32 %%%d, 0\n", variable, variable - 1);
        }
    }
    else {
        variable = genExpr(root->child, variable, tabs, "i1");
    }
    label++;
    doTabs(tabs);
    printf("br i1 %%%d, label %%label%d, label %%label%d\n\n", variable, label - 1, label);
    variable++;
    doTabs(tabs);
    printf("label%d:\n", label - 1);
    variable = genFuncBody(root->child->sibling, tabs, variable, funcType, 0);
    if(strcmp(root->child->sibling->sibling->tag, "Null") != 0) { //else
        if(variable < 0) {
            variable *= -1;
        }
        else {
            doTabs(tabs);
            printf("br label %%label%d\n\n", label + 1);
        }
        doTabs(tabs);
        printf("label%d:\n", label);
        variable = genFuncBody(root->child->sibling->sibling, tabs, variable, funcType, 1);
        label++;
         
        if(variable < 0) {
            variable *= -1;
        }
        else {
            doTabs(tabs);
            printf("br label %%label%d\n\n", label);
        }
        
        doTabs(tabs);
        printf("label%d:\n", label); //continue
    }
    else { //no else   
        if(variable < 0) {
            variable *= -1;
        }
        else {
            doTabs(tabs);
            printf("br label %%label%d\n\n", label);
        }
        doTabs(tabs);
        printf("label%d:\n", label);
    }
    label++;
    return variable;
}

int generateWhile(node root, int variable, int tabs, char* funcType) {
    doTabs(tabs);
    printf("br label %%label%d\n\n", label);
    doTabs(tabs);
    printf("label%d:\n", label);
    label++;
    //comparacao aqui
    if(!(checkIfLogicalOperation(root->child->tag) || strcmp(root->child->tag, "And") == 0 || strcmp(root->child->tag, "Or") == 0)) {
        if(strcmp(root->child->type, "double") == 0) {
            variable = genExpr(root->child, variable, tabs, "double");
            variable++;
            doTabs(tabs);
            printf("%%%d = fcmp une double %%%d, 0\n", variable, variable - 1);
        }
        else {
            variable = genExpr(root->child, variable, tabs, "i32");
            variable++;
            doTabs(tabs);
            printf("%%%d = icmp ne i32 %%%d, 0\n", variable, variable - 1);
        }
    }
    else {
        variable = genExpr(root->child, variable, tabs, "i1");
    }
    doTabs(tabs);
    printf("br i1 %%%d, label %%label%d, label %%label%d\n\n", variable, label, label + 1);
    variable++;
    doTabs(tabs);
    printf("label%d:\n", label);
    variable = genFuncBody(root->child->sibling, tabs, variable, funcType, 1);
    doTabs(tabs);
    printf("br label %%label%d\n\n", label - 1);
    label++;
    doTabs(tabs);
    printf("label%d:\n", label); //continue
    label++;
    return variable;
}

char* genOperationCommand(char* op, char* type) {
    char* result = NULL;
    if(strcmp(op, "Add") == 0) {
        if(strcmp(type, "double") == 0) {
            result = strdup("fadd");
        }
        else {
            result = strdup("add");
        }
    }
    else if(strcmp(op, "Sub") == 0) {
        if(strcmp(type, "double") == 0) {
            result = strdup("fsub");
        }
        else {
            result = strdup("sub");
        }
    }
    else if(strcmp(op, "Mul") == 0) {
        if(strcmp(type, "double") == 0) {
            result = strdup("fmul");
        }
        else {
            result = strdup("mul");
        }
    }
    else if(strcmp(op, "Div") == 0) {
        if(strcmp(type, "double") == 0) {
            result = strdup("fdiv");
        }
        else {
            result = strdup("sdiv");
        }
    }
    else if(strcmp(op, "Mod") == 0) {
        result = strdup("srem");
    }
    else if(strcmp(op, "BitWiseAnd") == 0) {
        result = strdup("and");
    }
    else if(strcmp(op, "BitWiseOr") == 0) {
        result = strdup("or");
    }
    else if(strcmp(op, "BitWiseXor") == 0) {
        result = strdup("xor");
    }
    else if(strcmp(op, "Eq") == 0) {
        if(strcmp(type, "double") == 0) {
            result = strdup("fcmp oeq");
        }
        else {
            result = strdup("icmp eq");
        }
    }
    else if(strcmp(op, "Ne") == 0) {
        if(strcmp(type, "double") == 0) {
            result = strdup("fcmp one");
        }
        else {
            result = strdup("icmp ne");
        }
    }
    else if(strcmp(op, "Le") == 0) {
        if(strcmp(type, "double") == 0) {
            result = strdup("fcmp ole");
        }
        else {
            result = strdup("icmp sle");
        }
    }
    else if(strcmp(op, "Ge") == 0) {
        if(strcmp(type, "double") == 0) {
            result = strdup("fcmp oge");
        }
        else {
            result = strdup("icmp sge");
        }
    }
    else if(strcmp(op, "Lt") == 0) {
        if(strcmp(type, "double") == 0) {
            result = strdup("fcmp olt");
        }
        else {
            result = strdup("icmp slt");
        }
    }
    else if(strcmp(op, "Gt") == 0) {
        if(strcmp(type, "double") == 0) {
            result = strdup("fcmp ogt");
        }
        else {
            result = strdup("icmp sgt");
        }
    }
    return result;
}

//aux functions

int cmpSize(char* size1, char* size2) {
    if(strcmp(size1, size2) == 0) { //same size
        return 0;
    }
    if(strcmp(size1, "i32") == 0 && strcmp(size2, "i32") != 0) { //size1 bigger than size2
        return 1; 
    }
    else if(strcmp(size1, "i16") == 0 && (strcmp(size2, "i8") == 0 || strcmp(size2, "i1") == 0) ) { //size1 bigger than size2
        return 1; 
    }
    else if(strcmp(size1, "i8") == 0 && (strcmp(size2, "i1") == 0) ) { //size1 bigger than size2
        return 1; 
    }
    else if(strcmp(size1, "i1") == 0 && strcmp(size2, "i1") != 0) { //size1 smaller than size2
        return -1; 
    }
    else if(strcmp(size1, "i8") == 0 && (strcmp(size2, "i8") != 0 || strcmp(size2, "i1") != 0)) { //size1 smaller than size2
        return -1; 
    }
    else if(strcmp(size1, "i16") == 0 && strcmp(size2, "i32") == 0) { //size1 smaller than size2
        return -1; 
    }
    return 0;
}

int trasformToAscii(char* string) {
    int transform = 0;

    if(*string == '\\' && *(string + 1) == 'n') {
        transform = 10;
    }
    else if(*string == '\\' && *(string + 1) == 't') {
        transform = 9;
    }
    else if(*string == '\\' && *(string + 1) == '"') {
        transform = 34;
    }
    else if(*string == '\\' && *(string + 1) == '\'') {
        transform = 39;
    }
    else if(*string == '\\' && *(string + 1) == '\\') {
        transform = 92;
    }
    else if(*string == '\\') {
        int aux;
        int aux1 = 0;
        int size = strlen(string) - 1;
        int el = 0;

        for(; size > 0; size--) {
            aux = *(string + size) - 48;
            aux1 += aux * powAux(10, el);
            el++;
        }
        el = 0;
        while(aux1 != 0) {
            transform += (aux1 % 10)* powAux(8, el);
            el++;
            aux1 /= 10;
        }
    }
    else {
        transform = *string;
    }

    return transform;
}

int powAux(int nr, int el) {
    int result = nr;

    if(el == 0) {
        result = 1;
    }
    else {
        for(int n = 1; n < el; n++) {
            result *= nr;
        }
    }

    return result;
}

int checkIfLiteral(node root) {
    if(strncmp(root->tag, "Real", 4) == 0 || strncmp(root->tag, "Int", 3) == 0 || strncmp(root->tag, "Chr", 3) == 0) {
        return 1;
    }
    else if(strcmp(root->tag, "Minus") == 0 || strcmp(root->tag, "Plus") == 0 || strcmp(root->tag, "Not") == 0) {
        return checkIfLiteral(root->child);
    }
    else {
        return 0;
    }
}

char* checkType(char* type1, char* type2) {
    char* type;
    if(strcmp(type1, "double") == 0 || strcmp(type2, "double") == 0) {
        type = strdup("double");
    }
    else if (strcmp(type1, "int") == 0 || strcmp(type2, "int") == 0) {
        type = strdup("int");
    }
    else if (strcmp(type1, "short") == 0 || strcmp(type2, "short") == 0) {
        type = strdup("short");
    }
    else {
        type = strdup("char");
    }
    return type;
}

char* generateOctal(char* string) {
    int aux;
    int transform = 0;
    int aux1 = 0;
    int size = strlen(string) - 1;
    int el = 0;

    for(; size > 0; size--) {
        aux = *(string + size) - 48;
        aux1 += aux * powAux(10, el);
        el++;
    }
    el = 0;
    while(aux1 != 0) {
        transform += (aux1 % 10)* powAux(8, el);
        el++;
        aux1 /= 10;
    }
    char* ret = (char*)malloc(strlen(string) * sizeof(char));
    sprintf(ret, "%d", transform);
    return ret;
}