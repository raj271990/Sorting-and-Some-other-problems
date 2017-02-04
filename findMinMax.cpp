#include<stdio.h>
#include<conio.h>

//Function prototypes
void calculateMinMax(int a[]);
void swap(int *i, int *j);
bool less(int a, int b);

// Function to calculate max and min from an array passed to it

void calculateMinMax(int a[], int n) {
     int max, min, i=0;
     // If array has only one element
     if(n == 1) {
          max = min = a[0];
          printf("%d %d", min, max);
          return;
     }
     if(n == 2) {
          max = a[0];
          min = a[1];
          if(less(max,min)) {swap(&min, &max);}
          printf("%d %d", min, max);
          return;
     }
     //Now if, we are here n is greater than 2 for sure
     max = min = a[i++];
     // If we have odd number of elements left out, we should pick one more element
     if( (n-1) % 2 != 0) {
         max = a[i++];
         if(less(max,min)) swap(&min, &max);
     }
     // Now we will loop through the entire array
     for(int j = i; j < n; j = j + 2) {
             if(less(a[j],a[j+1])){
                 if(less(a[j],min)) min = a[j];
                 if(less(max, a[j+1])) max = a[j+1];
             }
             else {
                 if(less(a[j+1], min)) min = a[j+1];
                 if(less(max,a[j])) max = a[j];
             }
     } 
     printf("%d %d", min, max);
}

// Helper functions

void swap(int *i, int *j) {
     int *swap = i;
     *i = *j;
     *j = *swap;
}

bool less(int a, int b) {
     if(a < b) {
          return true;
     }
     return false;
}

// Client code
int main()
{
    int a[8] = {5,4,7,1,3,9,8,100};
    calculateMinMax(a, 8);
    getch();
}
