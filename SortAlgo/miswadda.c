#include <stdlib.h>
#include <stdio.h>


typedef struct node{
    int val;
    struct node *one;
    struct node *two;
    struct node *three;
}node;

int nbfeuilles(struct node *root){
    int som = 0;
    
    som += nbfeuilles(root->one);
    som += nbfeuilles(root->two);
    som += nbfeuilles(root->three); 
    return som;   
}

int main(){

    int tab[5]={2,4,2,1,2};
    printf("%d",sizeof(tab)/sizeof(tab[0]));
 
    return 0;

}
