#include <stdio.h>
int main (){
    int i,n=0;
    int o_count=0,e_count=0 ;
    int o_numbers[100],e_numbers[100] ;
    int arr[100];
    for(i=0;i>=0;i++){
        scanf("%d",&arr[i]);
        if(arr[i]==0){
            break;
        }
        n++;
    }
    for (i = 0; i < n; i++){
        if(arr[i]%2!=0){
            o_numbers[o_count]=arr[i];
            o_count++;
        }
        else{
            e_numbers[e_count]=arr[i];
            e_count++;
        }
    }
    printf("Odd numbers: ");
    for(i=0;i<o_count;i++){
        printf("%d ",o_numbers[i]);
    }
    printf("\nCount of odd: %d\n",o_count);
    
    printf("Even numbers: ");
    for(i=0;i<e_count;i++){
        printf("%d ",e_numbers[i]);
    }
    printf("\nCount of even: %d\n",e_count);
    return 0;
}