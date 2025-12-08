#include <stdio.h>
int main(){
    int x = 42;
    float y = 3.14;
    char z = 'A';

    int *p1 = &x;
    float *p2 = &y;
    char *p3 = &z;

    printf("Example (addresses vary):\nint: %d at %p\nfloat: %.2f at %p\nchar: %c at %p", x, (void*)p1, y, (void*)p2, z, (void*)p3);
    return 0;

}