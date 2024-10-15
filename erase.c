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


node *erase(node *head)
{
    node *t, *p = head->next;
    while(p->next != head)
    {
        p = p->next;
    }

    p->next = NULL;
    
    while (head != NULL)
    {
        t = head;
        head = head->next;

        free(t);
    }
    return NULL;
}

int main() {

    node *head = getnode();
    if (head == NULL) return 1;
    head->data = 1;

    head->next = getnode();
    if (head->next == NULL) return 1;
    head->next->data = 2;


    head->next->next = getnode();
    if (head->next->next == NULL) return 1;
    head->next->next->data = 3;
    head->next->next->next = head;


    printf("Original List: ");
    display(head);


    head = erase(head);


    printf("List after erasing: ");
    display(head);

    return 0;
}