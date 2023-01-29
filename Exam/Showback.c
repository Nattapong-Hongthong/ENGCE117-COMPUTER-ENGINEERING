#include <stdio.h>
#include <stdlib.h>

struct number {
    int data;
    struct number* next;
};

struct number* start = NULL; 

void AddNode(int data) {
    struct number* temp = (struct number*)malloc(sizeof(struct number));
    temp->data = data;
    temp->next = NULL;
    if(start == NULL) {
        start = temp;
        return;
    }
    struct number* last = start;
    while(last->next != NULL) {
        last = last->next;
    }
    last->next = temp;
}

void ShowAll() {
    struct number* temp = start;
    if(temp == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("");
    while(temp != NULL) {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void ShowBack() {
    struct number* temp = start;
    if(temp == NULL) {
        printf("List is empty\n");
        return;
    }
    struct number *current, *prev, *next;
    current = start;
    prev = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    start = prev;
    temp = start;
    printf("");
    while(temp != NULL) {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    AddNode(10);
    AddNode(20);
    AddNode(30);
    AddNode(40);
    ShowAll(); //10, 20, 30, 40
    ShowBack(); //40, 30, 20, 10
    return 0;
}
