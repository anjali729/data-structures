#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *link;
};
struct node*front=NULL;
struct node*rear=NULL;
void enqueue(int a){
    struct node *node;
    node=malloc(sizeof(struct node));
    if(front==0&&rear==0){
       front=node;
       rear=node;
       node->data=a;
       node->link=0;
    }
    else{
        rear->link=node;
        rear=node;
        node->data=a;
        node->link=0;
    }
}
int dequeue(){
    int v;
    struct node*temp=front;
    if(temp!=0){
    v=temp->data;
    front=front->link;
    free(temp);
    return v;
    }
    else
    return -1;
}
void display(){
    struct node*temp=front;
    printf("Elements of queue : ");
    while(temp!=0){
        printf("%d\t",temp->data);
        temp=temp->link;
    }

}
int value_at_front(){
    if(front!=0)
    return front->data;
    else{
    return -1;
    }
}
int value_at_rear(){
    if(rear!=0)
    return rear->data;
    else
    return -1;
}
bool is_empty(){
    if(front!=0)
    return 0;
    else
    return 1;
    
}
int main(){
    int choice=1,ch,a,v;
    bool b;
    while(choice!=0){
        printf("\nEnter 1 to insert : ");
        printf("\nEnter 2 to delete : ");
        printf("\nEnter 3 to display : ");
        printf("\nEnter 4 to return value at front : ");
        printf("\nEnter 5 to return value at rear : ");
        printf("\nEnter 6 to check if queue is empty : ");
        scanf("%d",&ch);
        switch(ch){
        case 1:
        printf("\nEnter the value to be inserted : ");
        scanf("%d",&a);
        enqueue(a);
        break;
        case 2:
        v=dequeue();
        if(v==-1){
           printf("Queue is empty");
        }
        else
           printf("Deleted element is : %d ",v);
        break;
        case 3:
        display();
        break;
        case 4:
        v=value_at_front();
        if(v==-1){
            printf("Queue is empty");
        }
        else{
            printf("Value at the front is : %d",v);
        }
        break;
        case 5:
        v=value_at_rear();
        if(v==-1){
            printf("Queue is empty");
        }
        else{
            printf("Value at the rear is : %d",v);
        }
        break;
        case 6:
        b=is_empty();
        if(b==1){
            printf("\nQueue is empty");
        }
        else{
            printf("\nQueue is not empty");
        }
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