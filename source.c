#include <stdio.h>
#include <stdlib.h>

typedef struct nodeTree {
    int ID, fID, mID;
    float weight, hight, length;

    struct nodeTree *pLeft;
    struct nodeTree *pRight;
} nodeTree;

nodeTree *makeNode(int ID, int fID, int mID, float w, float h, float l) {
    nodeTree *ptr = (nodeTree *)malloc(sizeof(nodeTree));

    ptr->fID = fID;
    ptr->hight = h;
    ptr->ID = ID;
    ptr->length = l;
    ptr->mID = mID;
    ptr->weight = w;
    ptr->pLeft = NULL;
    ptr->pRight = NULL;

    return ptr;
}

nodeTree *insertNodeTree(nodeTree *tree, int ID, int fID, int mID, float w, float h, float l) {
    if (tree == NULL)
        tree = makeNode(ID, fID, mID, w, h, l);
    else {
        if (ID < tree->ID)
            tree->pLeft = insertNodeTree(tree->pLeft, ID, fID, mID, w, h, l);
        if (ID > tree->ID)
            tree->pRight = insertNodeTree(tree->pRight, ID, fID, mID, w, h, l);
    }

    return tree;
}

void printTree(nodeTree *root) {
    if (root != NULL) {
        printf("%d ", root->ID);
        printTree(root->pLeft);
        printTree(root->pRight);
    }
}

nodeTree* find(nodeTree *tree, int ID) {
    if (tree == NULL)
        return NULL;
    if (tree->ID == ID)
        return tree;

    nodeTree *ptr = tree->pLeft;
    while (ptr != NULL) {
        nodeTree *q = find(ptr, ID);
        if (q != NULL)
            return q;
        
        ptr = ptr->pRight;
    }
}

int main() {
    nodeTree *root;
    root = NULL;

    printf("Cin count goat: ");
    int n;
    scanf("%d", &n);

    printf("==========================\n");
    int ID, fID, mID;
    float w, h, l;

    for (int i = 1; i <= n; i++) {
        printf("Cin ID %d: ", i);
        scanf("%d", &ID);

        printf("Cin fID %d: ", i);
        scanf("%d", &fID);

        printf("Cin mID %d: ", i);
        scanf("%d", &mID);

        printf("Cin weight %d: ", i);
        scanf("%f", &w);

        printf("Cin hight %d: ", i);
        scanf("%f", &h);

        printf("Cin length %d: ", i);
        scanf("%f", &l);

        root = insertNodeTree(root, ID, fID, mID, w, h, l);
        printf("==========================\n");
    }

    printTree(root);
    return 0;
}