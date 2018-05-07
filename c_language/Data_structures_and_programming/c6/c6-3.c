#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
typedef struct Node NODE_TYPE;

void tree_display(NODE_TYPE * node, int level)
{
    int i;
    if (node != NULL) {
       tree_display (node->right, level + 1);
       printf ("\n");
       for (i = 0; i < level; i++) {
           printf ("_");
       }
       printf ("%d", node->data);
       tree_display (node->left, level + 1);
    }
}

void traverse_preorder (NODE_TYPE * node)
{
    if (node != NULL) {
        printf ("%2d ", node->data);
        traverse_preorder (node->left);
        traverse_preorder (node->right);
    }
}

void traverse_inorder (NODE_TYPE * node)
{
    if (node != NULL) {
        traverse_inorder (node->left);
        printf("%2d ", node->data);
        traverse_inorder (node->right);
    }
}

void traverse_postorder (NODE_TYPE * node)
{
    if (node != NULL) {
        traverse_postorder (node->left);
        traverse_postorder (node->right);
        printf ("%2d ", node->data);
    }
}

NODE_TYPE *tree_find_min (NODE_TYPE * node)
{
    if ((node == NULL) || (node->left == NULL)) {
        printf ("%2d ", node->data);
        return node;
    }
    return tree_find_min (node->left);
}

NODE_TYPE *tree_find_max (NODE_TYPE * node)
{
    if ((node == NULL) || (node->right == NULL)) {
        printf ("%2d ", node->data);
        return node;
    }
    return tree_find_max (node->right);
}

int main()
{
    NODE_TYPE *root;
    
    root = malloc (sizeof (NODE_TYPE));
    root->data = 40;

    root->left = malloc (sizeof (NODE_TYPE));
    root->left->data = 30;

    root->right = malloc (sizeof (NODE_TYPE));
    root->right->data = 70;

    root->left->left = malloc (sizeof (NODE_TYPE));
    root->left->left->data = 10;
    root->left->right = NULL;
    
    root->right->left = malloc (sizeof (NODE_TYPE));
    root->right->left->data = 60;
    root->right->left->left = NULL;
    root->right->left->right= NULL;

    root->right->right = malloc (sizeof (NODE_TYPE));
    root->right->right->data = 90;
    root->right->right->left = NULL;
    root->right->right->right= NULL;

    root->left->left->right = malloc (sizeof (NODE_TYPE));
    root->left->left->right->data = 20;
    root->left->left->right->left = NULL;
    root->left->left->right->right= NULL;
    
    tree_display (root, 0);
    printf ("\n");
    
    printf ("Preorder  :");
    traverse_preorder(root);
    printf ("\n");
    
    printf ("Inorder   :");
    traverse_inorder(root);
    printf ("\n");
    
    printf ("Postorder :");
    traverse_postorder(root);
    printf ("\n");

    printf ("\n");

    printf ("Max :");
    tree_find_max(root);
    printf ("\n");

    printf ("Min :");
    tree_find_min(root);
    printf ("\n");

    return 0;
}