#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
    int data;
    struct node *link;
};
struct node* insertbeginning(struct node* start,int info){
//allocate memory & define the node
    struct node* temp=(struct node *)malloc(sizeof(struct node));
//put data to node
    temp->data=info;
//create link
    temp->link=start;
    start=temp;
//return the start node
    return start;
}
void insertend(struct node* start,int info){
    struct node* temp,*p;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=info;
//finding the last term's place in the list.
    p=start;
    while(p->link!=NULL){
        p=p->link;
    }
//using address of the last term of list to link the new term.
    p->link=temp;
    temp->link=NULL;
}
struct node* createlist(struct node* start){
    int n,info;
    printf("how many numbers do you want to insert?\n");
    scanf("%d",&n);

    if(n==0){return start;}

    printf("\nenter the first number=");
    scanf("%d",&info);
    start=insertbeginning(start,info);

    for(int i=1;i<n;i++){
        printf("enter the next number=");
        scanf("%d",&info);
        insertend(start,info);
    }
    return start;
}
void printlist(struct node *start) {
    struct node *p;
    p=start;
    printf("List=");
    while(p!=NULL){
        printf(" %d",p->data);
        p=p->link;
    }}
void searchlist(struct node *start,int x){
    struct node *p;
    int counter=1;
    bool a=false;
    p=start;
    while(p!=NULL){
        if(p->data==x){
            a=true;
            break;
        }
        counter++;
        p=p->link;
    }
    if(a){printf("\n%d found at the position(%d).",x,counter);}
    else{printf("%d is not in this link",x);}
}
struct node* reverselist(struct node*start){
    struct node*prev ,*ptr,*next;
    prev=NULL;
    ptr=start;
    while(ptr!=NULL){
        next=ptr->link;
        ptr->link=prev;
        prev=ptr;
        ptr=next;
    }
    start=prev;
    return start;
}
struct node* delete(struct node*start,int pos){
    struct node *p,*c;
    p=start;
    for(int i=0;i<pos-2;i++){
        p=p->link;
    }
    c=p->link;
    p->link=c->link;
    free(c);

}

struct node* delete_first(struct node*start){
    struct node* temp;
    temp=start;
    start=start->link;
    free(temp);
    return start;
}
int main(){
    struct node *start=NULL; int x,pos;
    //creates list
    start=createlist(start);

    //prints list
    printlist(start);

    //search a user-ınserted number in list
    printf("\nenter the number that you want to search=");
    scanf("%d",&x);
    searchlist(start,x);

    //reverses the list
    start=reverselist(start);
    printf("\n");   printlist(start);

    //deletes the term in the given position
    printf("\nInsert the position to delete term=");
    scanf("%d",&pos);
    if(pos!=1){
    delete(start,pos);
    printlist(start);}
    else if(pos==1){
        start=delete_first(start);
        printlist(start);
    }
    return 0;
}