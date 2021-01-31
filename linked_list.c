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
    Node *node = (Node *)malloc(sizeof(Node));
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
    size_t len;
    Node *head;
} LinkedList;

LinkedList *lls_init(int v)
{
    LinkedList *lls = (LinkedList *)malloc(sizeof(LinkedList));
    lls->head = node_init(v);
    lls->len++;
    return lls;
}

void lls_release(LinkedList *lls)
{
    lls->len = 0;

    Node *p = lls->head;
    Node *next; // tmp pointer
    while (p)   // free all node.
    {
        next = p->next;
        node_release(p);
        p = next;
    }
    free(lls);
}

Node *lls_lastnode(LinkedList *lls)
{
    Node *p = lls->head;
    while (p->next)
    {
        p = p->next;
    }
    return p;
}

void lls_push(LinkedList *lls, Node *node)
{
    Node *p = lls->head;
    node->next = p;
    lls->head = node;
    lls->len++;
}

void lls_append(LinkedList *lls, Node *node)
{

    lls_lastnode(lls)->next = node;
    lls->len++;
}

Node *lls_find(LinkedList *lls, int v)
{
    Node *p = lls->head;
    while (p)
    {
        if (p->v == v)
        {
            break; // return the 1st occurence.
        }
        p = p->next;
    }
    return p; // return NULL if not found
}

Node *lls_hasNode(LinkedList *lls, Node *t_node)
{

    for (Node *p = lls->head; p; p = p->next)
    {
        if (p == t_node)
        {
            return p;
        }
    }
    printf("t_node is not in the linkedlist");
    return NULL;
}

Node *lls_find_previous(LinkedList *lls, Node *t_node)
{
    for (Node *p = lls->head; p; p = p->next)
    {
        if (p->next == t_node)
        {
            return p;
        }
    }
    return NULL; // if t_node is head: return NULL;
}

Node *lls_pop_head(LinkedList *lls)
{
    Node *p = lls->head;
    lls->head = lls->head->next;
    return p;
}

Node *lls_pop_tail(LinkedList *lls)
{

    if (!lls->head->next)
    {
        return lls_pop_head(lls);
    }

    for (Node *p = lls->head, *e; p; p = p->next)
    {
        if (p->next->next == NULL)
        {
            e = p->next;
            p->next = NULL;
            return e;
        }
    }

    return NULL;
}

Node *lls_pop_value(LinkedList *lls, int v)
{
    Node *n;
    Node *pv_n;

    if (lls->head->v == v)
    {
        return lls_pop_head(lls);
    }

    for (Node *p = lls->head; p; p = p->next)
    {

        if (p->next->v == v)
        {
            pv_n = p;
            n = p->next;
            pv_n->next = n->next;
            return n; // 1st occurence
        }
    }
    return NULL;
}

void lls_inserta(LinkedList *lls, Node *t_node, Node *i_node)
{
    if (!lls_hasNode(lls, t_node))
    {
        return;
    }

    i_node->next = t_node->next ? t_node->next : NULL;
    t_node->next = i_node;
    lls->len++;
}

void lls_print(LinkedList *lls)
{
    printf("lls len: %zu\n", lls->len);
    for (Node *p = lls->head; p; p = p->next)
    {
        printf("[%i]->", p->v);
    }
    printf("|\n");
}

// void lls_info(LinkedList *lls) {

//     lls_print(lls);
// }

// ===============
int main()
{

    LinkedList *lls = lls_init(1);

    lls_append(lls, node_init(2));
    Node *z = node_init(0);
    lls_push(lls, z);
    Node *f = node_init(5);
    Node *f2 = node_init(5);
    lls_inserta(lls, z, f);
    lls_print(lls);
    printf("lls_find 2: %i\n", lls_find(lls, 2)->v);
    printf("lls_find 8: %p\n", lls_find(lls, 8));
    printf("lls_find_previous 5: %i\n", lls_find_previous(lls, f)->v);   // 0
    printf("lls_find_previous 5 (*): %p\n", lls_find_previous(lls, f2)); // 0x0
    lls_pop_head(lls);
    puts("pop head:");
    lls_print(lls);
    lls_pop_tail(lls);
    puts("pop tail:");
    lls_print(lls);
    lls_pop_value(lls, 5);
    puts("pop value: ");
    lls_print(lls);
    lls_pop_value(lls, 1);
    puts("pop value: ");
    lls_print(lls);
    lls_release(lls);

    return 0;
}
