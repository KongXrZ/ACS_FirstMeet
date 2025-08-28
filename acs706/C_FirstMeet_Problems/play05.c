#include <stdio.h>
int main(){
    int N,i ;
    int votes[101]={0};
    int arr[100]={};
    
    scanf("%d",&N);
    for (i=0; i<N; i++ ){
        scanf("%d",&arr[i]);
        votes[arr[i]]++;
    }
    

    int maxvotes = 0;
    for(i=0;i<101;i++){
        if (votes[i]>maxvotes){
            maxvotes = votes[i];
        }
    }
    if(maxvotes == 1){
        printf("None\n");
        return 0;
    }

    for(i=0;i<101;i++){
        if(votes[i]==maxvotes){
            printf("%d ",i);
        }
    }
    return 0;
}