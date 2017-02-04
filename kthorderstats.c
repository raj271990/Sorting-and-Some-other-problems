// Kth order statistics
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

// Function prototypes
int kthOrderMin(int a[],int n, int k);
int kMin(int a[], int i, int j, int k);
int partition(int a[], int i, int j);
void swap(int a[], int i, int j);
bool less(int a, int b);

// Public kMin routine
int kthOrderMin(int a[],int n, int k) {
    return(kMin(a, 1, n, k));

}

// Private kMin routine - recursuve in nature
int kMin(int a[], int i, int j, int k) {
    // Base condition
    if(i == j) return a[i];
    // Inductive Step
    int p = partition(a, i, j);
    if(k == p) {
         return a[p];
    }
    else if(k < p) { return(kMin(a, i, p-1, k)); }
    else { return(kMin(a, p+1, j, p-k));}
}

// Private partition routine

int partition(int a[], int i, int j) {
    // we will maintain invariant p. The elements before this location would be smaller than or equal to pivot element [we will be choosing first element as the pivot element
    // to partition the array] and those after would be greater
    int pivot = a[i],p =i;
    for(int t = i+1; t <= j; t++) {
            if(less(a[t],pivot)) {
                p = p + 1;
                swap(a, p, t);
            }
    }
    // Take pivot to index of p
    swap(a, i, p);
    return p;
}

// Helper functions - if any

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
    int n;
    printf("Enter the array size\n");
    scanf("%d", &n);
    int a[n+1], i, result, k;
    printf("Enter the elem\n");
    for(i=1; i<=n; i++) {
             scanf("%d", &a[i]);
    }
    printf("Enter the kth mean\n");
    scanf("%d", &k);
    result = kthOrderMin(a,n,k);
    printf("\nResult = %d", result);
    getch();
}
