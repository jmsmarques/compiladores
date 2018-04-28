#include "structs.h"

node createNode(char* tagValue) {
    node no = (node)malloc(sizeof(tree_node));
    no->tag = (char*)malloc((strlen(tagValue) + 1) * sizeof(char));
    strcpy(no->tag, tagValue);
    no->type = NULL;
    no->child = NULL;
    no->sibling = NULL;
    return no;
}

node createNodeEmpty() {
    node no = (node)malloc(sizeof(tree_node));
    no->tag = NULL;
    no->type = NULL;
    no->child = NULL;
    no->sibling = NULL;
    return no;
}

node createNodeTerminal(char* tagValue, char* value) {
    node no = (node)malloc(sizeof(tree_node));
    no->tag = (char*)malloc((strlen(tagValue) + strlen(value) + 3) * sizeof(char));
    sprintf(no->tag, "%s%c%s%c", tagValue, '(', value, ')');
    no->type = NULL;
    no->child = NULL;
    no->sibling = NULL;
    return no;
}

void addChild(node father, node son) {
    if(father == NULL)
        return;
    father->child = son;
}

void addNullChild(node father) {
    node aux;
    aux = (node) malloc(sizeof(tree_node));
    aux->tag = (char*) malloc(5*sizeof(char));
    strcpy(aux->tag, "Null");
    aux->type = NULL;
    aux->child = NULL;
    aux->sibling = NULL;

    father->child = aux;
}

void addSibling(node sibling1, node sibling2) {
    if(sibling1 == NULL || sibling2 == NULL) {
        return;
    }
    while(sibling1->sibling != NULL) {
        sibling1 = sibling1->sibling;
    }
    sibling1->sibling = sibling2;
}

void typeSpecDef(node up, char* newTag) {
    if(up == NULL) {
        return;
    }

    up->child->tag = (char*)malloc((strlen(newTag) + 1) * sizeof(char));
    strcpy(up->child->tag, newTag);

    typeSpecDef(up->sibling, newTag);
}

void printTree(node root, int level) {
    int aux;
    if(root == NULL) {
        return;
    }
    else {
        for(aux = 0; aux < level; aux++) {
            printf("..");
        }
        printf("%s\n", root->tag);
        
    }
    printTree(root->child, level + 1);
    printTree(root->sibling, level);

    free(root->tag);
    free(root->child);
    free(root->sibling);
    if(level == 0) {
        free(root);
    }
}

void freeTree(node root) {
    if(root == NULL) {
        return;
    }
    freeTree(root->child);
    freeTree(root->sibling);
    
    free(root->tag);
    free(root->child);
    free(root->sibling);
}

node checkNull(node no) {
    if(no != NULL) {
        return no;
    }
    else {
        return createNode("Null");
    }
}

void addLinesAndCols(node root, int line, int col) { //adiciona a linha e a col a um no da ast
    root->pos[0] = line;
    root->pos[1] = col;
}