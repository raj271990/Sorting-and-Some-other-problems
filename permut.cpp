// Program to print permutations of a string of size n

// Import Library
#include<stdio.h>
#include<conio.h>

// Prototypes
void permut(char arr[], int n);
void swap(char arr[], int i, int j);


void permut(char arr[], int n) {
     // Base Case
     if(n==1) printf("%c ", arr[n]);
     // Inductive Step
     else {
          for(int i = 1; i <= n; i++) {
              permut(arr, n-1);
              printf("%c ", arr[n]);
              printf("\n");
              swap(arr, n, n-i);
          }
     }
}

// Helper Swap routine

void swap(char arr[], int i, int j) {
     char swap;
     swap = arr[i];
     arr[i] = arr[j];
     arr[j] = swap;
}

// Client 

int main() {
    char arr[4];
    arr[1] = 'a';
    arr[2] = 'b';
    arr[3] = 'c';
    permut(arr, 3);
    getch();
}

