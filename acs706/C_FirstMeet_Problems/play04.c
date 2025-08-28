#include <stdio.h>
int main(){
    int i,j ;
    int arr[10];

    for(i=0;i<10;i++){
        scanf("%d",&arr[i]);
    }

    int maxfreq = 0;
    int mode = -1;
    for(i=0;i<10;i++){
        int freq = 0 ;
        for(j=0;j<10;j++){
            if (arr[i]==arr[j]){
                freq++;
            }
        }
        if(freq>maxfreq){
            maxfreq=freq;
            mode=arr[i];
        }
    }
    printf("Mode = ");
    printf("%d ",mode);
    return 0;
}