#include <stdio.h>

int main() {
    float a,b;
    
    scanf("%f",&a);
    scanf("%f",&b);

    float result = a*b;
    int c=result;
    if((result-(int)result)>=0.5){
        c = (int)result+1;
    }
    printf("%d",c);
    return 0 ;
}