#include <stdio.h>
int main(){
    FILE *fp = fopen("sample.txt","r");
    int ch; //ใส่int เพื่อรับค่าEOF

    if (fp==NULL){
        printf("Cannot open file. \n");
        return 1;
    }

    printf("Reading file using fgetc...\n\n");

    while ((ch = fgetc(fp)) != EOF)  //EOF = End of file
    {
        printf("%c",ch);
    }

    fclose(fp);
    return 0;
    
}