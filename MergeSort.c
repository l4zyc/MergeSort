#include <stdio.h>

void merge(int *array, int start, int mid, int end) {
    int len = (end - start) + 1;

    int temp[len];

    int i = start, j = mid + 1, k = 0;

    while(i <= mid && j <= end) {
        if(array[i] < array[j]) {
            temp[k++] = array[i++];
        } else {
            temp[k++] = array[j++];
        }
    }

    while(i <= mid) {
        temp[k++] = array[i++]; 
    }

    while(j <= end) {
        temp[k++] = array[j++];
    }

    for(int x = 0; x < len; x++) {
        array[start + x] = temp[x];
    }
    
}

void mergeSort(int *array, int start, int end) {
    if(start < end) {
        int mid = (end + start) / 2;

        mergeSort(array, start, mid);
        mergeSort(array, mid+1, end);

        merge(array, start, mid, end);
    }
};

int main() {

    int array[] = {9,3,2,1,5,6,7,8};
    int size = sizeof(array) / sizeof(array[0]);

    mergeSort(array, 0, size - 1);

    for(int i = 0; i < size ;i++) {
        printf("%d ", array[i]);
    }

    return 0;
}