#include <stdio.h>
#include <stdlib.h>



int main(){
    int tabl[]={1,2,3,4,9,10,21};int taille=7;
    int i,t=taille-1;
    int x=8;

    while (t>0){
        if(tabl[t]>x) {
            tabl[t+1]=tabl[t];
            t--;
        }else{
        tabl[t+1]=x;
        t=0;

        }
    }

    for(i=0;i<=taille;i++)printf("%d ",tabl[i]);

    return 0;

}
