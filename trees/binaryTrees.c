#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int data;
    struct node *right;
    struct node *left;
}node;

struct node *createNode(int var){

    struct node *nouv=(struct node*)malloc(sizeof(node));
    if (nouv!=NULL){
        nouv->data=var;
        nouv->left=NULL;
        nouv->right=NULL;
    }
    return nouv;
}

struct node *insert(struct node *root,int var){

    if(root==NULL) return createNode(var);
    if(var<(root->data))  root->left= insert(root->left,var); //the root(left r right) will have inside of it another roots thats why we insert in it
    else     root->right = insert(root->right,var); 

    return root;

}

void aficherTree(struct node *root){
    if(root!=NULL ){
        aficherTree(root->left); //print all the value that are on the left
        printf("%d\n",(root->data));      //then go to the main node and print its value
        aficherTree(root->right);//then go to the right side 
    }
}

int searchTree(struct node *root,int var){

    if (root==NULL) return 0;
    else if(var==(root->data)) return 1;
    else if(var<(root->data)) return searchTree(root->left,var);//if the value is not in this root and its bigger than it , the it must be in the left side...
    else if(var>(root->data)) return searchTree(root->right,var); 

    return 0;
}

int succesor(struct node *root){
    root=root->right; //go to the right, then to the extreme left to find the first greater number than the main root 
    while(root->left!=NULL){
        root=root->left;
    }
    return (root->data);

}
int biggest(struct node *root){
    root=root->right;
    struct node *current = root;
    while(current->right != NULL){
        current = current->right;
    }
    return current->data;
}
int predecesseur(struct node *root){
    root=root->left;
    while(root->right!=NULL){
        root=root->right;
    }
    return root->data;
}
struct node *removeVar(struct node *root, int var){

    if(!searchTree(root,var)){
        printf(" %d does not exists to eliminate",var);
        return NULL;
    }else if(var<(root->data)) root->left=removeVar(root->left,var);
     else if(var>(root->data)) root->right=removeVar(root->right,var);
    //if is not bigger or lower than we are in the good node , so we proceed to remove it
    else{
        if(root->left==NULL && root->right==NULL) root=NULL;
        else if(root->left!=NULL){ //place the data of the left node in its right place
            root->data=predecesseur(root);
            root->left=removeVar(root->left,root->data);
        }
        else if(root->right!=NULL){ //place the data of the right node in its right place
            root->data=succesor(root);
            root->right=removeVar(root->right,root->data);
        }
    }
    return root;

}

void removeBiggest(struct node *root){
    struct node *parent = NULL;
    struct node *current = root;
    while((current->right != NULL)){
        parent = current;
        current = current->right;
    }
    if(current->left != NULL) parent->right = current->left;
    else parent -> right = NULL;

    free(current);
}
int nbfeuilles(struct node *root){

    if(root == NULL) return 0; //nothing
    else if(root->right == NULL && root->left==NULL) return 1; //this is the feuille
    return nbfeuilles(root->right) + nbfeuilles(root->left);   
}
int main(void){

    struct node *root=NULL;
    
    root=insert(root,10);
    insert(root,12); //will work with root= or without it: why? i dont know hhhhh antik
    insert(root,51);
    insert(root,82);
    insert(root,2);
    insert(root,5);
    insert(root,1);
    insert(root,3);
    aficherTree(root); 
    printf("This is the great number in the tree: %d\n",biggest(root));
    removeBiggest(root);
    aficherTree(root);
    printf("The total of feullies %d\n",nbfeuilles(root));
    return 0;
    
}
