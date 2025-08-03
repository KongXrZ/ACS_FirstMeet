#include <stdio.h>
int main(){
    int i,nmenu,ncup;
    int nmenu[3],ncup[10];
    for (i=0;i>=0;i++){
        scanf("%d",&nmenu[i]);
        
        if (nmenu!=0){
            scanf("%d",&ncup);
            if(ncup==0){
                break;
            }
        }
        else{
            break;
        }
        
        
    }
    return 0;
}