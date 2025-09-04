#include <stdio.h>

int main(){
    int num;
    scanf("%d",&num);

    switch (num)
    {
    case 1:
        printf("You chose Option %d\n",num);
        break;
    case 2:
        printf("You chose Option %d\n",num);
        break;
    case 3:
        printf("You chose Option %d\n",num);
        break;
    
    default:
        printf("Invalid choice\n");
        break;
    }
    return 0;
}