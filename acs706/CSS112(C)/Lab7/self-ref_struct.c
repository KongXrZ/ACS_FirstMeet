#include <stdio.h>

//Self-referncing struct (โครงสร้างที่มี pointer ชี้ไป Struct ชนิดเดียวกัน)
struct Node
{
    int data;
    struct Node *next;
};

int main(){
    struct Node a,b; //สร้าง Node 2 ตัวแบบปกติ
    struct Node *p; //pointer ชี้ไป Node

    a.data = 10;
    b.data = 20;

    //เชื่อมNode a -> b
    a.next = &b;
    b.next = NULL;
    
    p=&a;

    printf("a.data = %d\n", a.data);
    printf("b.data = %d\n", b.data);

    //เข้าถึง b ผ่าน pointer
    printf("p->data = %d\n", p->data);
    printf("p->next->data = %d\n", p->next->data);

    return 0; 
}
