#include <stdio.h>

int main(){
    int n,i = 0 ;
    scanf("%d",&n);
    while (n>=1 && n-i != 0)
    {
        printf("%d\n",n-i);
        i++;
    }
    return 0;
}