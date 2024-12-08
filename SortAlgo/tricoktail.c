#include <stdio.h>
#include <stdalign.h>
#include <stdbool.h>

void triAbull(int tab[],int n){
    int temp;
    for(int i = 0; i < n ; i++ ){

        for(int j = 0; j< n-i;j++){
            if(tab[j]>tab[j+1]) {
                temp = tab[j+1];
                tab[j+1] = tab[j];
                tab[j] = temp;
            }
        }
    }
}

void triCoktail(int tab[], int n){
    int sorted = 0;
    int deb = 0;
    int fin = n - 1;
    while(sorted != 1){
        sorted = 1;
        for(int i = deb; i<fin ;i ++ ){
            if(tab[i]>tab[i+1]){
                int temp = tab[i+1];
                tab[i+1] = tab[i];
                tab[i] = temp;
                sorted = 0;
            }
        }
        fin--;

        for(int i = fin;i > deb;i--){
            if(tab[i]<tab[i-1]){
                int temp = tab[i-1];
                tab[i-1] = tab[i];
                tab[i] = temp;
            sorted = 0;

            }
        }
        deb++;
}
}

int main(){
    int tab[] = {5,2,1,3,4,4,1,2,5,2,1,2,51,231,21,213,342,232};
    triCoktail(tab,18);
    for(int i = 0;i<18;i++) printf("%d ",tab[i]);
}