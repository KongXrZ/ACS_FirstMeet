#include <stdio.h>

int main() {
    int N,i;
    scanf("%d", &N);

    int candy[N];
    int count = 0;

    for (i=0; i<N;i++) {
        scanf("%d", &candy[i]);
    }
    for (i=0; i<N;i++) {
        if (candy[i]%2 == 0) {
            count++;
        }
    }
    printf("Boxes with even candies: ");
    printf("%d", count);
    return 0;
}
