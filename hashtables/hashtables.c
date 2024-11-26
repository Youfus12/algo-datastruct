#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NAME  256
#define TABLE_SIZE 5
/*Two methods to handle collitions here;  -Open adressing: find another free space in the table for the var(with linear probing, or using another has fonction) this is used for better memory optimization
                                          -External chaining; using chain lists (we will use this) for better and faster preformance in searching
*/
typedef struct person{
    char name[MAX_NAME];
    int age;
    struct person *next;
}person;

person *hashTable[TABLE_SIZE]; //pointer to the hash table , we can access froma any part of the code

void init_hashTable(void){
for(int i=0;i<TABLE_SIZE;i++){
    hashTable[i]=NULL;
}}// initialize EMPTY TABLE

void print_table(void){
    for(int i=0;i<TABLE_SIZE;i++){
        if(hashTable[i]==NULL){
            printf("\t%i\t---\n",i);
        }else{
            person *tmp=hashTable[i];
            printf("\t%d\t",i);
            while(tmp!=NULL){
                printf("%s- ",tmp->name);
                tmp=tmp->next;
            }
            printf("\n");
        }
        printf("\n");
    }
}

int hash(char *name){
    unsigned long length=strnlen(name,MAX_NAME);
    int hash_value=0;

    for(int i=0; i<length;i++){
        hash_value += name[i]; //each character ascii value in the char will be added to hash value a
        
    }
    return (hash_value % TABLE_SIZE);
}

bool insert_hashTable(person *p){
    if(p==NULL) return false;
    int index=hash(p->name);
    p->next=hashTable[index]; //add the first value that is in the table to the next 
    hashTable[index]=p;      // then add the new one to the table : adding to the tete of the list chain 
    return true;
    
}
//fonction to find person
person *find_hashTable(char *name){
    int index=hash(name);
    //strncp= give the name of the index, first side if the space isnt null, second if it has the same index , compare it t the one that exists in the table, if are the same it will return 0 and its true(exists)
    person *tmp=hashTable[index];
    while(tmp!=NULL && strncmp(tmp->name,name,MAX_NAME)!=0) tmp=tmp->next; //name and tmp->name are not equal 

    return tmp; //if the name is found it will return the adress of the person, sinon will return NULL cause, the last iteration will be tmp = tmp->next = NULL
}

person *delete_hashTable(char *name){
    int index=hash(name);
    person *tmp=hashTable[index];
    person *prev=NULL ;
    while(tmp!=NULL && strncmp(tmp->name,name,MAX_NAME)!=0){
    prev=tmp;
    tmp=tmp->next; //name and tmp->name are not equal 
    }
    
    if(tmp==NULL) return NULL; //case 1: NOTHING TO DELTE

    if(prev==NULL) hashTable[index]=tmp->next; // case 2 :the value that we want to delete is in the head
    else  prev->next=tmp->next;                 //case 3: the value is in the end or middle

    return tmp; //to free it and be deleted completly

    
   
}

int main(void)
{  
    person *p1=(person *)malloc(sizeof(person));
    strcpy(p1->name,"Younes"); //one way to create a value
    p1->age=12;
    //Second method to create a value
    person p2={.name="Sohaib",.age=15};
    person p3={.name="Anes", .age=25};
    person p4={.name="Samir", .age=7};
    person p5={.name="Lobster", .age=9};
    person p6={.name="Botter", .age=12};
    person p7={.name="Snozer", .age=21};

    insert_hashTable(p1); //p1 is the adress that the pointer *p1 is pointing
    insert_hashTable(&p2); // &p2 is the adress of the var p2 
    insert_hashTable(&p3);
    insert_hashTable(&p4); 
    insert_hashTable(&p5); 
    insert_hashTable(&p6); 
    insert_hashTable(&p7); 
    print_table();
    /*
    person *tmp;
    print_table();   
    tmp = find_hashTable("Younes");
    if(tmp==NULL) printf("Not found\n");
    else printf("Exists %s.\n",tmp->name);

    tmp=find_hashTable("Tester");
    if(tmp==NULL) printf("Not found\n");
    else printf("Exists %s\n",tmp->name);

    person *del=delete_hashTable("Younes");
    if(tmp==NULL) printf("Not found\n");
    else printf("Exists %s.\n",tmp->name);


    
    //rigel memoire nigro 
    free(del); 
    free(p1);
    free(tmp);
    //ok
    */
    return 0;
}
