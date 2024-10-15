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

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

node *insertAtEnd(node *head, int x)
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

    temp->next = head;
    t->next = temp;

    return head;
}

void bubble(node *head) 
{
    node *p;
    int n = count(head);
    for(int i = 0; i < n;i++)
    {
        p = head;
        for(int j = 0; j < n-i-1; j++)
        {
            if (p->data > p->next->data)
            {
                swap(&(p->data),&(p->next->data));
            }

            p = p->next;
        }

    }
}


int main()
{
    int n, a;
    printf("Enter Length for Linked-List :");
    scanf("%d",&n);

    node *head = NULL;
    for (int i = 0; i < n; i++)
    {
        printf("Enter the data(%d): ",i+1);
        scanf("%d",&a);

        head = insertAtEnd(head, a);
    }

    printf("Intial List is :\n");
    display(head);

    printf("After Bubble Sort :\n");
    bubble(head);
    display(head);
    printf("\n");
    
}