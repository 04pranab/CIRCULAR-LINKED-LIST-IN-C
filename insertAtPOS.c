#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *getnode() {
    node *a;
    a = (node *)malloc(sizeof(node));

    if (a == NULL) {
        printf("Memory Allocation Failed.\n");
        return NULL;
    } else {
        return a;
    }
}

void display(node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    node *temp = head->next;
    printf("Head -> ");
    printf("%d -> ", head->data);
    while (temp != head) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("Head\n");
}

node *insertAtPos(node *head, int x, int pos)
{
    node *temp  = getnode();
    if (temp == NULL)
    {
        printf("Malloc Failed !");
        return head;
    }

    temp->data = x;
    temp->next = NULL;
    
    if (head == NULL)
    {
        temp->next = temp;  
        return temp;       
    }

    node *t = head;
    int c = 0;

    while (t->next != head && c == pos)
    {
        t = t->next;
    }

    temp->next = t->next;
    t->next = temp;

    return head;
}

int main()
{
    node *head = NULL;
    head = insertAtPos(head, 10, 0);
    head = insertAtPos(head, 30, 1);
    head = insertAtPos(head, 20, 1);
    

    display(head);
    return 0;
}