struct Node
{
    int value;
    struct Node *next;
};

typedef struct Node Node;

typedef Node *List;

void push(List *, int);
void printList(List);
void removeHead(List *);
void removeList(List *);