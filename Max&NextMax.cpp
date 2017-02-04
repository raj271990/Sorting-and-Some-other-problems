// Find Max and Next Max

// Libraries
#include<stdio.h>
#include<conio.h>

// Function prototypes
void Max_NextMax(int a[], int n);
bool less(int a, int b);
int findMin(int a[], int i, int j);
int maxOf(int a, int b);

// Max and Next Max Function
void Max_NextMax(int a[], int n) {
     int maxArr[2*n];
     for(int i = n,j=2*n-1; i>=1; i--,j--) {
             maxArr[j] = a[i];
     }
     for(int i = 2*n-2; i > 1; i=i-2) {
             maxArr[(i/2)] = maxOf(maxArr[i], maxArr[i+1]);
     }
     printf("Max = %d\n", maxArr[1]);
     
     int nextMax = findMin(a,1,n);
     int i=1;
     while(2*i < (2*n-1)) {
             int j = 2*i;
             if(less(maxArr[j], maxArr[j+1])){
                 if(less(nextMax,maxArr[j])) {nextMax = maxArr[j];}
                 i = j+1;
             }
             else {
                  if(less(nextMax,maxArr[j+1])){nextMax = maxArr[j+1];}
                  i = j;
             }
     }
     printf("NextMax = %d\n", nextMax);
}

// Helper

bool less(int a, int b) {
     if(a < b) return true;
     return false;
}

int findMin(int a[], int i, int j) {
    int min = i;
    for(int k = i+1; k<=j; k++) {
            if(less(a[k], a[min])) min = k;
    }
    return a[min];
}

int maxOf(int a, int b) {
    if(a >= b) return a;
    return b;
}

// Client

int main() {
    int n;
    printf("Enter array size\n");
    scanf("%d", &n);
    int a[n+1];
    printf("Enter the elements into array\n");
    for(int i = 1; i<=n; i++) {
            scanf("%d",&a[i]);
    }
    Max_NextMax(a,n);
    getch();
}
