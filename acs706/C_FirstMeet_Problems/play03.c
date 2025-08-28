#include <stdio.h>
int main(){
    int bit[8];
    int value[8]={128, 64, 32, 16, 8, 4, 2, 1};
    int sum = 0;
    int i;

    for(i=0;i<8;i++){
        scanf("%d",&bit[i]);
    }
    for(i=0;i<8;i++){
        sum += bit[i]*value[i];
    }
    printf("%d",sum);
    return 0 ;
}
