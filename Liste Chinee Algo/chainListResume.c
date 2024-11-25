#include <stdlib.h>
#include <stdio.h>


typedef struct node{
    int info;
    struct node* next;

}node;

void insertEnd(node** head,int x){ // double **: pointer pointing to a pointer that is pointing to head adress

    node* newNode=malloc(sizeof(node)) ;

    if (newNode==NULL) exit(1); 

    newNode->next=NULL;
    newNode->info=x;

    if(*head==NULL){
        *head=newNode;
        return;
    }

    //now iterate to the last node
    node* curr= *head;
    while(curr->next!=NULL) curr=curr->next; //curr now is the last node
    curr->next=newNode;


}

void deallocate(node** head){
    node* curr=*head;

    while(curr!=NULL){
        node* aux=curr;
        curr=curr->next;
        free(aux);
    }
    *head=NULL;    
}

int main(void){

    node* tete=NULL;

    insertEnd(&tete,8);
    insertEnd(&tete,9);
    node* curr = tete; // pointer type node named curr, pointing to the adress of tete
    
    do{
        printf("The num %d",curr->info);
        printf("\n");
        curr=curr->next;
        
    }while(curr!=NULL);

    deallocate(&tete);

     printf("\n");

    return 0; 

 }