#include<stdio.h>
#include<stdlib.h>
struct node{
      int coff;
      int exp;
      struct node *link;
};
struct node* create(){
    int d,i=0;
    struct node*start=NULL;
    struct node*temp=NULL;
    printf("\nEnter highest degree of polynomial : ");
    scanf("%d",&d);
    printf("\nEnter each term with coff and exp : ");
    while(i<=d){
        struct node* node=NULL;
        node=malloc(sizeof(struct node));
        if(i==0){
        scanf("\n%d",&node->coff);
        scanf("\n%d",&node->exp);
        node->link=NULL;
        start=node;
        temp=node;
        }
        else{
        scanf("%d",&node->coff);
        scanf("%d",&node->exp);
        node->link=NULL;
        temp->link=node;
        temp=temp->link;
        }
        i++;
    }
    return start;
}
void display(struct node*ptr){
    if(ptr==NULL)
    printf("No polynomial exist");
    else{
    struct node*temp=ptr;
    printf("(%dX^%d)",temp->coff,temp->exp);
    temp=temp->link;
    while(temp!=NULL){
        printf("(+ %dX^%d)",temp->coff,temp->exp);
        temp=temp->link;
    }
    }
}
void add(struct node*ptr1,struct node*ptr2){
        struct node*temp1=ptr1,*temp2=ptr2,*temp=NULL,*ptr3=NULL,*start=NULL;
        temp=malloc(sizeof(struct node));
        temp->coff=temp1->coff+temp2->coff;
        temp->link=NULL;
        temp->exp=temp1->exp;
        ptr3=temp;
        start=temp;
        temp1=temp1->link;
        temp2=temp2->link;
        while(temp1!=0&&temp2!=0){
              temp=malloc(sizeof(struct node));
              temp->coff=temp1->coff+temp2->coff;
              temp->exp=temp1->exp;
              temp->link=NULL;
              ptr3->link=temp;
              ptr3=ptr3->link;
              temp1=temp1->link;
              temp2=temp2->link;
        }
        printf("sum of two polynomial is : \n");
        display(start);
}
int main(){
    struct node*ptr1=NULL,*ptr2=NULL,*ptr3=NULL;
    int choice=1,ch;
    while(choice==1){
        printf("\nEnter 1 to create");
        printf("\nEnter 2 to display");
        printf("\nEnter 3 to add two polynomial");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            printf("\nEnter a polynomial");
            ptr1=create();
            break;
            case 2:
            display(ptr1);
            break;
            case 3:
            printf("Enter first polynomial : ");
            ptr1=create();
            printf("\nEnter second polynomial");
            ptr2=create();
            add(ptr1,ptr2);
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