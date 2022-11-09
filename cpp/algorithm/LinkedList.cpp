#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char id[10];
    char name[13];
    char clazz[13];
    float score;
} Stu;

typedef struct Node{
    Stu stu;
    struct Node *next;
}ND;

ND* head = NULL;

int Insert(){
    char id[10],name[13],clazz[13];
    ND* tmp = head;
    ND* newNode = (ND*) malloc(sizeof(ND));
    if(newNode == NULL) return 0;
    printf("依次输入'学号 姓名 班级 入学分数'\n");
    scanf("%s%s%s%f",id,name,clazz,&newNode->stu.score);
    newNode->next = NULL;
    strcpy(newNode->stu.id,id);
    strcpy(newNode->stu.name,name);
    strcpy(newNode->stu.clazz,clazz);
    if(head == NULL){
        head = newNode;
        return 1;    
    }
    while(tmp->next != NULL){
        if(strcmp(tmp->stu.id,id) == 0) return 0;   //过滤重复学号
        tmp = tmp ->next;
    }
    tmp->next = newNode;
    return 1;
}

void Print(){
    int i = 1;
    ND* tmp = head;
    while(tmp != NULL)
    {
        printf("%d\t%s\t%s\t%s\t%.2f\n",i,tmp->stu.id,tmp->stu.name,tmp->stu.clazz,tmp->stu.score);
        ++ i;
        tmp = tmp->next;
    }
}

ND* Get(char* id){
    ND* tmp = head;
    while( strcmp(tmp->stu.id,id) != 0 && tmp != NULL)
        tmp = tmp->next;
    return tmp;
}

int Delete(char* id){
    ND* tmp = head,*q;
    if(head == NULL) return 0;
    else if(head->next == NULL)
        head = NULL;
    else{
        while(strcmp(tmp->next->stu.id,id) != 0 && tmp->next != NULL)
            tmp = tmp->next;
        q = tmp->next;
        tmp->next = q->next;
        free(q);
    }
    return 1;
}

void Free(){
    ND* p = head;
    while(head != NULL){
        p = head;
        head = head->next;
        free(p);
    }
}

int main(void){
    Insert();
    Insert();
    Delete("22");
    Print();
    Free();
    return 0;
}