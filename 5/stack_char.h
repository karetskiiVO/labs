#ifndef STACK_CHAR
#define STACK_CHAR

typedef struct Node
{
    char elem;
    int size;
    struct Node* next;
} Node;

void push(Node** top, char arg);

char pop(Node** top, char* arg);

bool isempty(Node** top);

#endif //stack_char.h