#include <stdio.h>
#include <stdlib.h>

void fusion(int tab1[],int c1,int tab2[],int c2,int mainTab[]){

    int i=0;int j=0;int k=0;

    while(i<c1 && j<c2){
        
        if(tab1[i]>tab2[j]){
            mainTab[k]=tab2[j];
            k++;
            j++;
        }else{
            mainTab[k]=tab1[i];
            i++;
            k++;
        }
        
    }

    while(i<c1){
        mainTab[k]=tab1[i];
        k++;
        i++;

    }
    while(j<c2){
        mainTab[k]=tab2[j];
        k++;
        j++;

    }
}

int main(void){

    int tab1[]={2,4,6,8,9};int c1=5;
    int tab2[]={0,1,5,7}; int c2=4;
    int mainTab[20];
    
    fusion(tab1,c1,tab2,c2,mainTab);

    for(int i=0;i<(c1+c2);i++) printf("%d ", mainTab[i]);


    return 0;
}
