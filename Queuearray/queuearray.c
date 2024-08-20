#include<stdio.h>
#include<stdbool.h>
#define size 1000
int front=-1;
int rear=-1;
int arr[size];
void display(){
    if(front==-1&&rear==-1){
        printf("\nQueue is empty");
    }
    else{
    printf("\nElements of the queue is : ");
    for(int i=front;i<=rear;i++){
       printf("%d\t",arr[front]);
    }
    }
}
void enqueue(int a){
    if(rear==size-1){
        printf("\nQueue overflow");
    }
    else if(front==-1&&rear==-1){
        front++;
        rear++;
        arr[rear]=a;
    }
    else{
    rear=rear+1;
    arr[rear]=a;
    }
}
int dequeue(){
    if(front==-1||front==rear+1){
        printf("\nQueue underflow");
        return -1;
    }
    else{
    int v=arr[front];
    front=front+1;
    if(front>rear){
        front=-1;
        rear=-1;
    }
    return v;
    }
}
bool is_empty(){
     if(front==-1&&rear==-1){
        return true;
     }
     else{
        return false;
     }
}
bool is_full(){
    if(rear==size-1){
        return true;
    }
    else{
    return false;
    }
}
int value_at_front(){
    if(front==-1){
        printf("\nQueue is empty");
        return -1;
    }
    else{
    return arr[front];
    }
}
int value_at_rear(){
    if(rear==-1){
        printf("Queue is empty");
        return -1;
    }
    else{
    return arr[rear];
    }
}
int main(){
    int choice=1,ch,a;
    int v;
    bool b;
    while(choice!=0){
        printf("\nEnter 1 to insert : ");
        printf("\nEnter 2 to delete : ");
        printf("\nEnter 3 to display queue : ");
        printf("\nEnter 4 to return value at front : ");
        printf("\nEnter 5 to return value at rear : ");
        printf("\nEnter 6 to check if queue is full : ");
        printf("\nEnter 7 to check if queue is empty : ");
        scanf("%d",&ch);
        switch(ch){
        case 1:
        printf("\nEnter the value to be inserted : ");
        scanf("%d",&a);
        enqueue(a);
        break;
        case 2:
        v=dequeue();
        if(v!=-1){
            printf("Deleted element is : %d ",v);
        }
        break;
        case 3:
        display();
        break;
        case 4:
        v=value_at_front();
        if(v!=-1){
            printf("Value at the front is : %d",v);
        }
        break;
        case 5:
        v=value_at_rear();
        if(v!=-1){
            printf("Value at the rear is : %d",v);
        }
        break;
        case 6:
        b=is_full();
        if(b==1){
            printf("\nQueue is full");
        }
        else{
            printf("\nQueue is not full");
        }
        break;
        case 7:
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