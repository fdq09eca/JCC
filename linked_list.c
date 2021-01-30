#include <stdio.h>
#include <stdlib.h>
//== Node ==
typedef struct Node
{
    int v;
    struct Node *next;
} Node;

Node *node_init(int v)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->v = v;
    node->next = NULL;
    return node;
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

void lls_insert(LinkedList *lls, Node* node)
{
}

LinkedList* lls_init(int v)
{
    LinkedList* lls = (LinkedList*) malloc(sizeof(LinkedList));
    lls->count = 0;
    lls->head = node_init(v);
    return lls;
}

void lls_release(LinkedList *lls)
{
    lls->count = 0;

    Node *p = lls->head;
    Node *next = NULL;
    while (p) // free all node.
    {
        next = p->next;
        node_release(p);
        p = next;
    }
    free(lls);
    // return;
}

void lls_print(LinkedList *lls)
{
    for (Node *p = lls->head; p; p = p->next)
    {
        printf("[%i]->", p->v);
    }
    printf("|");
}

// void lls_insert(LinkedList *lls, Node *n)
// {
// }

// Node *lls_pop_head(LinkedList *lls)
// {
//     Node *p_head = lls->head;
//     lls->head = p_head->next return p_head;
// }

// ===============
int main()
{
    
    LinkedList* lls = lls_init(1);
    lls_print(lls);
    lls_release(lls);

    return 0;
}
