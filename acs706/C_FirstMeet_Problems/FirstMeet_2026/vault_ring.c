#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);

    int size = (2 * n) - 1;
    int center = n - 1;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int dx = (i - center < 0) ? -(i - center) : (i - center); //abs ทำมือ
            int dy = (j - center < 0) ? -(j - center) : (j - center);

            int max_dist = (dx > dy) ? dx : dy;
            printf("%d", max_dist + 1);
        }
        printf("\n");
    }

    return 0;
}