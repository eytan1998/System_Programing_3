

#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define SIZE 50

void shift_element(int *arr, int i);

void insert_sort(int *arr, int len);

int main() {
    int arr[SIZE];
    for (int i = 0; i < SIZE; ++i) {
        scanf(" %d", (arr + i));
    }
    insert_sort(arr, SIZE);
    printf("%d", *arr);
    for (int i = 1; i < SIZE; ++i) {
        printf(",%d", *(arr + i));
    }
    printf("\n");
    return 0;
}


void shift_element(int *arr, int i) {
    for (int j = i; j > 0; j--) {
        *(arr + j + 1) = *(arr + j);
    }
}

void insert_sort(int *arr, int len) {
    int key, j;
    for (int i = 1; i < len; i++) {
        key = *(arr + i);
        j = i - 1;

        int counter = 0;
        while (j >= 0 && *(arr + j) > key) {
            counter++;
            j = j - 1;
        }
        shift_element(arr + j, counter);
        *(arr + j + 1) = key;
    }
}