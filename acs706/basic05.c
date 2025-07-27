#include <stdio.h>

int main(){
    int temp ;
    scanf("%d",&temp);
    if(temp >=15 && temp <=25){
        printf("%s","1 สตรอว์เบอร์รี");
    }
    else if(temp >=26 && temp <=34){
        printf("%s","2 ผักกาด");
    }
    else if(temp >=35 && temp <=45){
        printf("%s","3 ข้าดโพด");
    }
    else{
        printf("%s","4 ไม่เหมาะกับการปลูกพืช");
    }
    return 0 ;
}