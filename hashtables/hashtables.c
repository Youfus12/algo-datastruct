#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NAME  256
#define TABLE_SIZE 10

typedef struct {
    char name[MAX_NAME];
    int age;
}person;

person *hashTable[TABLE_SIZE]; //pointer to the hash table , we can access froma any part of the code
void init_hashTable()
{
for(int i=0;i<TABLE_SIZE;i++){
    hashTable[i]=NULL;
}
//EMPTY TABLE
}

void print_table(){
    for(int i=0;i<TABLE_SIZE;i++){
        if(hashTable[i]==NULL){
            printf("\t%i\t---\n",i);
        }else{
            printf("\t%i\t%s\n",i,hashTable[i]->name);
        }
    }
}

unsigned int hash(char *name){
    int length=lstrlen(name);
    unsigned int hash_value=0;

    for(int i=0; i<length;i++){
        hash_value += name[i]; //each character ascii value in the char will be added to hash value a
        
    }
    return (hash_value % TABLE_SIZE);
}

bool insert_hashTable(person *p){
    if(p==NULL) return false;
    int index=hash(p->name);

    if(hashTable[index]!=NULL) return false; // Collision, index already occupied

    hashTable[index]=p;
    return true;
    
}
//fonction to find person
person *find_hashTable(char *name){
    int index=hash(name);
    //strncp= give the name of the index, first side if the space isnt null, second if it has the same index , compare it t the one that exists in the table, if are the same it will return 0 and its true(exists)

    if(hashTable[index]!=NULL && strncmp(hashTable[index]->name,name,MAX_NAME)==0) return hashTable[index];

    return NULL; 
}

person *delete_hashTable(char *name){
    int index=hash(name);

    if(hashTable[index]!=NULL && strncmp(hashTable[index]->name,name,SIZE_MAX)==0){
        person *tmp;
        tmp=hashTable[index];
        tmp=NULL;
        return tmp; //after the return free the tmp to completly delete it
    }
    return NULL;
}

int main()
{  
    person *p1=(person *)malloc(sizeof(person));
    strcpy(p1->name,"Younes"); //one way to create a value
    p1->age=12;
    //Second method to create a value
    person p2={.name="Sohaib",.age=15};
    person p3={.name="Anes", .age=19};

    insert_hashTable(p1); //p1 is the adress that the pointer *p1 is pointing
    insert_hashTable(&p2); // &p2 is the adress of the var p2 
    insert_hashTable(&p3); 

    person *tmp;

    tmp = find_hashTable("Younes");
    if(tmp==NULL) printf("Not found\n");
    else printf("Exists %s.\n",tmp->name);

    tmp=find_hashTable("Tester");
    if(tmp==NULL) printf("Not found\n");
    else printf("Exists %s\n",tmp->name);

    delete_hashTable("Younes");
    if(tmp==NULL) printf("Not found\n");
    else printf("Exists %s.\n",tmp->name);


    
    print_table(); 
    return 0;
}
