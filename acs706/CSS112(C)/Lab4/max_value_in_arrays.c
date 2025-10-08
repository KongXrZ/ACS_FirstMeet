#include <stdio.h>

int find_max_value(int arr[],int n){
    if (n==0){
        return arr[0];
    }

    int max_of_rest = find_max_value(arr, n-1);
    return (arr[n] > max_of_rest) ? arr[n] : max_of_rest; //Conditional Operator
}

int main(){
    int i,n;
    scanf("%d",&n);

    if (n<=0){
        return 1;
    }
    
    int max_arr[n];
    for(i=0;i<n;i++){
        scanf("%d",&max_arr[i]);
    }

    int result = find_max_value(max_arr,n-1);
    printf("%d",result);
    return 0;
}