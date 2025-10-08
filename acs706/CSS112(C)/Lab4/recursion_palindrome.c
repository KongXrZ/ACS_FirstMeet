#include <stdio.h>
#include <string.h>
int find_palindrome(char word[], int start, int end){
    if(start >= end){
        return 1;
    }
    if(word[start] != word[end]){
        return 0;
    }

    return find_palindrome(word, start+1, end-1);
}

int main(){
    char text[101];
    scanf("%100s",&text);

    int len = strlen(text);

    if(find_palindrome(text,0,len-1)){
        printf("Palindrome\n");
    }
    else{
        printf("Not Palindrome\n");
    }
    return 0;
}