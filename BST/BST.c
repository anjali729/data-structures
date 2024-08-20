#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left, *right;
};
struct node* insert(struct node*root,int val){
    struct node*ptr=NULL;
    ptr=malloc(sizeof(struct node));
    if(root==NULL){
    ptr->data=val;
    ptr->left=NULL;
    ptr->right=NULL;
  //  root=ptr;
    return ptr;
    }
    else if(root->data>val){
        root->left=insert(root->left,val);
    }
    else if(root->data<val){
        root->right=insert(root->right,val);
    }
    return root;
}
void inorder(struct node*root){
    if(root!=0){
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}
void preorder(struct node*root){
    if(root!=0){
        printf("%d\t",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node*root){
    if(root!=0){
        postorder(root->left);
        postorder(root->right);
        printf("%d\t",root->data);
    }
}
int main(){
    struct node*tree=NULL,*root=NULL;
    int choice=1;
    int ch,node,c=1;
    while(choice!=0){
        printf("\nEnter 1 to insert : ");
        printf("\nEnter 2 to inorder : ");
        printf("\nEnter 3 to preorder : ");
        printf("\nEnter 4 to postorder : ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            printf("\nEnter the node to be inserted : ");
            scanf("%d",&node);
            root=insert(root,node);
            break;
            case 2:
            inorder(root);
            break;
            case 3:
            preorder(root);
            break;
            case 4:
            postorder(root);
            break;
            default:
            printf("Enter valid choice : ");
            break;
        }
        printf("\nEnter 1 to continue and 0 to exit : ");
        scanf("%d",&choice);
    }
    return 0;
}