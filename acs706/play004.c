#include <stdio.h>

int main() {
    int arr[42] = {0};
    int count = 0;
    int i, x, r;

    for(i = 0; i < 10; i++) {
        scanf("%d", &x);
        r = x % 42;
        if(arr[r] == 0) {
            arr[r] = 1;
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}
