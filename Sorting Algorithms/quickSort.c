#include <stdlib.h>
#include <stdio.h>

int partiton(int tab[],int start, int end){

    int pivot=tab[end];
    int i=start-1;

    for(int j=start; j<=end; j++){
        if(tab[j]<pivot){
            i++;
            int temp=tab[i];
            tab[i]=tab[j];
            tab[j]=temp;
        }
    }
    i++;
    int temp=tab[i];
    tab[i]=tab[end];
    tab[end]=temp;

    return i;
}

void quickSort(int tab[],int start, int end){
    
    if(end<=start) return;

    int pivot=partiton(tab,start,end);
    quickSort(tab,start,pivot-1);
    quickSort(tab,pivot+1,end);

}

int main(void){
    int tabl[]={4,2,6,8,1,0,5,7};

    quickSort(tabl,0,7);
    for(int i=0;i<8;i++) printf("%d ",tabl[i]);
    return 0;

}
