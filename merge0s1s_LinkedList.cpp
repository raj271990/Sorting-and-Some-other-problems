#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

// Structure of Node
struct Node {
    int val;
    struct Node *next;
};

// Exchange function
void exchg(struct Node *p, struct Node *q) {
     int swap;
     swap = p->val;
     p->val = q->val;
     q->val = swap;
}

// Merge function - This function keeps all 0s at left and all 1s at the right of the list
void merge0s1s(struct Node *head) {
    if(head == NULL) return;
    struct Node *p, *q;
    p = head;
    q = p->next;
    while(q != NULL) {
        if(q->val == 0) {
            p = p->next;
            exchg(p,q);
        }
        q = q->next;
    }
    if(head->val == 1) exchg(head,p);
}

struct Node * listInsert(struct Node *head, struct Node *x) {
    if(head == NULL) head = x;
    else {
         x->next = head;
         head = x;
    }
    return head;
}

struct Node * buildList(int a[], int n) {
       printf("\nInside build List");
       struct Node *head = NULL;
       for(int i = n; i>= 1; i--) {
               struct Node *x;
               x = (struct Node *)malloc(sizeof(Node));
               x->val = a[i];
               x->next = NULL;
               head = listInsert(head, x);
       }
       return head;
}

//client code

int main() {
    int a[11] = {0,0,1,0,1,0,1,0,1,0,1};
    printf("a[10] = %d", a[10]);
    struct Node *head;
    head = buildList(a,10);
    // Print merged list
    printf("\nOriginal List :");
    struct Node *current;
    current = head;
    while(current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    // Merge the list
    merge0s1s(head);
    //Print merged List
    printf("\nMerged List :");
    current = head;
     while(current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    getch();
}
