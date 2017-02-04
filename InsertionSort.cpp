// Insertion sort

#include<stdio.h>
#include<conio.h>
#include<math.h>

// Function prototypes

bool less(int a, int b);
void swap(int a[], int i, int j);
void sort(int a[], int i, int j);


// Sort function - Doesn't return anything, o(n^2) worst case - Reverse sorted case , o(n) best case - Already sorted case

void sort(int a[], int i, int j) {
    int k,l;     
    for(k=i; k <= j; k++) {
         for(l = k; l > 0; l--) {
               if(less(a[l], a[l-1])) {
                             swap(a, l, l-1);
               }
               else {break;}
         }
    }  
}


// Helper function - swap [Not exposed to client]

void swap(int a[], int i, int j) {
     int swap = a[i];
     a[i] = a[j];
     a[j] = swap;
}

// Helper function - less [Not exposed to client]

bool less(int a, int b) {
     if(a < b) {
          return true;
     }
}

// Client Code

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
