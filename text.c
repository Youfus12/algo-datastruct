#include <stdio.h>
#include <stdlib.h>
// those three have a O(1) space coplexity

void bubble_sort(int lst[], int len){
    // best case O(n): already sorted
    // worst case O(n^2)   Reverse-sorted array

    for(int i = 0; i < len; i++){

        for(int j = 0 ; j < len-i-1; j++){

            if(lst[j] > lst[ j+1]){ // change the  > to < for decroissant order
                int temp = lst[j];
                lst[j] = lst[j+1];
                lst[j+1] = temp;
            }
        }
    }
}

void selection_sort(int lst[], int len){
    // best/worst case O(n^2) :always 

    for(int i = 0 ; i < len; i++){

        int min = i;
        for(int j = i+1; j < len;j++){
            if(lst[min] > lst[j]) min = j; // change the  > to < for decroissant order
        }

        int temp = lst[i];
        lst[i] = lst[min];
        lst[min] = temp; 
    }
}

void insertion_sort(int lst[],int len){
    // best case : O(n) already sorted
    // worst case O(n^2) revers sorted
    for(int i = 0; i < len; i++) printf("%d\t",lst[i]);
    printf("\n\n");

    for(int i = 1; i < len; i++){
        int temp = lst[i];
        int j = i - 1;
            while(j >= 0 && lst[j] > temp){ // change the > to < for decroissant order
                lst[j+1] = lst[j];
                j--;
            }
        lst[j+1] =  temp;
    }
}




void merge(int leftLst[],int lenLeft, int rightLst[], int lenRight, int lst[]){
    int l = 0, r = 0, len = 0;

    while( l < lenLeft && r < lenRight){
        if(leftLst[l] < rightLst[r]){ // change the  < to > for decroissant order
            lst[len] = leftLst[l];
            l++;
        }else{
            lst[len] = rightLst[r];
            r++;
        }
        len++;
    }
// if left list is not fully added to list
    while( l < lenLeft){
        lst[len] = leftLst[l];
        l++;
        len++;
    }
// if right list is not fully added in list
    while(r < lenRight){
        lst[len] = rightLst[r];
        r++;
        len++;
    }
}

void mergeSort(int lst[], int len){
    // all casees O(n log(n): 
    // space complexity : O(log(n))
    int middle = len/2;
    int leftLst[middle], rightLst[len-middle];
    int j = 0; // len of leftLst
    int c = 0; // len of rightLst
    if(len <= 1) return;

    for(int i = 0; i < len ; i++){

        if(i < middle){
            leftLst[j] = lst[i];
            j++;
        }else{
            rightLst[c] = lst[i];
            c++;
        }
    }
    
    mergeSort(leftLst,j);
    mergeSort(rightLst,c);
    merge(leftLst,j,rightLst,c,lst);

}

int partition(int lst[], int start, int end){
    int pivot = lst[end];
    int i = start - 1;

    
    for(int j = start ; j <= end ; j++){
        if(lst[j] < pivot){ // change the  < to > for decroissant order
            i++;
            int temp = lst[j];
            lst[j] = lst[i];
            lst[i] = temp;
        }
    }
    i++; 
    int temp = lst[end];
    lst[end] = lst[i];
    lst[i] = temp;

    return i;
}

void quickSort(int lst[], int start, int end){
    // best Case O(nlog(n)): good pivot
    // Worst Case O(n^2) : bad pivot or sorted array
    // Space complexity:  best :log(n)  Worst: (n)
    if(end <= start) return;

    int pivot = partition(lst, start,end);

    quickSort(lst, start, pivot - 1 );
    quickSort(lst, pivot + 1, end);
}

int main(void){
    int lists[6] = {5,2,1,3,6,4};
    int len = sizeof(lists) / sizeof(lists[0]);

    

    printf("List sorted Tss: \n");
    for(int i = 0; i < len; i++) printf("%d\t",lists[i]);
    return 0;   
}
