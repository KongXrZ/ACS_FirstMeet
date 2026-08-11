#include <stdio.h>

int main() {
    int N,i;
    scanf("%d", &N);

    int items[N];
    for(i=0;i<N;i++){
        scanf("%d",&items[i]);
    }

    int temp = items[0];
    items[0] = items[N-1];
    items[N-1] = temp;

    for (int i = 0; i < N; i++) {
        printf("%d", items[i]);
        if (i != N - 1) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}
