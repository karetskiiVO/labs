#include "stack_char.h"
#include <stdio.h>
#include <stdlib.h>

void push(Node** top, char arg)
{
    Node* tmp = (Node*) calloc(sizeof(Node),1);
    tmp->elem = arg;
    tmp->next = (*top);
    (*top) = tmp;
    free(tmp);
    (*top)->size++;
}

char pop(Node** top, char* arg)
{
    if(isempty(top))
    {
        printf("stack is empty\n");
        return 0;
    }
    Node *st = (*top);
    *arg = (*top)->elem;
    (*top) = (*top)->next;
    (*top)->size--;
    free(st);
    return *arg;
}

bool isempty(Node** top)
{
    if((*top)->size == 0)
    {
        return true;
    }
    return false;
}

