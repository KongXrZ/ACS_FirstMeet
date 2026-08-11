#include <stdio.h>
int main() {
    int n; 
    scanf("%d", &n);

    int size = (2 * n) - 1;
    int center = n - 1;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int dx = (i - center < 0) ? -(i - center) : (i - center);
            int dy = (j - center < 0) ? -(j - center) : (j - center);
            
            int path = (dx + dy == n - 1) ? '#' : '.';
            printf("%c", path);
        }
        printf("\n");
    }

    return 0;
}