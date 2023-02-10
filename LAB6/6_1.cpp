#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct studentNode {
  char name[20];
  int age;
  char sex;
  float gpa;
  struct studentNode *next;
  struct studentNode *back;
};

struct studentNode *AddNode(struct studentNode **start, char *name, int age,
                            char sex, float gpa) {
  struct studentNode *newNode, *walk;
  newNode = (struct studentNode *)malloc(sizeof(struct studentNode));
  strcpy(newNode->name, name);
  newNode->age = age;
  newNode->sex = sex;
  newNode->gpa = gpa;
  newNode->next = NULL;
  if (*start == NULL) {
    *start = newNode;
    newNode->back = NULL;
  } // end if
  else {
    walk = *start;
    while (walk->next != NULL) {
      walk = walk->next;
    } // end while
    walk->next = newNode;
    newNode->back = walk;
  } // end else
  return newNode;
} // end function

void ShowAll(struct studentNode *walk) {
  while (walk != NULL) {
    printf("%s ", walk->name);
    walk = walk->next;
  } // end while
  printf("\n");
} // end function

void DelNode(struct studentNode **now) {
  struct studentNode *temp;
  if ((*now)->back == NULL && (*now)->next == NULL) {
    *now = NULL;
  } else if ((*now)->back == NULL) {
    (*now)->next->back = NULL;
    *now = (*now)->next;
  } else if ((*now)->next == NULL) {
    (*now)->back->next = NULL;
    *now = (*now)->back;
  } else {
    temp = (*now)->next;
    (*now)->next->back = (*now)->back;
    (*now)->back->next = temp;
    *now = temp;
  }
  free(*now);
}
int main() {
  struct studentNode *start, *now;
  start = NULL;
  now = AddNode(&start, "one", 6, 'M', 3.11);
  ShowAll(start);
  now = AddNode(&start, "two", 8, 'F', 3.22);
  ShowAll(start);
  now = AddNode(&start, "three", 10, 'M', 3.33);
  ShowAll(start);
  now = AddNode(&start, "four", 12, 'F', 3.44);
  ShowAll(start);
  return 0;
} // end function