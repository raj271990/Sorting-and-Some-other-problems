// Merege Sort Algorithm Implementation - Recursive algorithm
#include<stdio.h>
#include<conio.h>

//Function prototypes
void mergeSort(int a[], int i, int j, int * len);
void merge(int a[], int i, int mid, int j, int * len);
bool less(int a, int b);


// Sort Function

void mergeSort(int a[], int i, int j, int * len) {
          printf("i = %d and j = %d\n", i, j);
          //Basis condition
          if(j<=i) return;
          // Inductive Step - Decomposition and Recomposition
          int mid;
          mid = i + (j-i) / 2;
          printf(" mid = %d\n", mid);
          // Decomposition
          mergeSort(a, i, mid, len);
          mergeSort(a, mid+1, j, len);
          // Recomposition - merge opearation - This function would be hidden to client
          merge(a, i, mid, j, len);
}

// Any private function - private as in, hidden to client

void merge(int a[], int i, int mid, int j, int * len) {
          printf("size of a = %d",sizeof(a));
          int size = *len;     
          int b[size];
          printf("size of b = %d",sizeof(b));
          int k;
          
          // copy all the elements of array a to array b. We are doing this, as we would be doing all over processing over array b and merge into a, so that array a is sorted
          
          for(k = i; k <= j; k++) {
                b[k] = a[k];
          }
          
          //Initialize two variables, which would help us to traverse through two sorted sub arrays. There are not actually two separate sub arrays
          int p = i, q = mid + 1, r = i;
          
          while(p <= mid && q <= j) {
                  if(less(b[p], b[q])) {
                              a[r++] = b[p++];
                  }
                  else {
                              a[r++] = b[q++];
                  }
          }
          
          // In case the second half of b gets completed and first half remains
          
          while(p <= mid) {
                  a[r++] = b[p++];
          }
          
          // In case the first half of b gets completed and second half remains
          
          while(q <= j) {
                  a[r++] = b[q++];
          }
}

//helper functions

bool less(int a, int b) {
     if(a < b) {
          return true;
     }
     return false;
}

// Client Code

int main() {
    int n, i;
    printf("Enter the number of elements to be sorted\n");
    scanf("%d", &n);
    int a[n];
    printf("Value of n = %d", n);
    printf("Enter the elements now\n");
    for(i=0 ; i < n; i++) {
            scanf("%d", &a[i]);
    }
    printf("Inside main, size of a = %d", sizeof(a));
    // Print unsorted array
    printf("Unsorted Array -> ");
    for(i=0 ; i < n; i++) {
            printf("%d", a[i]);
    }
    printf("Value of (n-1) = %d", n-1);
    mergeSort(a, 0, (n-1), &n);
    
    //print the sorted array
    for(i=0; i < n ; i++) {
         printf("a[%d] = %d\n", i, a[i]);
    }
    getch();
}
