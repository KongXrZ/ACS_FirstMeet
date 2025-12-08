#include <stdio.h>
struct Student
{
    int id;
    float gpa;
};
int main(){
    struct Student s1;
    struct Student *p; //pointer ชี้ไป struct Student
    
    s1.id = 1001;
    s1.gpa = 3.50;

    p=&s1;

    //เข้าถึงสมาชิก struct ผ่าน pointer
    (*p).id = 2002; //แบบเต็ม
    p->gpa = 3.85; //แบบย่อ

    printf("s1.id = %d\n",s1.id);
    printf("s1.gpa = %d\n",s1.gpa);

    return 0;
}
