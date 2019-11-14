#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* cicular double linked list */

struct Node
{
    char data[100];
    struct Node* next;
    struct Node* prev;
};

void rotate(struct Node **head, int k, int len); /* rotate linklist in counter-clockwise*/
void push (struct Node** head, char new_data[]);   /* create nodes */
void odd2even(struct Node *head); /* let odd to even */
void put_prev(struct Node **head); /* let cicular linked list transfer to double cicular linked list */
void eliminating_game(struct Node **head, int k, int len,int direction); /* eliminating_game */
void printList(struct Node *node);  /* print node */

int main(void)
{
    /* Start with the empty list */

    struct Node* head = NULL;
    int k,direction,skip;
    scanf("%d",&k);
    scanf("%d",&direction);
    scanf("%d",&skip);
    int count = 0;
    char input[100][100];

    while (scanf("%s",input[count])!=EOF)
        count++;
    for(int i = count -1; i >= 0; i--)
        push(&head,input[i]);

    printList(head);

    odd2even(head);
    printList(head);

    rotate(&head,k,count);
    printList(head);

    put_prev(&head);
    eliminating_game(&head,skip,count,direction);
    return 0;
}

void rotate(struct Node **head, int k,int len)
{
     if (k == 0||k == len)
       return;
     // If k > linklist_len return back to 0
     if(k>len)
        k = k % len ;

    struct Node* current = *head;

    // current will either point to kth or NULL after this loop.
    int count = 1; // 0 need to include
    while (count < k && current != NULL)
    {
        current = current->next;
        count++;
    }

    // store k'th node.
    struct Node *kthNode = current;

    // current will point to last node after this loop
    while (current->next != NULL)
        current = current->next;
    // Change next of last node to previous head
    current->next = *head;

    // Change head to (k+1)th node
    *head = kthNode->next;

    // change next of kth node to NULL
    kthNode->next = NULL;
}

void push (struct Node** head, char new_data[])
{
    /* allocate node */
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    /* put in the data  */
    strcpy(new_node->data,new_data);

    /* link the old list off the new node */
    new_node->next = (*head);

    /* move the head to point to the new node */
    (*head) = new_node;
}

void odd2even(struct Node *head)
{
    struct Node* odd = head;
    struct Node* even = head->next;
    struct Node* evenfirst = even;
    while(1)
    {
        /* If there is no more nodes */
        if(odd == NULL || even == NULL ||even->next == NULL)
        {
            odd->next  = evenfirst;
            break;
        }

        /* put odd nodes */
        odd->next = even->next;
        odd = even->next;

        /* no more odd nodes */
        if(odd->next == NULL)
        {
            even->next = NULL;
            odd->next = evenfirst;
            break;
        }

        /* put even nodes */
        even->next = odd->next;
        even = odd->next;
    }
}

void eliminating_game(struct Node **head, int k, int len,int direction)
{
    struct Node* current = *head;
    int people = len;
    if(direction == 1) /* couter-clockwise */
    {
        while (people!=1)
        {
            for(int i = 0; i<k; i++) /* skip people */
                current = current->next;
            printf("%s died\n",current->data);

            /* let the killed person delete int the list */
            current->prev->next = current->next;
            current->next->prev = current->prev;
            current = current->next;
            people --;
        }
        printf("%s",current); /* print the remain person */
    }
    else /* clockwise */
    {
        while (people!=1)
        {
            for(int i = 0; i<k; i++)
                current = current->prev;
            printf("%s died\n",current->data);

            /* let the killed person delete int the list */
            current->prev->next = current->next;
            current->next->prev = current->prev;
            current = current->prev;
            people --;
        }
        printf("%s",current); /* print the remain person */
    }
}

void put_prev(struct Node **head)
{
    struct Node* current = *head;
    struct Node* current2;
    struct Node* current3 = *head;
    /* put 1~n-1 nodes prev */
    while (current->next != NULL)
    {
        current2 = current;
        current2 = current2->next;
        current2 -> prev = current;
        current = current -> next;
    }
    /* link first node and last node */
    current3 -> prev = current;
    current -> next = current3;
}


/* Function to print linked list */
void printList(struct Node *node)
{
    while (node->next != NULL)
    {
        printf("%s -> ", node->data);
        node = node->next;
    }
    printf("%s",node->data );
    printf("\n");
}
