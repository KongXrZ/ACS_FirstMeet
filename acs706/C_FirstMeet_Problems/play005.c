#include <stdio.h>
int main(){
    int i,m,j,n=0 ;
    int arr[10];
    scanf("%d",&m);
    if(m>=1&&m<=10){
        n=m;
    }
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    
    for(i=0;i<n;i++){
        int x = arr[i];
        int isprime=1;

        if(x<2){
            isprime = 0;
        } else if (x==2)
        {
            isprime = 1;
        } else if (x%2 ==0)
        {
            isprime =0;
        }else{
            for(j=3;j*j<=x;j+=2){
                if (x % j == 0 ){
                    isprime = 0;
                    break;
                }
            }
        }
        if(isprime || x%2 != 0){
            printf("T\n");
        }
        else{
            printf("F\n");
        }
    }


    return 0;
}