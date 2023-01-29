#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct number{
    int data;
    struct number* next;
};

void AddNode(struct number** start, int data){
    struct number* newNode = (struct number*) malloc(sizeof(struct number));
    newNode->data = data;
    newNode->next = *start;
    *start = newNode;
}

void ShowAll(struct number* start) {
    struct number* temp = start;
    printf("");
    while (temp != NULL) {
        printf("%d, ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void Update(struct number** start, int searchValue, int newValue) {
    struct number* temp = *start;
    struct number* prev = NULL;
    while (temp != NULL) {
        if (temp->data == searchValue) {
            if(prev != NULL)
                prev->next = temp->next;
            else
                start = temp->next;
            temp->data = newValue;
            temp->next = start;
            start = temp;
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

int main() {
    struct Node* start = NULL;
    AddNode(&start, 40);
    AddNode(&start, 30);
    AddNode(&start, 20);
    AddNode(&start, 10);
    ShowAll(start); //10, 20, 30, 40
    Update(&start, 10, 99);
    ShowAll(start); //99, 20, 30, 40
    Update(&start, 10, 98);
    ShowAll(start); //99, 20, 30, 40
    return 0;
}