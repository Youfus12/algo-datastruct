#include <stdlib.h>
#include <stdio.h>

void bubleSort(int list[],int n){
    int temp,i=0,j=0;
    for(i=0;i<n;i++){
        
        for(j=0;j<n-1-i;j++){ // -i to not reach the sorted part in the next iteration,ya que the last value is sorted

            if(list[j]>list[j+1]){

                temp=list[j];
                list[j]=list[j+1];
                list[j+1]=temp;
            }

        }
    }

}


int main(void){
    int ls[]={0,2,3,1,9,60};
    bubleSort(ls,6);
    for(int i=0;i<6;i++) printf("%d ",ls[i]);

    return 0;

}
 