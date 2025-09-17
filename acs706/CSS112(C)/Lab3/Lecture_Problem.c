#include <stdio.h>
int CalAge(int d1, int m1, int y1, int d2, int m2, int y2){
    if(m2>m1){     
        return y2-y1;
    }
    else if(m2 == m1){
        if(d2>d1){
            return y2-y1;
        } 
        else if (d1 == d2){
            return y2-y1;
        }
    }
    else{
        return (y2-y1)-1;
    }
}

int main(){
    int age = CalAge(01,05,2000,01,05,2020);
    printf("%d",age);
    return 0;
}