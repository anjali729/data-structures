#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

void displaylist(struct node *start){
    struct node *temp=start;
    printf("Elements of the list are: ");
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->link;
    }
}

void sortlist(struct node *start){
    struct node *ptr1=start;
    struct node *ptr2=ptr1->link;
    int temp, count=0, i=1;
    
    // Counting the number of nodes
    while(ptr1->link!=NULL){
        count++;
        ptr1=ptr1->link;
    }
    
    // Sorting the list using bubble sort
    ptr1=start;
    while(i<=count){
        while(ptr2!=NULL){
            if(ptr1->data > ptr2->data){
                temp=ptr1->data;
                ptr1->data=ptr2->data;
                ptr2->data=temp;
            }
            ptr1=ptr1->link;
            ptr2=ptr2->link;
        }
        ptr1=start;
        ptr2=ptr1->link;
        i++;
    }
    // Displaying the sorted list
    displaylist(start);
}

void createlist(int n, struct node **start_ptr){
    int a;
    struct node *temp=NULL, *q=NULL;
    
    // Creating the first node
    temp=malloc(sizeof(struct node));
    if(temp==NULL){
        printf("Memory not allocated");
        exit(0);
    }
    printf("Enter 1st element of the list: ");    
    scanf("%d",&a);
    temp->data=a;
    temp->link=NULL;
    *start_ptr=temp;
    q=temp;
    
    // Creating the rest of the nodes
    for(int i=2; i<=n; i++){
        printf("Enter %dth element of the list: ",i);
        temp=malloc(sizeof(struct node));
        if(temp==NULL){
            printf("Memory not allocated");
            exit(0);
        }
        scanf("%d",&a); 
        temp->data=a;
        temp->link=NULL;
        q->link=temp;
        q=q->link;;
    }
}

int deletebeg(struct node **start_ptr){
    struct node *temp=*start_ptr;
    int v;
    if(temp->link!=NULL){
       *start_ptr=temp->link;
       v=temp->data;
       free(temp);
    }
    else{
        v=temp->data;
        free(temp);
        *start_ptr=NULL;
    }
    return v;
}

int deleteend(struct node **start_ptr){
    struct node *temp=*start_ptr;
    struct node *q=NULL;
    int v;
    if(temp->link!=NULL){
        while(temp->link!=NULL){
            q=temp;
            temp=temp->link;
        }
        v=temp->data;
        free(temp);
        q->link=NULL;
    }
    else{
        v=temp->data;
        free(temp);
        *start_ptr=NULL;
    }
    return v;
}

int deletemid(struct node **start_ptr, int a){
    struct node *temp=*start_ptr;
    struct node *q=NULL;
    int v;
    if(temp!=NULL){
        while(temp->data!=a){
            q=temp;
            temp=temp->link;
        }
        q->link=temp->link;
        v=a;
        free(temp);
    } 
    else{
        v=temp->data;
        if(v==a){
            free(temp);
            *start_ptr=NULL;
        }
        else{
            printf("\nElement doesn't exist");
        }
    }   
    return v;
}

void insertbeg(struct node **start_ptr, int a){
    struct node *temp=NULL;
    temp=malloc(sizeof(struct node));
    if(temp!=NULL){
        temp->data=a;
        temp->link=*start_ptr;
        *start_ptr=temp;
    }
    else{
        printf("Memory not allocated\n");
        exit(0);
    }
}

void insertend(struct node **start_ptr, int a){
    struct node *temp=NULL, *q=NULL;
    q=*start_ptr;
    temp=malloc(sizeof(struct node));
    if(temp!=NULL){
        while(q->link!=NULL){
            q=q->link;
        }
        temp->data=a;
        temp->link=NULL;
        q->link=temp;
    }
    else{
        printf("Memory not allocated\n");
        exit(0);
    }
}

void insertmid(struct node **start_ptr, int a, int l){
    struct node *temp=NULL;
    struct node *q=*start_ptr;
    int i=1;
    temp=malloc(sizeof(struct node));
    if(temp!=NULL){
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

int searchnode(struct node *start, int a){
    struct node *ptr=start;
    int count=1;
    while(ptr!=NULL && ptr->data!=a){
        ptr=ptr->link;
        count++;
    }
    if(ptr==NULL){
        return 0;
    }
    else{
        return count;
    }    
}

int main(){
    int ch=1,c,i1,i2,l,a,v;
    int n;
    struct node *ptr=NULL;
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
                createlist(n, &ptr);
                break;
            case 2:
                if(ptr!=NULL){
                    displaylist(ptr);
                    printf("\n");
                }
                else{
                    printf("List doesn't exist\n");
                }
                break;
            case 3:
                printf("Enter 1 to insert at beginning :\n");
                printf("Enter 2 to insert at end : \n");
                printf("Enter 3 to insert at a location : \n");
                scanf("%d",&i1);
                printf("Enter the element : ");
                scanf("%d",&a);
                switch(i1){
                    case 1:
                        if(ptr!=NULL){
                            insertbeg(&ptr, a);
                            n++;
                        }
                        else{
                            printf("List is empty\n");
                        }
                        break;
                    case 2:
                        if(ptr!=NULL){
                            insertend(&ptr, a);
                            n++;
                        }
                        else{
                            printf("List is empty\n");
                        }
                        break;
                    case 3:
                        if(ptr!=NULL){
                            printf("Enter the location at which you want to insert : ");
                            scanf("%d",&l);
                            insertmid(&ptr, a, l);
                            n++;
                        }
                        else{
                            printf("List is empty\n");
                        }
                        break;
                    default:
                        printf("Enter valid choice");
                        break;
                }
                break;
            case 4:
                printf("Enter 1 to delete from beginning : \n");
                printf("Enter 2 to delete from end : \n");
                printf("Enter 3 to delete from mid : \n");
                scanf("%d",&i1);
                switch(i1){
                    case 1:
                        if(ptr!=NULL){
                            v=deletebeg(&ptr);
                            printf("Deleted element is : %d",v);
                            n--;
                        }
                        else{
                            printf("List is empty\n");
                        }
                        break;
                    case 2:
                        if(ptr!=NULL){
                            v=deleteend(&ptr);
                            printf("Deleted element is : %d",v);
                            n--;
                        }
                        else{
                            printf("List is empty\n");
                        }
                        break;
                    case 3:
                        if(ptr!=NULL){
                            printf("Enter the element you want to delete : ");
                            scanf("%d",&a);
                            deletemid(&ptr, a);
                            printf("Deleted element is : %d",a);
                            n--;
                        }
                        else{
                            printf("List is empty\n");
                        }
                        break;
                }
                break;
            case 5:
                printf("Enter the element you want to search : ");
                scanf("%d",&a);
                if(ptr==NULL)
                    printf("List doesn't exist");
                else{
                    v=searchnode(ptr, a);
                    if(v==0){
                        printf("Element not found in the list");
                    }
                    else{
                        printf("Element found at location %d",v);
                    }
                }
                break;
            case 6:
                if(ptr==NULL)
                    printf("List doesn't exist");
                else
                    sortlist(ptr);
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