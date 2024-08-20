#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node{
    int data;
    struct node *link;
};
 struct node  *tos=NULL;
 void push(int a){
    struct node*temp=0;
    temp=malloc(sizeof(struct node));
    temp->data=a;
    temp->link=tos;
    tos=temp;
}
 int pop(){
    if(tos==NULL){
        printf("stack underflow");
        return 0;
    }
    else{
    struct node *temp=tos;
    int v=temp->data;
    tos=temp->link;
    free(temp);
    return v;
    }
}
int peep(){
     if(tos==NULL){
        printf("stack is empty");
        return 0;
    }
    else{
    struct node *temp=tos;
    return temp->data;
    }
}
bool is_empty( ){
    if(tos==NULL)
    return true;
    else 
    return false;
}
void display(){
    if(tos==NULL){
        printf("stack is empty");
    }
    else{
    struct node *ptr=tos;
    while(ptr!=0){
        printf("%d\t",ptr->data);
        ptr=ptr->link;
    }
    }
}
int main(){
    int a,choice=1,c,v;
    bool f;
    while(choice!=0){
        printf("\nEnter 1 to push : ");
        printf("\nEnter 2 to pop : ");
        printf("\nEnter 3 to peep : ");
        printf("\nEnter 4 to display : ");
        printf("\nEnter 5 to check whether stack is empty : ");
        scanf("%d",&c);
        switch(c){
            case 1:
            printf("\nEnter the element : ");
            scanf("%d",&a);
            push(a);
            printf("Element is pushed");
            break;
            case 2:
            v=pop();
            if(v!=0)
            printf("\npopped element is : %d",v);
            break;
            case 3:
            v=peep();
            if(v!=0)
            printf("\nelement at the top is : %d",v);
            break;
            case 4:
            display();
            break;
            case 5:
            f=is_empty();
            if(f==true)
            printf("\nStack is empty");
            else
            printf("\nStack is not empty");
            break;
            default:
            printf("\nEnter valid choice");
            break;
        }
        printf("\nEnter 1 to continue or 0 to exit : ");
        scanf("%d",&choice);
    }
    return 0;
}