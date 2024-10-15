#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *getnode()
{
    node *a;
    a = (node *)malloc(sizeof(node));

    if (a == NULL)
    {
        printf("Memory Allocating Failed.\n");
        return NULL;
    }
    else
    {
        return a;
    }
}

int count(node *head)
{
  if (head == NULL)
    {
        printf("LinkedList is Empty.\n");
        return 0;
    }

    int c = 1;
    node *current = head->next;

    while (current != head)
    {
        c++;
        current = current->next;
    }

    return c;
}

int main()
{
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

    int node_count = count(head);
    printf("The number of nodes in the linked list: %d\n", node_count);
}
