///////////////////////////////////////////
/////////// Radix Sort   TO CHECK /////////
///////////////////////////////////////////


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A utility function to get the maximum value in arr[]
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// A function to do counting sort of arr[] according to the digit represented by exp.
void countingSort(int arr[], int n, int exp) {
    int output[n]; // output array
    int i, count[10] = {0};

    // Store count of occurrences in count[]
    for (i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Change count[i] so that count[i] now contains the actual position of this digit in output[]
    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr now contains sorted numbers according to the current digit
    for (i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// The main function to that sorts arr[] of size n using Radix Sort
void radixSort(int arr[], int n) {
    // Find the maximum number to know the number of digits
    int m = getMax(arr, n);

    // Do counting sort for every digit. Note that instead of passing digit number,
    // exp is passed. exp is 10^i where i is the current digit number
    for (int exp = 1; m / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

// A utility function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Driver program to test above functions
int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: ");
    printArray(arr, n);
    radixSort(arr, n);
    printf("Sorted array: ");
    printArray(arr, n);
    return 0;
}