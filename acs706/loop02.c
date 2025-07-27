#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int mul = 1;
    for (int i = 1; i <= N; i++) {
        mul *= i;
    }

    printf("%d\n", mul);
    return 0;
}