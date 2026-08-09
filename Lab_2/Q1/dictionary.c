#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100000

/* ---------- Unsorted Array ---------- */

int ua[MAX];

int UA_Search(int n, int key)
{
    int i;
    for (i = 0; i < n; i++)
        if (ua[i] == key) return i;
    return -1;
}

void UA_Insert(int *n, int x)
{
    ua[(*n)++] = x;
}

void UA_Delete(int *n, int key)
{
    int i = UA_Search(*n, key);
    if (i == -1) return;

    for (; i < *n - 1; i++)
        ua[i] = ua[i + 1];

    (*n)--;
}

int UA_MinMax(int n, int max)
{
    int i, x = ua[0];

    for (i = 1; i < n; i++)
        if ((max && ua[i] > x) || (!max && ua[i] < x))
            x = ua[i];

    return x;
}


/* ---------- Sorted Array ---------- */

int sa[MAX];

int SA_Search(int n, int key)
{
    int l = 0, r = n - 1;

    while (l <= r)
    {
        int m = (l + r) / 2;

        if (sa[m] == key) return m;
        if (sa[m] < key) l = m + 1;
        else r = m - 1;
    }

    return -1;
}

void SA_Insert(int *n, int x)
{
    int i = *n - 1;

    while (i >= 0 && sa[i] > x)
    {
        sa[i + 1] = sa[i];
        i--;
    }

    sa[i + 1] = x;
    (*n)++;
}

void SA_Delete(int *n, int key)
{
    int i = SA_Search(*n, key);

    if (i == -1) return;

    while (i < *n - 1)
    {
        sa[i] = sa[i + 1];
        i++;
    }

    (*n)--;
}


/* ---------- Singly Linked List ---------- */

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *head = NULL;

void SL_Insert(int x)
{
    Node *p = malloc(sizeof(Node));
    p->data = x;
    p->next = head;
    head = p;
}

int SL_Search(int key)
{
    Node *p = head;

    while (p)
    {
        if (p->data == key) return 1;
        p = p->next;
    }

    return 0;
}

void SL_Delete(int key)
{
    Node *p = head, *prev = NULL;

    while (p && p->data != key)
    {
        prev = p;
        p = p->next;
    }

    if (!p) return;

    if (prev)
        prev->next = p->next;
    else
        head = p->next;

    free(p);
}


/* ---------- Doubly Linked List ---------- */

typedef struct DNode
{
    int data;
    struct DNode *prev, *next;
} DNode;

DNode *dhead = NULL;

void DL_Insert(int x)
{
    DNode *p = malloc(sizeof(DNode));

    p->data = x;
    p->prev = NULL;
    p->next = dhead;

    if (dhead)
        dhead->prev = p;

    dhead = p;
}

DNode *DL_Search(int key)
{
    DNode *p = dhead;

    while (p)
    {
        if (p->data == key) return p;
        p = p->next;
    }

    return NULL;
}

void DL_Delete(int key)
{
    DNode *p = DL_Search(key);

    if (!p) return;

    if (p->prev)
        p->prev->next = p->next;
    else
        dhead = p->next;

    if (p->next)
        p->next->prev = p->prev;

    free(p);
}


/* ---------- Main ---------- */

int main()
{
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n > MAX)
    {
        printf("Maximum allowed size = %d\n", MAX);
        return 1;
    }

    /* Create data */
    for (i = 0; i < n; i++)
    {
        ua[i] = i;
        sa[i] = i;
        SL_Insert(i);
        DL_Insert(i);
    }

    printf("\nDictionary Operations Complexity\n");
    printf("---------------------------------------------\n");

    printf("\nUnsorted Array:\n");
    printf("Search       : O(n)\n");
    printf("Insert       : O(1)\n");
    printf("Delete       : O(n)\n");
    printf("Min / Max    : O(n)\n");
    printf("Predecessor  : O(n)\n");
    printf("Successor    : O(n)\n");

    printf("\nSorted Array:\n");
    printf("Search       : O(log n)\n");
    printf("Insert       : O(n)\n");
    printf("Delete       : O(n)\n");
    printf("Min / Max    : O(1)\n");
    printf("Predecessor  : O(log n)\n");
    printf("Successor    : O(log n)\n");

    printf("\nSingly Linked List:\n");
    printf("Search       : O(n)\n");
    printf("Insert       : O(1)\n");
    printf("Delete       : O(n)\n");
    printf("Min / Max    : O(n)\n");
    printf("Predecessor  : O(n)\n");
    printf("Successor    : O(n)\n");

    printf("\nDoubly Linked List:\n");
    printf("Search       : O(n)\n");
    printf("Insert       : O(1)\n");
    printf("Delete       : O(1)  (given pointer)\n");
    printf("Min / Max    : O(n)\n");
    printf("Predecessor  : O(1)  (given pointer)\n");
    printf("Successor    : O(1)  (given pointer)\n");

    printf("\nProgram completed for n = %d\n", n);

    return 0;
}