#include <stdlib.h>
#include <stdio.h>

void insertionSort(int tab[],int n){
    int i,j,temp;

    for(i=1;i<n;i++){
        j=i-1;
        temp=tab[i];
        while(j>=0 && tab[j]>temp){
            tab[j+1]=tab[j];
            j--;
        }
        tab[j+1]=temp;
    }

}

int main(void){
    int tab[6]={5,3,2,1,6,0};
    insertionSort(tab,6);
    for(int i=0;i<6;i++) printf("%d ",tab[i]);
    return 0;
}
