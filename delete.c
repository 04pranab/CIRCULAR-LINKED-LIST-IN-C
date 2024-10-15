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


node *delete(node *head, int x)
{
    if (head == NULL) {
        printf("List is empty, cannot delete.\n");
        return NULL;
    }

    node *current = head, *prev = NULL;

  
    if (head->data == x) {
        if (head->next == head) {
            
            free(head);
            return NULL;
        } else {
            
            while (current->next != head) {
                current = current->next;
            }

            current->next = head->next;
            node *temp = head;
            head = head->next;
            free(temp);
            return head;
        }
    }

    prev = head;
    current = head->next;
    while (current != head) {
        if (current->data == x) {
            prev->next = current->next;
            free(current);
            return head;
        }
        prev = current;
        current = current->next;
    }

    printf("Element %d not found in the list.\n", x);
    return head;
}

int main()
{
    node *head = getnode();
    head->data = 1;
    head->next = getnode();
    head->next->data = 2;
    head->next->next = getnode();
    head->next->next->data = 3;
    head->next->next->next = head;

    printf("Original List: ");
    display(head);

    head = delete(head, 2);

    printf("List after deleting 2: ");
    display(head);

    head = delete(head, 1);

    printf("List after deleting 1: ");
    display(head);

    head = delete(head, 3);

    printf("List after deleting 3: ");
    display(head);

    return 0;
}
