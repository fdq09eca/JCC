#include <stdio.h>
#include <stdlib.h>
//== Node ==
typedef struct
{
    int v;
    Node *next;
} Node;

void node_init(Node *node)
{
    node->v = 0;
    node->next = NULL;
}

void node_release(Node *node)
{
    node->v = 0;
    node->next = NULL;
    free(node);
}

//== LinkedList ==

typedef struct
{
    int count;
    Node *head;
} LinkedList;

void lls_init(LinkedList *lli, Node *head)
{
    lli->count = 0;
    lli->head = head;
}

void lls_release(LinkedList *lli)
{
    lli->count = 0;

    // Node **n = &lli->head;
    // while (*n) {
    //     n = (*n)->next;
    //     node_release(*n);
    // }

    Node *h = lli->head;
    Node *t = NULL;
    while (h)
    {
        t = h->next;
        node_release(h);
        h = t;
        t = NULL;
    }

    // for (Node *h = lli->head, *t; h != NULL; h = t)
    // {
    //     t = h->next;
    //     node_release(h);
    // }
}
// ===============
int main()
{
    return 0;
}
