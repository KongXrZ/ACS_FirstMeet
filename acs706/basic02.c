#include <stdio.h>
int main(){
    float price;
    int value;
    int money;
    float receipt;

    scanf("%f",&price);
    scanf("%d",&value);
    scanf("%d",&money);

    receipt = money -(price * value);
    printf("%.2f",receipt);
    return 0;

}