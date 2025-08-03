#include <stdio.h>
int main(){
    int i=0,count=0,menu,cup,cups=0,n=0;
    int nmenu[10],ncup[10];
    while(1){
        scanf("%d",&menu);
        
        if (menu!=0&&menu<=3){
            scanf("%d",&cup);
            if(cup==0){
                break;
            }
        }
        else{
            break;
        }
        nmenu[i]=menu;
        ncup[i]=cup;
        
        i++;
        count++;
    }
    float price=0,total=0,discount=0.0;
    for(i=0;i<count;i++){
        if(nmenu[i]==1){
            price = ncup[i]*25;
        }else if (nmenu[i]==2){
            price = ncup[i]*30;
        }else if (nmenu[i]==3){
            price = ncup[i]*35;
        }
        total=total+price;
        cups+=ncup[i];
    }

    if (total >= 300){
        discount = total*0.05;
    }else if (cups>=10){
        discount = total*0.10;
    }
    total-=discount;
    int intotal = (int)total;
    if (total-intotal>=0.5)
    {
        intotal+=1;
    }
    
    printf("%d",intotal);
    return 0;
}