#include <stdio.h>
int main(){
    int i ;
    int arr[10];
    int freq[101]={0};
    int count = 0;
    int num;

    for(i=0;i<10;i++){
        scanf("%d",&num);
        if(num>=0 && num<=100){
            arr[count]=num;
            freq[num]++;
            count++;
        }
    }
    printf("Input array elements :\n");
    for(i=0;i<=100;i++){
        if(freq[i]>0){
            printf("Values %d\t\tFrequency %d time(s)\n",i,freq[i]);
        }
    }

    return 0;
}