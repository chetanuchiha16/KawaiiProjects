#include <stdio.h>
#include <stdlib.h>
void stack();

typedef struct node {
  int sem, phno;
  char name[20], usn[20], branch[20];
  struct node *next;
} NODE;
NODE *head = NULL;

void insert_front() {
  NODE *newnode = NULL;
  newnode = (NODE *)malloc(sizeof(NODE));
  printf("Enter the usn name branch sem phno\n");
  scanf("%s%s%s%d%d", newnode->usn, newnode->name, newnode->branch,
        &newnode->sem, &newnode->phno);
  newnode->next = head;
  head = newnode;
}

void create(int data) {
  int i, n;
  printf("Enter the number of nodes\n");
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    insert_front();
  }
}

void del_front() {
  NODE *cur;
  if (head == NULL)
    printf("NOthing to delete\n");
  cur = head;
  head = head->next;
  printf("deleted info\n");
  printf("%s\t%s\t%s\t%d\t%d\n", cur->usn, cur->name, cur->branch, cur->sem,
         cur->phno);
  free(cur);
}

void insert_end() {
  NODE *cur;
  NODE *newnode = NULL;
  newnode = (NODE *)malloc(sizeof(NODE));
  printf("Enter the usn name branch sem phno\n");
  scanf("%s%s%s%d%d", newnode->usn, newnode->name, newnode->branch,
        &newnode->sem, &newnode->phno);

  if (head == NULL) {
    newnode->next = head;
    head = newnode;
    newnode->next = NULL;
  } else {
    cur = head;
    while (cur->next != NULL)
      cur = cur->next;
    cur->next = newnode;
    newnode->next = NULL;
  }
}

void del_end() {
  NODE *cur, *pre;
  if (head = NULL)
    printf("nothing to print\n");
  else if (head->next = NULL) {
    printf("deleted info\n");
    printf("%s\t%s\t%s\t%d\t%d\n", cur->usn, cur->name, cur->branch, cur->sem,
           cur->phno);
    free(head);
    head = NULL;
  } else {
    cur = head;
    pre = cur;
    while (cur->next != NULL) {
      pre = cur;
      cur = cur->next;
    }
    printf("deleted info\n");
    printf("%s\t%s\t%s\t%d\t%d\n", cur->usn, cur->name, cur->branch, cur->sem,
           cur->phno);
    pre->next = NULL;
    free(cur);
  }
}

void display() {
  NODE *cur;
  int count = 0;

  if (head == NULL)
    printf("NOthing to print\n");

  else {
    cur = head;
    while (cur != NULL) {
      printf("%s\t%s\t%s\t%d\t%d\n", cur->usn, cur->name, cur->branch, cur->sem,
             cur->phno);
      cur = cur->next;
      count++;
    }
  }
  printf("count=%d", count);
}

void main_menu() {
  int ch;
  while (1) {
    printf("1.stack\n2.insertend\n3.delend\ndisplay");
    scanf("%d", &ch);
    switch (ch) {
    case 1:
      stack();
      break;
    case 2:
      insert_end();
      break;
    case 3:
      del_end();
      break;
    case 4:
      display();
      break;
    }
  }
}

void stack() {
  int ch;
  while (1) {
    printf("\n1.push\n2.pop\n3.display");
    scanf("%d", &ch);
    switch (ch) {
    case 1:
      insert_front();
      break;
    case 2:
      del_front();
      break;
    case 3:
      display();
      break;
    case 4:
      main_menu();
      break;
    }
  }
}

int main() {
  main_menu();
  return 0;
}