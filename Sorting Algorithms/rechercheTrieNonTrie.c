#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int searchNonTrie(int tab[],int c,int x){
    
    int i;
    for(i=0;i<c;i++){
        if(tab[i]==x) return i;
    }
    return false;

}




int main(void){
    int tab[6]={5,3,2,1,6,0};
    int x;
    
    printf("Scan the value that you wanna check: ");
    scanf("%d",&x);
    if(searchNonTrie(tab,6,x)){
        printf("The value exists at pos %d",searchNonTrie(tab,6,x));
    }else{
        printf("The value does not exists");
    }




    printf("\n");
    return 0;

}
