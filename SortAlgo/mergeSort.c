#include <stdio.h>
#include <stdlib.h>

void merge(int left[],int c,int right[],int j, int tab[]){
    //c size of left array, j right array, n tab array
    int i=0,l=0,r=0;

    while(l<c && r<j){
        if(left[l]<right[r]){
            tab[i]=left[l];
            i++;
            l++;
        }else{
            tab[i]=right[r];
            r++;
            i++;
        }
    }
    
    //those two loops for the rest values in right or left

    while(l<c){
        tab[i]=left[l];
        l++;
        i++;
    }
    while(r<j){
        tab[i]=right[r];
        r++;
        i++;
    }    

}

void mergeSort(int tab[],int n){
    int middle=n/2;
    int leftAr[middle],rightAr[n-middle];
    if(n<=1) return;

    int j=0;
    int c=0; //counter for left array
    // splitting
    for(int i=0;i<n;i++){
        if(i<middle){ 
            leftAr[i]=tab[i];
            c++;
            }else{
            rightAr[j]=tab[i];
            j++;
        }
    }
    mergeSort(leftAr,c);
    mergeSort(rightAr,j);
    merge(leftAr,c,rightAr,j,tab);
}

int main(void){
    int tabl[]={4,2,6,8,1,0,5,7};
    mergeSort(tabl,8);
    for(int i=0;i<8;i++) printf("%d ",tabl[i]);
    return 0;

}
