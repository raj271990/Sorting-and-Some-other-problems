// Reverse a list
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node {
       int n;
       struct Node *next; 
};

struct Node * reverseList(struct Node *start);
struct Node * insert(int i, struct Node * current);


struct Node * reverseList(struct Node *start) {
       struct Node *previous = NULL;
       struct Node *current = start;
       struct Node *next;
       while(current != NULL) {
                     next = current->next;
                     current->next = previous;
                     previous = current;
                     current = next; 
       }
       return previous;
}

struct Node * nodeFromEnd(struct Node *current, int n) {
       struct Node *front, *back;
       front = back = current;
       
       // Move front pointer n times
       for(int i=1; i<=n; i++) {
               front = front -> next;
       }
       while(front != NULL) {
                   front = front -> next;
                   back = back ->next;
       }
       return back;
}

struct Node * insert(int i, struct Node * current) {
       struct Node * oldcurrent = current;
       current = (struct Node *)malloc(sizeof(Node));
       current -> n = i;
       current -> next = oldcurrent;
       oldcurrent = NULL;
       return current;
}

//client

int main() {
    struct Node *start = NULL;
    for(int i=1; i<=5; i++) {
            start = insert(i, start);
    }
    printf("Printing the list\n");
    struct Node *current = start;
    while(current!=NULL) {
        printf("%d->", current->n);
        current = current ->next;
    }
    // Call nth node from end and print the result
    current = nodeFromEnd(start, 1);
    printf("1rd node from end = %d", current -> n);
    
    // We have a list of 5 items now... Let's reverse the list
    start = reverseList(start);
    current = start;
    printf("\nReversed List");
    while(current != NULL) {
                  printf("%d->", current->n);
                  current = current -> next;
    }
    
    getch();
}
