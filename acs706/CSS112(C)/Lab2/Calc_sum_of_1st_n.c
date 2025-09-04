#include <stdio.h>

int main(){
    int n,i,sum = 0 ;
    scanf("%d",&n);
    if(n>=1){
        for(i=1;i<=n;i++){
            sum += i;
        }
        printf("Sum = %d\n",sum);
    }
    return 0;
}