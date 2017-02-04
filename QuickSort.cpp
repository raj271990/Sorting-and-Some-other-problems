// Quick Sort Algorithm Implementation

// Include necessary libraries
#include<stdio.h>
#include<conio.h>

// Function prototypes
void quickSort(int a[], int i, int j, int *len);
int partition(int a[], int i, int j, int * len);
void swap(int a[], int i, int j);
bool less(int a, int b);

// quickSort routine
void quickSort(int a[], int i, int j, int *len) {
     // Base condition
     if(j<=i) return;
     //Inductive step
     int k = partition(a, i, j, len);
     quickSort(a, i, k-1, len);
     quickSort(a, k+1, j, len);
}

// private partition routine
int partition(int a[], int i, int j, int * len) {
    // we will maintain invariant p. The elements before this location would be smaller than or equal to pivot element [we will be choosing first element as the pivot element
    // to parttion the array] and those after would be greater
    int size = *len - 1;
    int pivot = a[i],p =i;
    for(int t = i+1; t <= size; t++) {
            if(less(a[t],pivot)) {
                          p = p + 1;
                          swap(a, p, t);
            }
    }
    // Take pivot to index of p
    swap(a, i, p);
}

//helper functions

void swap(int a[], int i, int j) {
     int swap = a[i];
     a[i] = a[j];
     a[j] = swap;
}

bool less(int a, int b) {
     if(a < b) {
          return true;
     }
     return false;
}


// Client code

int main() {
    int n, i;
    printf("Enter the number of elements to be sorted\n");
    scanf("%d", &n);
    int a[n];
    for(i=0 ; i < n; i++) {
            scanf("%d", &a[i]);
    }
    quickSort(a, 0, (n-1), &n);
    //print the sorted array
    for(i=0; i < n ; i++) {
         printf("a[%d] = %d\n", i, a[i]);
    }
    getch();
}
