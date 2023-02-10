#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct studentNode {
char name[20] ;
int age ;
char sex ;
float gpa ;
struct studentNode *next ;
} ;

void ShowAll( struct studentNode *walk ) ;

struct studentNode* AddNode(struct studentNode **start, char name[20], int age, char sex, float gpa) {
    struct studentNode *newNode = (struct studentNode*)malloc(sizeof(struct studentNode));
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->sex = sex;
    newNode->gpa = gpa;
    newNode->next = NULL;
    if (*start == NULL) {
        *start = newNode;
    }
    else {
        struct studentNode *temp = *start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return newNode;
}

void InsNode(struct studentNode *current, char name[20], int age, char sex, float gpa) {

    struct studentNode *newNode = (struct studentNode*) malloc(sizeof(struct studentNode));
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->sex = sex;
    newNode->gpa = gpa;
    newNode->next = current->next;
    current->next = newNode;
}

void DelNode(struct studentNode **start, struct studentNode *current) {
    if (*start == NULL) {
        printf("Linked list is empty\n");
        return;
    }
    if (*start == current) {
        *start = current->next;
        free(current);
        return;
    }
    struct studentNode *prev = *start;
    while (prev->next != current) {
        prev = prev->next;
    }
    prev->next = current->next;
    free(current);
}


void ShowAll( struct studentNode *walk ) {
    while( walk != NULL ) {
        printf( "%s ", walk->name ) ;
        walk = walk->next ;
    }//end function
    printf( "\n") ;
}



int main() {
    struct studentNode *start, *now ;
    start = NULL ;
    now = AddNode( &start, "one", 6, 'M', 3.11 ) ; ShowAll( start ) ;
    now = AddNode( &start, "two", 8, 'F', 3.22 ) ; ShowAll( start ) ;
    InsNode( now, "three", 10, 'M', 3.33 ) ; ShowAll( start ) ;
    InsNode( now, "four", 12, 'F', 3.44 ) ; ShowAll( start ) ;
    DelNode( &start, now ) ; ShowAll( start ) ;
    return 0 ;
}//end function

