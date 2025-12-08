#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    if (n<2 || n>100){
        return 1;
    }
    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int *ptr = arr;
    int largest = *ptr;
    int second = -1000000; 

    for (int i = 1; i < n; i++) {
        ptr++;
        if (*ptr > largest) {
            second = largest;
            largest = *ptr;
        } else if (*ptr == largest){
            largest = *ptr;
        } else if (*ptr > second && *ptr != largest) {
            second = *ptr;
        }
    }

    printf("Second largest = %d\n", second);
    return 0;
}