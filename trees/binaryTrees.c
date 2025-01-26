#include <stdio.h>
#include <stdlib.h>

/*
    Timecoplexity for those algorithms of trees: O(n)
*/
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

struct node *insert_binary(struct node *root,int var){

    if(root==NULL) return createNode(var);
    if(var<(root->data))  root->left= insert_binary(root->left,var); //the root(left r right) will have inside of it another roots thats why we insert in it
    else     root->right = insert_binary(root->right,var); 

    return root;

}
void print_depth_first(node* root){
    
    node* stack[100];
    int stack_num = 0;
    stack[0] = root;
    stack_num++;

    while(stack_num > 0){
        node* current = stack[stack_num-1]; // last node in the stack array
        stack_num--;
        printf("%d\n",(current->data));
        
        if(current->right != NULL){
            stack[stack_num] = current->right;
            stack_num++;
        }

        if(current->left != NULL){
            stack[stack_num] = current->left;
            stack_num++;
        }
    }

}

void dfs_recursive(node* node){
    printf("%d\n",node->data);
    if(node->left != NULL)  dfs_recursive(node->left);
    if(node->right != NULL )  dfs_recursive(node->right);
}
void print_breadth_first(node* root){
    node* queue[100];
    int queue_num = 0;
    queue[0] = root;
    queue_num++;

    while(queue_num > 0){
        node* current = queue[0];

        printf("%d\n",current->data);

        for(int i = 0; i < queue_num-1; i++){
            queue[i] = queue[i+1]; 
        }
        queue_num--;
        // izquierda a derecha : first in first out

        if(current -> left  != NULL ){
            queue[queue_num] = current->left;
            queue_num++;
        } 
        if(current->right != NULL){
            queue[queue_num] = current->right;
            queue_num++;
        }
    }
}


void in_order(node* root){
        // left -> root -> right
        // used in a contextof binary search tree in order
        if(root!=NULL ){
            in_order(root->left); //print all the value that are on the left
            printf("%d\n",(root->data));      //then go to the main node and print its value
            in_order(root->right);//then go to the right side 
    }

}
void post_fixe(node* root){
    // left -> right ->root
    // used in context to delete a tree from leaf to root
    if(root != NULL){
        post_fixe(root->left);
        post_fixe(root->right);
        printf("%d\n",root->data);
    }
}

void pre_order(node* root){
    // root -> left -> right
    // preoder is used to create a copy of a tree

        if(root != NULL){
            printf("%d\n",root->data);
            post_fixe(root->left);
            post_fixe(root->right);
            
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

void destroy(node *root){
    if(root == NULL) return;

    destroy(root->left);
    destroy(root->right);
    free(root);
    
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
    /*
            10

        6        12    

    5      8  11     15

    */
    root=insert_binary(root,10);
    insert_binary(root, 12);
    insert_binary(root, 11);
    insert_binary(root, 15);
    insert_binary(root, 6);
    insert_binary(root, 5);
    insert_binary(root,8);
   /* 
    in_order(root); 
    printf("This is the great number in the tree: %d\n",biggest(root));
    printf("The total of feullies %d\n\n",nbfeuilles(root));

    printf("Printing with the depht first algorithm : \n");
    print_depth_first(root);

    
    printf("Printing with the breadth first algorithm : \n");
    print_breadth_first(root);
*/

    print_depth_first(root);
    printf("\n\n\n");
    
    if(checkBST(root)==1) printf("\nYounes is sigma boy");
    return 0;
    
}
