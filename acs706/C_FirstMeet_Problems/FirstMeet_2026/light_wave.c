#include <stdio.h>

int main() {
    int h, r;
    scanf("%d %d", &h, &r);
    
    for (int w = 1; w <= r; w++) {
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= i; j++) {
                printf("%d", i);
            }
            printf("\n");
        }
        
        for (int i = h - 1; i >= 1; i--) {
            for (int j = 1; j <= i; j++) {
                printf("%d", i);
            }
            printf("\n");
        }

        if (w < r) {
            printf("\n");
        }
    }
    
    return 0;
}