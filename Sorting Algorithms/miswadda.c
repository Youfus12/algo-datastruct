#include <stdlib.h>
#include <stdio.h>


int main(){

    int tab[5]={2,4,2,1,2};
    printf("%d",sizeof(tab)/sizeof(tab[0]));
 
    return 0;

}
