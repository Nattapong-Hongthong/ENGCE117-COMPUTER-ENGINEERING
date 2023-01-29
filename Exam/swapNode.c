#include <stdio.h>
#include <stdlib.h>

struct number {
    int data;
    struct number* next;
};

void AddNode(struct number** start, int new_data)
{
    struct number* new_node = (struct number*) malloc(sizeof(struct number));
    new_node->data = new_data;
    new_node->next = (*start);
    (*start) = new_node;
}

void ShowAll(struct number *node)
{
    while (node != NULL) {
        printf("%d, ", node->data);
        node = node->next;
    }
    printf("\n");
}

void SwapNode(struct number **start, int x, int y)
{
    if (x == y) return;
    struct number *prevX = NULL, *currX = *start;
    struct number *prevY = NULL, *currY = *start;
    while (currX && currX->data != x)
    {
        prevX = currX;
        currX = currX->next;
    }
    while (currY && currY->data != y)
    {
        prevY = currY;
        currY = currY->next;
    }
    if (currX == NULL || currY == NULL)
        return;
    if (prevX != NULL)
        prevX->next = currY;
    else
        *start = currY;
    if (prevY != NULL)
        prevY->next = currX;
    else
        *start = currX;
    struct number *temp = currY->next;
    currY->next = currX->next;
    currX->next = temp;
}

int main() {
    struct number* start = NULL;
    AddNode( &start, 40 );
    AddNode( &start, 30 );
    AddNode( &start, 20 );
    AddNode( &start, 10 );
    ShowAll(start); //10, 20, 30, 40
    SwapNode(&start, 20, 30);
    ShowAll(start); //10, 30, 20, 40
    SwapNode(&start, 40, 10);
    ShowAll(start); //40, 30, 20, 10
    return 0;
}