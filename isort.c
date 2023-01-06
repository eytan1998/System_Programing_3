
#include <stdio.h>

#define SIZE 50

void shift_element(int *arr, int i);

void insert_sort(int *arr, int len);

int main() {
    int arr[SIZE];
    //read array
    for (int i = 0; i < SIZE; ++i) {
        scanf(" %d", (arr + i));
    }
    //sort
    insert_sort(arr, SIZE);
    //print sorted array
    for (int i = 0; i < SIZE - 1; ++i) {
        printf("%d,", *(arr + i));
    }
    printf("%d\n", *(arr + SIZE - 1));
    return 0;
}


void shift_element(int *arr, int i) {
    for (int j = i; j > 0; j--) {
        *(arr + j + 1) = *(arr + j);
    }
}

void insert_sort(int *arr, int len) {
    int key, i, j;
    int counter = 0;

    for (i = 1; i < len; i++) {
        key = *(arr + i);

        counter = 0;
        //find the index to insert
        for (j = i - 1; j >= 0 && *(arr + j) > key; j--) {
            counter++;
        }
        shift_element(arr + j, counter);
        *(arr + j + 1) = key;
    }
}