#include<stdio.h>
#include<stdbool.h>
#define size 5
int arr[size];
int front=-1;
int rear=-1;
void enqueue(int a){
    if(front==-1&&rear==-1){
        front++;
        rear++;
        arr[rear]=a;
    }
    else if(front==0&&rear==size-1||front==rear+1){
        printf("Queue overflow");
    }
    else{
        if(rear==size-1&&front!=0)
            rear=0;
        else
            rear++; 
        arr[rear]=a;   
    }
}
void display(){
    if(front==-1){
        printf("Queue is empty");
    }
    else{
        if(rear>=front){
            for(int i=front;i<=rear;i++){
                printf("%d\t",arr[i]);
            }
        }
        else{
            for (int i = front; i < size; i++)
            printf("%d ", arr[i]);
 
            for (int i = 0; i <= rear; i++)
            printf("%d ", arr[i]);
        }
    }

}
int dequeue(){
    int v;
    if(front==-1&&rear==-1){
        printf("Queue underflow");
    }
    else if(front==rear){
        v=arr[front];
        front=-1;
        rear=-1;
    }
    else if(front==size-1){
        v=arr[front];
        front=0;
    }
    else{
        v=arr[front];
        front++;
    }
    return v;
}
int value_at_front(){
    if(front==-1){
        return -1;
    }
    else{
        return arr[front];
    }
}
int value_at_rear(){
    if(rear==-1)
       return -1;
    else
       return arr[rear];   
}
bool is_empty(){
    if(front==-1)
    return 1;
    else
    return 0;
}
bool is_full(){
    if((rear==size-1&&front==1)||rear==front+1)
    return 1;
    else
    return 0;
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
        printf("\nEnter 7 to check if queue is full : ");
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
        case 7:
        b=is_full();
        if(b==1)
           printf("Queue is full");
        else
           printf("Queue is not full");
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
