#ifndef STACK_INT
#define STACK_INT

typedef struct Node_int
{
    struct Node_int* next;
    int elem;
    int size;
} Node_int;

void push_int(Node_int** top, int arg);

int pop_int(Node_int** top, int* arg);

bool isempty(Node_int** top);

#endif //stack_int.h