#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node*link;
}node;
node*createlist(int n){
    node*start=0;
    return start;
}
node*displaylist(node*start){
    return start;
}
node*insertbeg(node*start,int a){
     return start;
}
    int main(){
    int choice=1,ch,n,c,l,loc,a;
    node*ptr=0;
    while(choice!=0){
        printf("\nEnter 1 to create");
        printf("\nEnter 2 to display");
        printf("Enter 3 to insert");
        printf("Enter 4 to delete");
        printf("\nEnter 5 to search");
        printf("\nEnter 6 to sort");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            printf("\nEnter the number of elements in the list : ");
            scanf("%d",&n);
            ptr=createlist(n);
            break;
            case 2:
            ptr=displaylist(ptr);
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
                ptr=insertbeg(ptr,a);
                break;
                case 2:
                insertend(ptr,a);
                break;
                case 3:
                printf("\nEnter the location to insert element : ");
                scanf("%d",&l);
                insertmid(ptr,a,l);
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
                ptr=deletebeg(ptr);
                if(ptr==NULL){
                    printf("\nList is empty.");
                }
                break;
                case 2:
                ptr=deleteend(ptr);
                if(ptr==NULL){
                    printf("\nList is empty.");
                }
                break;
                case 3:
                printf("\nEnter the location to delete element : ");
                scanf("%d",&l);
                ptr=deletemid(ptr,l);
                if(ptr==NULL){
                    printf("\nList is empty.");
                }
                break;
                default:
                printf("\nEnter valid choice");
                break;
            }
            break;
            case 5:
            printf("\nEnter the element to search : ");
            scanf("%d",&a);
            loc=searchlist(ptr,a);
            if(loc!=0)
            printf("\nElement found at location %d",loc);
            break;
            case 6:
            sortlist(ptr);
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