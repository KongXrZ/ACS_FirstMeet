#include <stdio.h>
#include <string.h>

struct Student 
{
    char name[30];
    int age;
    float gpa;
};

float findMax(struct Student std_lst[], char *top_name){
    float max_gpa = std_lst[0].gpa;
    strcpy(top_name, std_lst[0].name);
    for(int i=0; i<5; i++){
        if (std_lst[i].gpa > max_gpa){
            max_gpa = std_lst[i].gpa;
            strcpy(top_name, std_lst[i].name);
        }
    }
    return max_gpa;
}

int main(){
    struct Student students[5];
    for(int i=0; i<5; i++){
        scanf("%29s %d %f", students[i].name, &students[i].age, &students[i].gpa);
    }
    
    float gpax = 0;
    for(int j=0; j<5; j++){
        gpax += students[j].gpa;
    }
    printf("เกรดเฉลี่ยรวมคือ %.2f\n",gpax/5);

    char top_name[30];
    float max_gpa = findMax(students, top_name);
    printf("นักเรียนที่มี GPA สูงสุดคือ %s ได้เกรดเฉลี่ย %.2f\n",top_name, max_gpa);
    return 0;
}
