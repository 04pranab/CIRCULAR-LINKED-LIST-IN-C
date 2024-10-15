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

node *insertAtBEG(node *head, int x)
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
    while (t->next != head)
    {
        t = t->next;
    }

    t->next = temp;
    temp->next = head;

    return temp; 
}

void display(node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    node *temp = head->next;
    printf("Head -> ");
    printf("%d->", head->data);
    while (temp != head) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("Head\n");
}


int main()
{
    node *head = NULL;
    head = insertAtBEG(head, 10);
    head = insertAtBEG(head, 20);
    head = insertAtBEG(head, 30);

    display(head);
    return 0;
}