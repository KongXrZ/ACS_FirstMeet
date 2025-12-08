#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

//ฟังก์ชั่นสร้างNode
struct Node* createNode(int value){
    struct Node *n = (struct Node*)malloc(sizeof(struct Node));
    (*n).data = value;
    (*n).next = NULL;
    return n;
}

//เพิ่มnode แบบสุดท้าย (Simple Version)
void append(struct Node **head, int value){
    struct Node *newNode = createNode(value);
    if(*head == NULL){
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    while ((*temp).next != NULL){
        temp = (*temp).next;
    }
    (*temp).next = newNode;
}

//แสดงlinked list
void printList(struct Node *head){
    struct Node *t = head;

    while (t != NULL){
        printf("%d - > ",t->data);
        t = t->next;
    }
    printf("NULL\n");
}

int search(struct Node *head, int key){
    struct Node *t = head;

    while (t != NULL){
        if (t->data == key)
            return 1;
        t = t->next;
    }
    return 0;
}

int main(){
    struct Node *head = NULL;

    //สร้างLinked list : 10 -> 20 -> 30
    append(&head,10);
    append(&head,20);
    append(&head,30);

    printf("Linked List: ");
    printList(head);

    int key;
    printf("Enter number to search: ");
    scanf("%d", &key);

    if(search(head, key))
        printf("FOUND %d in the linked list.\n", key);
    else
        printf("NOT FOUND %d in the linked list.\n", key);
    return 0;
}
