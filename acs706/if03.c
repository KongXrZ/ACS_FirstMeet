#include <stdio.h>

int main(){
    int temp ;
    scanf("%d",&temp);
    if(temp >= 15 && temp <= 25){
        printf("1");
    }
    else if(temp >= 26 && temp <= 34){
        printf("2");
    }
    else if(temp >= 35 && temp <= 45){
        printf("3");
    }
    else{
        printf("0");
    }
    return 0 ;
}