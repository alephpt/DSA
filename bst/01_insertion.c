#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node *left, *right;
};

struct node* instantiate_node(int item) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = NULL;
    temp->right = NULL;
}

struct node* insert (struct node* node, int key) {
    if (node == NULL) { 
        return instantiate_node(key); 
    }

    if (key < node->key) {
        node->left = insert(node->left, key);
    } 

    if (key < node->key) {
        node->right = insert(node->right, key);
    } 

    return node;
}

void ordered_print(struct node* root) {
    if (root != NULL) {
        ordered_print(root->left);
        printf("%d ", root->key);
        ordered_print(root->right);
    }
}

void printTree(struct node* root, int space){
    if (root != NULL)
    {
        space += 10;
        printTree(root->right, space);

        for (int i = 10; i < space; i++){
            printf(" ");
        }
   
        printf("%d\n", root->key);

        printTree(root->left, space);
    }
}

int main() 
{
    struct node* root = NULL;

    root = insert(root, 100);
    root = insert(root, 50);
    root = insert(root, 120);
    root = insert(root, 55);
    root = insert(root, 101);
    root = insert(root, 108);
    root = insert(root, 128);
    root = insert(root, 43);
    root = insert(root, 78);
    root = insert(root, 53);
    root = insert(root, 33);
    root = insert(root, 123);
    root = insert(root, 117);
    root = insert(root, 121);
    root = insert(root, 49);

    printTree(root, 0);
    
    return 0;
}
