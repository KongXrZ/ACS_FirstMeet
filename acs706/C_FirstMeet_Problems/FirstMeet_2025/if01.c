#include <stdio.h>

int main(){
    int score ;
    scanf("%d",&score);
    if(score >=80){
        printf("%s","A");
    }
    else if(score >=70){
        printf("%s","B");
    }
    else if(score >=60){
        printf("%s","C");
    }
    else if(score >=50){
        printf("%s","D");
    }
    else{
        printf("%s","F");
    }
    return 0 ;
}