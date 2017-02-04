// Heap Sort Algo

#include<stdio.h>
#include<conio.h>

// function prototypes
void sort(int a[], int n);
void sink(int a[], int n, int k);
void swim(int a[], int n, int k);
void exchg(int a[], int i, int j);
bool less(int a[], int i, int j);

// Sort function

void sort(int a[], int n) {
     // Build max heap
     for(int i = n/2; i >= 1; i--) sink(a,n,i);
     // exchange first element with the last and decrease array size by 1 and then sink on the first element
     while(n > 1) {
             exchg(a,1,n);
             n--;
             sink(a,n,1);
     }
}

// Sink function
void sink(int a[], int n, int k) {
    while(2*k <= n) {
        int j = 2*k;
        if(j<n && less(a,j,j+1)) j++;
        if(!less(a,k,j)) break;
        exchg(a,k,j);
        k = j;     
    }
}

// Swim function
void swim(int a[], int n, int k) {
    while((k/2) > 0 && less(a,k/2,k)) {
        exchg(a,k/2,k);
    }
}


// exchange helper function
void exchg(int a[], int i, int j) {
     int swap = a[i];
     a[i] = a[j];
     a[j] = swap;
}

// less helper fuction

bool less(int a[], int i, int j) {
     return (a[i] < a[j]);
}

// client call
int main() {
    int n;
    printf("Enter array size : ");
    scanf("%d", &n);
    int a[n+1];
    printf("\nEnter array elements : ");
    for(int i = 1; i<=n; i++) scanf("%d", &a[i]);
    printf("\n Input array : ");
    //printf("I am here");
    for(int i = 1; i<=n; i++) printf("%d ", a[i]);
    sort(a,n);
    printf("\n Sorted array : ");
    for(int i = 1; i<=n; i++) printf("%d ", a[i]);
    getch();
}
