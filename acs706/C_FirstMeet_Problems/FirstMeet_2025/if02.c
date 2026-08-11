#include <stdio.h>

int main(){
    int byears ;
    scanf("%d",&byears);

    if(2025-byears>=18){
        printf("1");
    }
    else{
        printf("0");
    }
    return 0 ;
}