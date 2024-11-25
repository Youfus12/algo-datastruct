#include <stdlib.h>
#include <stdio.h>


typedef struct node{
    int info;
    struct node* next;

}node;

int main(void){

    node tete;

    tete.info=5;
    tete.next=malloc(sizeof(node));
    tete.next->info=10;
    tete.next->next=NULL;

    node* curr = &tete; // pointer type node named curr, pointing to the adress of tete
    
    do{
        printf("The num %d",curr->info);
        printf("\n");
        curr=curr->next;
        
    }while(curr!=NULL);

    free(tete.next);
    printf("\n");
    return 0; 

 }