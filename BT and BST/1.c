/*
1. Read n ints and make a binary search tree (BST). Do k search operations to print results as y/n.
Input: (n, x_i, k, y_i)
4
2 1 4 3
3
3 7 1
Output:
y
n
y
2. Read n ints and make a BST in the same order. Print the tree in preorder, inorder and postorder
traversals. Separate characters by '_'.
Input: (n, x_i)
4
2 1 4 3
Output:
2_1_4_3_
1_2_3_4_
1_3_4_2_

*/


#include <stdio.h>
#include <stdlib.h>


struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create_tree(struct node *root, int val)
{
    if (root == NULL)
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));

        temp->data = val;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }

    if (root->data < val)
    {
        root->right = create_tree(root->right, val);
    }
    else
    {
        root->left = create_tree(root->left, val);
    }
    return root;
}
void in_order(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    in_order(root->left);
    printf("%d ", root->data);
    in_order(root->right);
}

void pre_order(struct node *root)
{
    if (root == NULL)
    {
        // return;
    }

    printf("%d ", root->data);
    in_order(root->left);
    in_order(root->right);
}

struct node* search(struct node* root, int val) 
{
    if (root == NULL) {
        printf ("n\n");
        return root;
    }
    if (root -> data == val)
    {
        printf("y\n");
        return root;
    }
    else if(root -> data < val) {
      root -> right =  search(root -> right, val);
    } else {
        root -> left = search(root -> left, val);
    }
    return root;
    
}
int main()
{
    struct node *root = NULL;
    int val;
    for (int i = 0; i < 4; i++)
    {
        scanf("%d", &val);
        root = create_tree(root, val);
    }

    in_order(root);
    printf("\n");
    pre_order(root);

    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &val);
        search(root, val);
    }
}