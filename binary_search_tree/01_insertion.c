#include <stdio.h>
#include <stdlib.h>

int rm_key = 0;
int levels = 0;

struct node {
    int key;
    int layer;
    struct node *left, *right;
};

struct node* instantiate_node(int item, int level) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->layer = level + 1;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct node* insert (struct node* node, int key, int level) {
    if (node == NULL) {
        struct node* new_node = instantiate_node(key, level);

        // compares the global max level to the current node level
        if (levels < new_node->layer) { 
            levels = new_node->layer;
        }

//        printf("insert key: %d", key);
//        printf("\t\tlayer: %d", new_node->layer);
//        printf("\tlevels: %d", levels);
//        printf("\n");

        return new_node; 
    }

    if (key < node->key) {
        node->left = insert(node->left, key, node->layer);
    } if (key > node->key) {
        node->right = insert(node->right, key, node->layer);
    } 

    return node;
}


int right_most_branch(struct node* branch) {
    if (branch->right != NULL) {
        return branch->right->key;
    }

    if (branch->left != NULL) {
        return branch->left->key;
    }

    return branch->key;
}

void print_key(struct node* node) {
    printf("\t");

    for (int spaces = levels; spaces > 0; spaces--) {
//        for (int space2 = levels; space2 > 0; space2--) {
            printf("\t");
//        }
    }
    
    if (node != NULL) {
        printf("%d", node->key);
    } else {
        printf("  ");
    }

    return;
}

//                10
//         5               15
//      4     8      11         17
//    2     6   9      12     16  18
//           7           13              

void tree_branch(struct node* branch) { // 5
    print_key(branch->left); // print 4
    print_key(branch->right); // print 8
    
    int right_most_key = right_most_branch(branch);

    if (rm_key == right_most_key) {
        printf("\n");
        levels--;

        if (branch->right != NULL) {
            rm_key = right_most_branch(branch->right); // 17
        } else if (branch->left != NULL) {
            rm_key = right_most_branch(branch->left);
        } else {
            return;
        }
        
        //printf("right most wtf: %d\n", rm_key); // 
        
        tree_branch(branch->left); // 5
        tree_branch(branch->right); // 15
    } 

    return;
}


void print_tree(struct node* root) {
    if (root != NULL) {
        printf("\n\n");
        print_key(root);   // 10
        rm_key = root->key;  // 10

        int tmp_key = right_most_branch(root); // 15

        if (rm_key != tmp_key) {
            rm_key = tmp_key; // 15
            
            printf("\n");
            levels--;

            tree_branch(root);
        }
    }
}


int main() 
{
    struct node* root = NULL;

    root = insert(root, 10, 0);
    root = insert(root, 5, 0);
    root = insert(root, 15, 0);
    root = insert(root, 8, 0);
    root = insert(root, 11, 0);
    root = insert(root, 4, 0);
    root = insert(root, 17, 0);
    root = insert(root, 6, 0);
    root = insert(root, 9, 0);
    root = insert(root, 16, 0);
    root = insert(root, 12, 0);
    root = insert(root, 2, 0);
    root = insert(root, 18, 0);
    root = insert(root, 7, 0);
    root = insert(root, 13, 0);

    print_tree(root);
    
    return 0;
}
