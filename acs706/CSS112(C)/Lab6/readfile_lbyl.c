#include <stdio.h>
int main(){
    FILE *fp = fopen("sample.txt","r");
    char line[200];

    if (fp == NULL){
        printf("Cannot open file.\n");
        return 1;
    }

    printf("Reading file using fgets():\n\n");

    int n = 0;
    while (fgets(line,sizeof(line), fp) != NULL)
    {
        n++;
        printf("[LINE %d] %s",n,line);
    }

    fclose(fp);
    return 0;
    
}