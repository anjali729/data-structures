#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *prevlink;
    struct node *nextlink;
}node;
struct node*start=NULL;
void createlist(int n){
    node *temp=NULL,*ptr=NULL;
    int a,i;
        printf("\nEnter 1 element of list : ");
        scanf("%d",&a);
        temp=malloc(sizeof(node));
        if(temp==NULL){
            printf("Memory not allocated");
            exit(0);
        }
        else{
            temp->data=a;
            temp->nextlink=NULL;
            temp->prevlink=NULL;
            start=temp;
            ptr=start;
        }
        for(i=2;i<=n;i++){
        printf("\nEnter %d element of list : ",i);
        scanf("%d",&a);
        temp=malloc(sizeof(node));
            if(temp==NULL){
                printf("\nMemory not allocated");
                exit(0);
            }
            else{
                temp->data=a;
                ptr->nextlink=temp;
                temp->prevlink=ptr;
                temp->nextlink=NULL;
                ptr=ptr->nextlink;
            }
        }
    }
void displaylist(){
     if(start==0){
        printf("\nList does not exist");
    }
    else{
    node*ptr=start;
    printf("\nElements of list is : ");
    while(ptr!=NULL){
        printf("%d\t",ptr->data);
        ptr=ptr->nextlink;
    }
    }
}
int searchlist(int a){
    int loc=1;
    node *ptr=start;
    if(start==0){
        printf("\nList does not exist");
        return 0;
    }
    else{
        while(ptr!=0){
            if(ptr->data==a){
               return loc;
            }  
            else{
            ptr=ptr->nextlink;
            loc++;
            }
        }
        printf("\nElement not found");
        return 0;
    }    
}
void insertbeg(int a){
    if(start==0){
        printf("\nList does not exist");
    }
    else{
    node*temp=0;
    temp=malloc(sizeof(node));
        if(temp==NULL){
            printf("\nMemory not allocated");
            exit(0);
        }
        else{    
            temp->data=a;
            temp->prevlink=NULL;
            temp->nextlink=start;
            start->prevlink=temp;
            start=temp;
        }
    }
}
void insertend(int a){
    node*ptr=start;
     if(start==0){
        printf("\nList does not exist");
    }
    else{
    node*temp=0;
    temp=malloc(sizeof(node));
        if(temp==NULL){
            printf("\nMemory not allocated");
            exit(0);
        }
        else{ 
            while(ptr->nextlink!=0){   
                  ptr=ptr->nextlink;
                }
            temp->data=a;
            temp->nextlink=NULL;
            ptr->nextlink=temp;
            temp->prevlink=ptr;
        }
    }
}
void insertmid(int a,int l){
    node *ptr=start;
    int i=1;
    if(start==0){
        printf("\nList does not exist");
    }
    else{
    node*temp=0;
    temp=malloc(sizeof(node));
        if(temp==NULL){
            printf("\nMemory not allocated");
            exit(0);
        }
        else{
            while(i<l-1){
                 ptr=ptr->nextlink;
                 i++;
            }
            temp->data=a;
            temp->nextlink=ptr->nextlink;
            ptr->nextlink->prevlink=temp;
            temp->prevlink=ptr;
            ptr->nextlink=temp;
        }
    }
}
int deletebeg(){
     node*temp=start;
     int v;
     if(start==0){
        return 0;
    }
    else if(start->nextlink!=NULL){
        start->nextlink->prevlink=NULL;
        start=start->nextlink;
        v=temp->data;
        free(temp);
    }
    else{
        v=temp->data;
        free(temp);
        start=NULL;
    }
    return v;
}
int deleteend(){
    node*ptr=start,*temp=NULL;
     int v;
     if(start==0){
       return 0;
    }
    else if(start->nextlink!=NULL){
        while(ptr->nextlink->nextlink!=NULL){
            ptr=ptr->nextlink;
        }
        temp=ptr->nextlink;
        ptr->nextlink=NULL;
        v=temp->data;
        free(temp);
    }
    else{
        v=temp->data;
        free(temp);
        start=NULL;
    }
    return v;
}
int deletemid(int l){
    node*ptr=start,*temp=NULL;
     int v,i=1;
     if(start==0){
       return 0;
    }
    else if(start->nextlink!=NULL){
        while(i<l-1){
            ptr=ptr->nextlink;
            i++;
        }
        temp=ptr->nextlink;
        ptr->nextlink=temp->nextlink;
        temp->nextlink->prevlink=temp->prevlink;
        v=temp->data;
        free(temp);
    }
    else{
        v=temp->data;
        free(temp);
        start=NULL;
    }
    return v;
}
void sortlist(){
    node*ptr1=start;
    node*ptr2=ptr1->nextlink;
    int temp;
    if(start!=NULL){
    while(ptr1->nextlink!=0){
        while(ptr2!=0){
          if(ptr1->data>ptr2->data){
            temp=ptr1->data;
            ptr1->data=ptr2->data;
            ptr2->data=temp;
            }
        ptr2=ptr2->nextlink;
        }
        ptr1=ptr1->nextlink;
        ptr2=ptr1->nextlink;
    }
    }
    else{
        printf("\nList does not exist");
    }
}
int main(){
    int choice=1,ch,a,l,c,n,loc,v;
    while(choice!=0){
        printf("\nEnter 1 to create : ");
        printf("\nEnter 2 to display : ");
        printf("\nEnter 3 to insert : ");
        printf("\nEnter 4 to delete : ");
        printf("\nEnter 5 to search : ");
        printf("\nEnter 6 to sort : ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            printf("\nEnter the number of elements in the list : ");
            scanf("%d",&n);
            createlist(n);
            break;
            case 2:
            displaylist();
            break;
            case 3:
            printf("\nEnter the element to insert : ");
            scanf("%d",&a);
            printf("\nEnter 1 to insert in beg : ");
            printf("\nEnter 2 to insert in end : ");
            printf("\nEnter 3 to insert at the location : ");
            scanf("%d",&c);
            switch(c){
                case 1:
                insertbeg(a);
                displaylist();
                break;
                case 2:
                insertend(a);
                displaylist();
                break;
                case 3:
                printf("\nEnter the location to insert element : ");
                scanf("%d",&l);
                insertmid(a,l);
                 displaylist();
                break;
                default:
                printf("\nEnter valid choice.");
                break;
            }
            break;
            case 4:
            printf("\nEnter 1 to delete from beg : ");
            printf("\nEnter 2 to delete from end : ");
            printf("\nEnter 3 to delete from the location : ");
            scanf("%d",&c);
            switch(c){
                case 1:
                v=deletebeg();
                if(v!=0)
                printf("Deleted value is %d : ",v);
                else
                printf("\nList does not exist");
                 displaylist();
                break;
                case 2:
                v=deleteend();
                if(v!=0)
                printf("Deleted value is %d : ",v);
                else
                printf("\nList does not exist");
                 displaylist();
                break;
                case 3:
                printf("\nEnter the location to delete element : ");
                scanf("%d",&l);
                v=deletemid(l);
                if(v!=0)
                printf("Deleted value is %d : ",v);
                else
                printf("\nList does not exist");
                 displaylist();
                break;
                default:
                printf("\nEnter valid choice");
                break;
            }
            break;
            case 5:
            printf("\nEnter the element to search : ");
            scanf("%d",&a);
            loc=searchlist(a);
            if(loc!=0)
            printf("\nElement found at location %d",loc);
            break;
            case 6:
            sortlist();
             displaylist();
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
