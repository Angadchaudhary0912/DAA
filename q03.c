#include <stdio.h>

int main() {
    int n1, n2, i, j, k;

    printf("Enter the size of first sorted array: ");
    scanf("%d", &n1);

    int arr1[n1];

    printf("Enter the elements of first sorted array:\n");
    for(i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the size of second sorted array: ");
    scanf("%d", &n2);

    int arr2[n2];
    int merged[n1 + n2];

    printf("Enter the elements of second sorted array:\n");
    for(i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }

    i = 0;
    j = 0;
    k = 0;

    while(i < n1 && j < n2) {
        if(arr1[i] <= arr2[j]) {
            merged[k] = arr1[i];
            i++;
        } else {
            merged[k] = arr2[j];
            j++;
        }
        k++;
    }

    while(i < n1) {
        merged[k] = arr1[i];
        i++;
        k++;
    }

    while(j < n2) {
        merged[k] = arr2[j];
        j++;
        k++;
    }

    printf("Merged sorted array:\n");
    for(i = 0; i < n1 + n2; i++) {
        printf("%d ", merged[i]);
    }

    return 0;
}