#include <stdio.h>
int main(){
    int n,i;
    scanf("%d",&n);

    int arr[n];
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    int found = 0;
    for(i=0;i<n;i++){
        if (arr[i]%3 == 0 && arr[i]>=0 && arr[i]<=9){
            if(found){
                printf(" ");
            }
            printf("%d",arr[i]);
            found = 1;
        }
    }
    if(!found){
        printf("None");
    }
    return 0 ;
}