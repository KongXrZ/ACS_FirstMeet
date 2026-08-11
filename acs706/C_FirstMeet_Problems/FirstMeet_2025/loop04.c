#include <stdio.h>
int main(){
    int N, i;
    int maxN = 0;
    i = 1;
    while(i=1){
        scanf("%d",&N);
        if (N>maxN){
            maxN=N;
        }
        if(N==0){
            printf("The highest weight is: ");
            printf("%d",maxN);
            break;
        }
    }
}