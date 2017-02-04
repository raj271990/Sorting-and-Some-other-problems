// Selection Sort Algorith1qm Implementation

// Include library files
#include<stdio.h>
#include<conio.h>

//Function prototypes
int findMin(int a[], int i, int j);
void swap(int a[], int i, int j);
bool less(int a, int b);

// Sort function
void sort(int a[], int i, int j) {
     int min,k;
     for(k = i; k <= j; k++) {
           //Call function which returns index of minimum element
           min = findMin(a, k, j);
           // Got the minimum - so swap with first element
           swap(a, k, min);
     }
}

// findMin function
int findMin(int a[], int i, int j) {
    int trav, min;
    min = i;
    for(trav = i; trav <= j; trav++) {
             if(less(a[trav], a[min])) {
                              min = trav;
             }
    }
    return min;
}


// Helper functions

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

// Client

int main() {
    int a[100], n, i;
    printf("Enter the number of elements to be sorted\n");
    scanf("%d", &n);
    for(i=0 ; i < n; i++) {
            scanf("%d", &a[i]);
    }
    sort(a, 0, (n-1));
    
    //print the sorted array
    for(i=0; i < n ; i++) {
         printf("a[%d] = %d\n", i, a[i]);
    }
    getch();
}
