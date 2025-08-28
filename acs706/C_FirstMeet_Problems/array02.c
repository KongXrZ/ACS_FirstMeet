#include <stdio.h>

int main() {
    int N,i;
    scanf("%d", &N);

    int rock[N];
    for(i=0;i<N;i++){
        scanf("%d",&rock[i]);
    }

    int issafe = 1;
    for(i=1;i<N;i++){
        if(rock[i]<rock[i-1]){
            issafe = 0;
            break;
        }
    
    }
    if (issafe)
    {
        printf("safe");
    }else{
        printf("dangerous");
    }
    return 0;

}
