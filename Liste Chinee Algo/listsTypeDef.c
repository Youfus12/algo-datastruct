#include <stdio.h>
#include <stdlib.h>

typedef struct etudiant{
    int id;
    char *nom;
    char *prenom;
    float moy;
    struct etudiant  *next;
}etudiant;


float *calcMoy(struct etudiant *TETE){

    float som=0;
    int i=0;
    struct etudiant *position=TETE;
    while(position!=NULL){
        som+=(position->moy);
        i++;
        position=position->next;
    }

    float *moyn=malloc(sizeof(float));
    if (moyn==NULL){
        printf("NO MEMMORY");
        exit(1);
    }

    if(i!=0) *moyn=(som/i);
    
    return moyn;
}

void create(struct etudiant **tete, int id, char *nom, char *prenom,float moy){
    struct etudiant *etu=malloc(sizeof(etudiant));
    if(etu==NULL) {
        printf("Exit no memory");
        exit(1);
    }
        etu->id=id;
        etu->nom=nom;
        etu->prenom=prenom;
        etu->moy=moy;
        etu->next=*tete;
        *tete=etu;
    
    
}
void aficher(struct etudiant *TETE){
    struct etudiant *temp=TETE;
    while(temp!=NULL){
        
        printf("ID:%d \nName: %s \nPrename: %s\nNote:%f\n",
        temp->id,temp->nom,temp->prenom,temp->moy
        );
        temp=temp->next;
        printf("-------\n");
    }
}

void freeList(struct etudiant *TETE){
    struct etudiant *temp;

    while(TETE!=NULL){
        temp=TETE;
        TETE=TETE->next;
        free(temp->nom);
        free(temp->prenom);
        free(temp);
    }



}

int main(){

    struct etudiant *E=NULL;
    float *moyn;
    create(&E,13,"younes","chiad",12);
    create(&E,14,"mohamed","rresto",19);
    create(&E,15,"sidali","cobol",2);
    create(&E,16,"assembly","trit",9);
    create(&E,17,"steve","minecraft",16);

    aficher(E);
    moyn=calcMoy(E);
    printf("La moyenne de class %f\n",*moyn);
    free(moyn);

    struct etudiant *L1=NULL;
    struct etudiant *L2=NULL;
    struct etudiant *temp2=E;

    while(temp2!=NULL){
        if(temp2->moy>=10) create(&L1,temp2->id,temp2->nom,temp2->prenom,temp2->moy);
        else create(&L2,temp2->id,temp2->nom,temp2->prenom,temp2->moy);
        temp2=temp2->next;
    }
    
    printf("The first List L1\n");
    aficher(L1);
    printf("_-----");
    aficher(L2);
    //rigel memoire sahbob
    
    free(temp2);
    freeList(E);
    freeList(L1);
    freeList(L2);
    return 0;

}
