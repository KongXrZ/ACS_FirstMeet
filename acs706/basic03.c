#include <stdio.h>
int main(){
    //input
    int secs;
    //for ouput
    int sec;
    int min;
    int hr;
    

    scanf("%d",&secs);
    hr = secs / 3600;
    min = (secs%3600)/60;
    sec = secs%60;

    printf("%d ชั่วโมง %d นาที %d วินาที",hr,min,sec);

}