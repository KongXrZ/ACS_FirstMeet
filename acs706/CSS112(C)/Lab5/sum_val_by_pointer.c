#include <stdio.h>
int main(){
    int n,sum = 0;
    scanf("%d",&n);
    int arr[n];
    int *ptr=&arr;
    if (n < 1 || n > 100){
        return 1;
    }
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    for(int j=0; j<n;j++){
        sum += *(ptr+j);
    }
    printf("Sum = %d",sum);
    return 0;
}