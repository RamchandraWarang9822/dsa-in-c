#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

struct node* newNode(int value, struct node* next)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->value = value;
    new_node->next = next;
    return new_node;
}

void insertAt(struct node* node, int pos, int value){
    int count = -1;
    while (count != pos - 1 && node->next != NULL) {
        node = node->next;
        count++;
    }
    struct node* temp = newNode(value, node->next);
    node->next = temp;
}

struct node* insertLast(struct node* node ,int value)
{
    if(node == NULL){
        return newNode(value, NULL);
    }
    
    if(node->next == NULL){
        node->next = newNode(value, NULL);
    } else {
        insertLast(node->next, value);
    }
    
    return node;
}

void printLinkedList(struct node* node){
    while(node != NULL){
        printf("%d -> ", node->value);
        node = node->next;
    }
}

int main(void) {
    // Sample usage
    struct node* head = newNode(1, NULL);
    insertLast(head, 2);
    insertLast(head, 3);
    insertAt(head, 1, 4);
    printLinkedList(head);

    return 0;
}
