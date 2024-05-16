#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *create(int data){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->prev=newnode->next=NULL;
    return newnode;
}struct node *insert(struct node* root,int data){
    if(root==NULL){
        return create(data);
    }
    if(data<root->data){
        root->prev=insert(root->prev,data);
    }
    else{
        root->next=insert(root->next,data);
    }
    return root;
}
int search(struct node* root,int data){
    if(root==NULL){
        return 0;
    }
    if(root->data==data){
        return 1;
    }
    else if(root->data<data){
        return search(root->next,data);
    }
    else{
        return search(root->prev,data);
    }
}
void inorder(struct node *root){
    if(root!=NULL){
        inorder(root->prev);
        printf("%d ",root->data);
        inorder(root->next);
    }
    else{
        return;
    }
}
void preorder(struct node *root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->prev);
        preorder(root->next);
    }
    else{
        return;
    }
}
void postorder(struct node *root){
    if(root!=NULL){
        postorder(root->prev);
        postorder(root->next);
        printf("%d ",root->data);
    }
    else{
        return;
    }
}
int minimum(struct node *root){
    while(root!=NULL){
        root=root->prev;
    }
    return root->data;
}
int maxi(struct node *root){
    while(root!=NULL){
        root=root->next;
    }
    return root->data;
}
struct node *mini(struct node *root){
    while(root!=NULL){
        root=root->prev;
    }
    return root;
}
struct node *delete(struct node* root, int data) {
    if (root == NULL)
        return root;

    if (data < root->data)
        root->prev = delete(root->prev, data);

    else if (data > root->data)
        root->next = delete(root->next, data);

    else {
        if (root->prev == NULL) {
            struct node* temp = root->next;
            free(root);
            return temp;
        } else if (root->next == NULL) {
            struct node* temp = root->prev;
            free(root);
            return temp;
        }
        else{
            struct node *temp=root->prev;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            root->data=temp->data;
            free(temp->next);
            temp->next=NULL;
        }
    }
    return root;
}
void main(){
    int i=1,data;
    struct node* root=NULL;
    while(i){
        printf("Enter data to be inserted:");
        scanf("%d",&data);
        root=insert(root,data);
        printf("Click 1 to insert another number:");
        scanf("%d",&i);
    }
    inorder(root);
    printf("\nEnter number to search:");
    scanf("%d",&data);
    if(search(root,data)){
        printf("Element found\n");
    }
    else{
        printf("Not found\n");
    }
    printf("Enter number to delete:");
    scanf("%d",&data);
    if(search(root,data)){
        root=delete(root,data);
    }
    else{
        printf("\nElement not found");
    }
    printf("\nInorder:");
    inorder(root);
    printf("\nPreorder:");
    preorder(root);
    printf("\nPostorder:");
    postorder(root);
}