#include <stdio.h>

int main() {
    int arr[] = {2, 7, 4, 5, 1, 3};
    int n = 6;
    int target = 6;
    int i, j;

    printf("Pairs with sum %d are:\n", target);

    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(arr[i] + arr[j] == target) {
                printf("(%d, %d)\n", arr[i], arr[j]);
            }
        }
    }

    return 0;
}