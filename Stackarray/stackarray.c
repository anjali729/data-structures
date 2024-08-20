#include<stdio.h>
#include<stdbool.h>
#define size 1000
int arr[size],tos=-1;
void push(int);
int pop();
int peek();
void stackshow();
void stackshow(){
    int top=tos;
    if(top==-1){
        printf("\nStack is empty");
    }
    else{
        while(top!=-1){
            printf("%d\t",arr[top]);
            top--;
        }
    }
}
void push(int a){
     if(tos==size-1){
        printf("stack overflow");
     }
     else{
    tos++;
    arr[tos]=a;
    }
}
int pop(){
    if(tos==-1){
        printf("Stack underflow");
        return -1;
    }
    else{
    int v=arr[tos];
    tos--;
    return v;
    }
}
int peek(){
    if(tos==-1){
        printf("Stack is empty");
        return -1;
    }
    else
       return arr[tos];    
}
bool is_full(){
    if(tos==size-1){
        return true;
    }
    else{
        return false;
    }
}
bool is_empty(){
    if(tos==-1){
        return true;
    }
    else{
    return false;
    }
}
int main(){
    int choice,a,v,c=1;
    bool b;
    while(c!=0){
    printf("\nEnter 1 to push : ");
    printf("\nEnter 2 to pop : ");
    printf("\nEnter 3 to peek : ");
    printf("\nEnter 4 to display : ");
    printf("\nEnter 5 to check if stack is full : ");
    printf("\nEnter 6 to check if stack is empty : ");
    scanf("%d",&choice);
    switch(choice){
        case 1:
        printf("Enter the element to be pushed : ");
        scanf("%d",&a);
        push(a);
        break;
        case 2:
        v=pop();
        if(v!=-1)
        printf("Popped element is : %d",v);
        break;
        case 3:
        v=peek();
        if(v!=-1)
        printf("Element at the top is : %d",v);
        break;
        case 4:
        stackshow();
        break;
        case 5:
        b=is_full();
        if(b==true)
        printf("\nStack is full");
        else
        printf("\nStack is not full");
        break;
        case 6:
        b=is_empty();
        if(b==true)
        printf("\nStack is empty");
        else
        printf("\nStack is not empty");
        break;
        default:
        printf("Enter valid choice");
        break;
    }
    printf("\n");
    printf("Enter 1 to continue or 0 to exit : ");
    scanf("%d",&c);
    }
    return 0;
}