#include <stdint.h>
#include <stdlib.h>
#include <stdio.h> 


typedef struct node{
    int val;
    node* fg;
    node* fd
}node;

void print_bfs(node* root){
    node* queue[100];
    int queue_num = 0;
    queue[0]= root;
    queue_num++;

    while(queue_num > 0){
        node* current = queue[0];

        for(int i = 0; i < queue_num-1; i++){
            queue[i] = queue[i+1];
        }
        queue_num--;

        if(current->fg != NULL){
            queue[queue_num] = current->fg; 
            queue_num++;
        }
        if(current->fd != NULL){
            queue[queue_num] = current->fd;
            queue_num++;
        }


    }
}


int main(void){
    int lists[6] = {5,2,1,3,6,4};
    int len = sizeof(lists) / sizeof(lists[0]);



    printf("List sorted Tss: \n");
    for(int i = 0; i < len; i++) printf("%d\t",lists[i]);
    return 0;   
}
