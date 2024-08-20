#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
 struct node{
       int data;
       struct node *link;
    };

    struct node*start=NULL;
    void displaylist(){
        struct node *temp=NULL;

        temp=start;
        printf("\nElements of the list is : ");
        while(temp!=NULL){
           printf("%d\t",temp->data);
           temp=temp->link;
        }
    }

   void sortlist(){
        struct node*ptr1=start;
        struct node*ptr2=ptr1->link;
        int temp;
        while(ptr1->link!=NULL){
            while(ptr2->link!=NULL){
                if(ptr1->data>ptr2->data){
                temp=ptr1->data;
                ptr1->data=ptr2->data;
                ptr2->data=temp;
                }
            ptr2=ptr2->link;
            }
        ptr1=ptr1->link;
        ptr2=ptr1->link;
        }
        displaylist();
    }

void createlist(int n){
    int a;
   struct node*q=NULL;
   struct node *temp=NULL;

    temp=malloc(sizeof(struct node));
    if(temp==NULL){
        printf("Memory not allocated");
        exit(0);
    }
   printf("Enter 1 element of list : ");    
   scanf("%d",&a);
    temp->data=a;
    temp->link=NULL;
    start=temp;
    q=temp;
    for(int i=2;i<=n;i++){
           printf("Enter %d element of list : ",i);
           temp=malloc(sizeof(struct node));
              if(temp==NULL){
                printf("Memory not allocated");
                exit(0);
               }
                scanf("%d",&a); 
                temp->data=a;
                temp->link=NULL;
                q->link=temp;
                q=temp;
            }
}

int deletebeg(){
    struct node *temp=start;
    int v;
    if(temp->link!=0){
       v=temp->data;
       start=temp->link;
       free(temp);
       temp=NULL;
    }
    else{
        v=temp->data;
        free(temp);
        start=NULL;
    }
   return v;
}
int deleteend(){
    struct node *temp=start;
    struct node *q=NULL;
    int v;
    if(start->link!=NULL){
    while(temp->link!=NULL){
         q=temp;
         temp=temp->link;
        }
        v=temp->data;
        free(temp);
        q->link=NULL;
        temp=NULL;
    }
    else{
        v=temp->data;
        free(temp);
        start=NULL;
    }
    return v;
}
int deletemid(int a){
    struct node *temp=start;
    struct node *q=start;
    int v;
    if(start->link!=NULL){
    while(temp!=NULL){
        q=temp;
        temp=temp->link;
        if(temp->data==a){
            v=temp->data;
            q->link=temp->link;
            free(temp);
            temp=NULL;
            break;
        }
        else if(temp->link==NULL&&temp->data!=a){
           return 0;
        }
    }
    } 
    else{
        if(temp->data==a){
           v=temp->data;
           free(temp);
           start=NULL;
        }
    }
    return v;
   
}
void insertbeg(int a){
    struct node *temp=0;
    temp=malloc(sizeof(struct node));
    if(temp!=0){
    temp->data=a;
    temp->link=start;
    start=temp;
    }
    else{
        printf("Memory not allocated\n");
        exit(0);
    }
}
void insertend(int a){
    struct node *temp=NULL,*q=NULL;
    q=start;
    temp=malloc(sizeof(struct node));
    if(temp!=0){
    while(q->link!=0){
        q=q->link;
    }
    temp->data=a;
    temp->link=0;
    q->link=temp;
    }
    else{
        printf("Memory not allocated\n");
        exit(0);
    }
}
void insertmid(int a,int l){
    struct node *temp=0;
    struct node*q=start;
    int i=1;
    temp=malloc(sizeof(struct node));
    if(temp!=0){
    while(i<l-1){
        q=q->link;
        i++;
    }
    temp->data=a;
    temp->link=q->link;
    q->link=temp;
    }
    else{
        printf("Memory not allocated\n");
        exit(0);
    }
}
int searchnode(int a){
    struct node *ptr=start;
    int count=1;
    while(ptr!=0&&ptr->data!=a){
        ptr=ptr->link;
        count++;
    }
    if(ptr==0){
        return 0;
    }
    else{
        return count;
    }    
}
int main(){
    int ch=1,c,i1,i2,l,a,v;
     int n;
    //struct node*ptr=NULL;
    while(ch!=0){
    printf("Enter 1 to create list : \n");
    printf("Enter 2 to display list : \n");
    printf("Enter 3 to insert : \n");
    printf("Enter 4 to delete : \n");
    printf("Enter 5 to search : \n");
    printf("Enter 6 to sort : \n");
    scanf("%d",&c);
    switch(c){
        case 1:
        printf("Enter the no. of elements in the list : ");
        scanf("%d",&n);
        createlist(n);
        break;
        case 2:
        if(start!=0){
        displaylist();
        printf("\n");
        }
        else{
            printf("List doesn't exist\n");
        }
        break;
        case 3:
        printf("Enter 1 to insert at begining :\n");
        printf("Enter 2 to insert at end : \n");
        printf("Enter 3 to insert at a location : \n");
        scanf("%d",&i1);
        printf("Enter the element : ");
        scanf("%d",&a);
        switch(i1){
            case 1:
            if(start!=0){
            insertbeg(a);
            }
            else{
                printf("List is empty\n");
            }
            displaylist();
            break;
            case 2:
            if(start!=0){
            insertend(a);
            }
            else{
                printf("List is empty\n");
            }
            displaylist();
            break;
            case 3:
            if(start!=0){
            printf("Enter the location at which you want to insert : ");
            scanf("%d",&l);
            insertmid(a,l);
            }
            else{
                printf("List is empty\n");
            }
            displaylist();
            break;
            default:
            printf("Enter valid choice");
            break;
        }
        break;
        case 4:
        printf("Enter 1 to delete from beg : \n");
        printf("Enter 2 to delete from end : \n");
        printf("Enter 3 to delete from mid : \n");
        scanf("%d",&i1);
        switch(i1){
            case 1:
            if(start!=0){
            v=deletebeg();
            printf("Deleted element is : %d",v);
            }
            else{
                printf("List is empty\n");
            }
            displaylist();
            break;
            case 2:
            if(start!=0){
            v=deleteend();
            printf("Deleted element is : %d",v);
            }
            else{
                printf("List is empty\n");
            }
            displaylist();
            break;
            case 3:
            if(start!=NULL){
            printf("Enter the element you want to delete : ");
            scanf("%d",&a);
            v=deletemid(a);
            if(v!=0){
            printf("Deleted element is : %d",v);
            }
            else{
                printf("\nElement does not exist");
            }
            }
            else{
                printf("\nList does not exist");
            }
            displaylist();
            break;
            default:
            printf("\nEnter valid choice");
            break;
        }
        break;
        case 5:
        printf("Enter the element you want to search : ");
        scanf("%d",&a);
        if(start==0)
        printf("List doesn't exist");
        else{
        v=searchnode(a);
        if(v==0){
         printf("Element not found in the list");
        }
        else{
        printf("Element found at location %d",v);
        }
        }
        break;
        case 6:
        if(start==0)
        printf("List doesn't exist");
        else
        sortlist();
        break;
        default:
        printf("Enter valid choice");
        break;
    }
    printf("\n");
    printf("Enter 1 to continue or 0 to exit : ");
    scanf("%d",&ch);
}
return 0;
}
   