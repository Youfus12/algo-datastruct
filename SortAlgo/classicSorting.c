#include <stdlib.h>
#include <stdio.h>



void triAbulle(int tab[10]){ //bubble sorting: taking the big number to the last index...

    int i=0,j=0,temp; 

    for(i=0;i<9;i++){
        for(j=0;j<=9-i;j++){ //9-i means: to ignore the sorted part(last part)
            if(tab[j]>tab[j+1]){
                temp=tab[j];
                tab[j]=tab[j+1];
                tab[j+1]=temp;

            }
        }

    }

}

void triSelection(int tab[]){
    int min,temp;
    
    for(int i=0;i<9;i++){
        min=i;

        for(int j=i;j<9;j++){
            if(tab[min]>tab[j+1]) min=j+1; //save the index of the min
        }

        temp=tab[i];
        tab[i]=tab[min];
        tab[min]=temp;
        
    }
}

void triInsertion(int tab[]){

    int temp;

    for(int i=1;i<=9;i++){
        temp=tab[i];
        int j=i-1; 
        while(j>= 0 && tab[j]>temp){ 
            tab[j+1]=tab[j]; //shift element to la derecha/right
            j=j-1;

        }
        tab[j+1]=temp; // IF tab[j] is lower than temp that means tab[j+1] is the correct position
    }

}


int main(void){
    int tabl[10]={7,5,0,3,6,8,12,32,11,10};

     triAbulle(tabl);
   // triInsertion(tabl);
    for(int i=0;i<10;i++) printf("%d ",tabl[i]);
    
    return 0;
}
