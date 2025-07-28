#include <stdio.h>

int main(){
    int n;
    int count =1;
    
    scanf("%d",&n);

    while (1)
    {
        if (n /10 !=0)
        {
           n/=10;
           count++;

        }
        else{
            printf("%d",count);
            break;
        }
    }
    return 0;
}