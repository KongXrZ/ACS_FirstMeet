#include <stdio.h>
int main(){
    float a ;
    float b ;
    float c ;
    float d ;
    float e ;
    float result ;
    
    scanf("%f",&a);
    scanf("%f",&b);
    scanf("%f",&c);
    scanf("%f",&d);
    scanf("%f",&e);

    result = (a+b+c+d+e) / 5;
    printf("%.2f",result);
}