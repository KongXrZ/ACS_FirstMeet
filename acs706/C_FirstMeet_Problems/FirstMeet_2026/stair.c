#include <stdio.h>
int main() {
    int n=10;
    //scanf("s%d", &n);

    int max_width = 0;
    int digits = 0;
    for (int x = n; x > 0; x /= 10) {
        digits++;
    }
    max_width = n * digits;

    for (int i = 1; i <= n; i++) {
        digits = 0;
        for (int x = i; x > 0; x /= 10) {
            digits++;
        }

        int width = i * digits;
        for (int j = 0; j < max_width - width; j++) {
            putchar(' ');
        }
        for (int j = 0; j < i; j++) {
            printf("%d", i);
        }
        printf("\n");
    }

    return 0;
}