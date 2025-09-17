#include <stdio.h>
int main(){
    char text[101];
    scanf("%100s",text);
    int i , j=1, len = 0;
    int isPalindrome = 1;
    while(text[len] != '\0') // วนนับจำนวนตัวอักษร  ถ้าไม่ใช้strlen
    {
        len++;
    }

    for (i=0; i<len ;i++) //วนลูป len รอบ
    {
        if(text[i] != text[len-1-i]) //ใส่-1เพื่อให้ค่าติดลบในindexที่0
        {
            isPalindrome = 0;
            break;
        }
    }
    if (isPalindrome){ //เช็คค่าสุดท้ายของ isPalindrome
        printf("Palindrome");
    }
    else {
        printf("Not palindrome");
    }
    return 0;
}