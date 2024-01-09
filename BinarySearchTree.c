#include<stdio.h>
#include <stdlib.h>

// Structure

struct node {
    int val;
    struct node *left;
    struct node *right;
};


// Insertion

struct node* newNode(int val)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->val = val;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* insert(struct node* node, int val){
    if(node == NULL){
        return newNode(val);
    }
    
    if(node->val < val){
        node->right = insert(node->right, val);
    } else if(node->val > val){
        node->left = insert(node->left, val);
    }
    
    return node;
}

// Traversal & Printing

void inorder(struct node* root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ", root->val);
        inorder(root->right);
    }
}

void bfs(struct node* root){
    if(root == NULL){
        return;
    }
   
    struct node** queue = (struct node**)malloc(sizeof(struct node*) * 1000);
    int front  = -1, rear = -1;
    
    queue[++rear] = root;
    
    while(front != rear){
        struct node* current = queue[++front];
        printf("%d ", current->val);
        
        if(current->left != NULL){
            queue[++rear] = current->left;
        }
        
        if(current->right != NULL){
            queue[++rear] = current->right;
        }
    }
    
    free(queue);
}


// Searching

struct node* search(struct node* root, int value)
{
    if(root == NULL || root->val == value)
        return root;
    
    if(root->val < value)
        return search(root->right, value);
    
    return search(root->left, value);
}


// Deletion


int main(void) {
    
    struct node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
 
    // Print inorder traversal of the BST
    bfs(root);
    
    // Key to be found
    int key = 60;
 
    // Searching in a BST
    if (search(root, key) == NULL)
        printf("\n %d not found\n", key);
    else
        printf("\n%d found\n", key);
    
    return 0;
}
