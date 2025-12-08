#include <stdio.h>
struct Student
{
    char name[50];
    int age;
    float gpa;
};

int main(){
    struct Student s;
    FILE *fp = fopen("sample.txt","r");

    if (fp==NULL) return 1;

    printf("Read using fscanf (name age gpa):\n\n");

    while(fscanf(fp, "%s %d %f", s.name, &s.age, &s.gpa) == 3){
        printf("Name=%s Age=%d GPA=%.2f\n", s.name, s.age, s.gpa);
    }

    fclose(fp);
    return 0;
        
}