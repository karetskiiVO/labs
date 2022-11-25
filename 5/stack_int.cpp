#include "stack_int.h"
#include <stdio.h>
#include <stdlib.h>

void push_int(Node_int** top, int arg)
{
    Node_int* tmp = (Node_int*) calloc(sizeof(Node_int),1);
    tmp->elem = arg;
    tmp->next = (*top);
    (*top) = tmp;
    free(tmp);
    (*top)->size++;
}

int pop_int(Node_int** top, int* arg)
{
    if(isempty(top))
    {
        printf("stack is empty");
        return 0;
    }
    Node_int* tmp = (*top);
    *arg = (*top)->elem;
    (*top) = (*top)->next;
    (*top)->size--;
    free(tmp);
    return *arg;
}

bool isempty(Node_int** top)
{
    if((*top)->size == 0)
    {
        return true;
    }
    return false;
}