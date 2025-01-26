#include <stdlib.h>
#include <stdio.h>

void selectionSort(int tab[],int n){

    int i,j,temp,min;

    for(i=0;i<n;i++){
        min=i;
        for(j=i+1;j<n;j++){
            if(tab[min]>tab[j]){
                min=j;
            }
        }
        temp=tab[min];
        tab[min]=tab[i];
        tab[i]=temp;
    }

}


int main(void){
    int tab[6]={5,3,2,1,6,0};
    selectionSort(tab,6);

    for(int i=0;i<6;i++) printf("%d",tab[i]);

    return 0;

}
