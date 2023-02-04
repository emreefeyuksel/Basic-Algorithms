#include <stdio.h>
#include <stdlib.h>
/*******STACK************/
/*********Array Implementation********/
/*int top=-1;
int arr[20];

void add_element(int x){
    top++;
    arr[top]=x;
}
void delete_element(){
        arr[top]=0;
        top--;
}
void show_size(){
    printf("size is :%d\n",top+1);
}
void display(){
    printf("-Stack-\n");
    for(int i=top;i>-1;i--){
        printf("%d\n",arr[i]);
    }
}
int main() {
    int x,choice;
    while(1){
        printf("\n1.Push element to stack\n");
        printf("2.Pop element from stack\n");
        printf("3.Show size of the stack\n");
        printf("4.Show terms of the stack\n");
        printf("5.Quit\n");
        printf("please enter your choice=");
        scanf("%d",&choice);
        if(choice==5)
            break;
        switch(choice){
            case 1:
                printf("enter the element will be pushed=");
                scanf("%d",&x);
                add_element(x);
                break;
            case 2:
                delete_element();
                break;
            case 3:
                show_size();
                break;
            case 4:
                display();
                break;
            default:
                printf("not valid choice!\n");
        }
    }
    return 0;
}*/
/*********Linked List Implementation*********//*
struct node{
    int info;
    struct node* link;
};
struct node*top;

void add_element(int x){
    struct node* temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->link=top;
    temp->info=x;
    top=temp;
}
void delete_element(){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp=top;//declaring pointer temp as first node's pointer
    //popped element is optional
    top=top->link;//taking first pointers link to 2nd node
    free(temp);//deleting temp node
}
void show_size(){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    int i;
    temp=top;
    for(i=0;temp!=NULL;i++){
        temp=temp->link;
    }
    printf("size is:%d\n",i);
}
void display(){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp=top;
    while(temp!=NULL){
        printf("%d\n",temp->info);
        temp=temp->link;
    }
}

int main(){
    int x,choice;
    top=NULL;
    while(1){
        printf("\n1.Push element to stack\n");
        printf("2.Pop element from stack\n");
        printf("3.Show size of the stack\n");
        printf("4.Show terms of the stack\n");
        printf("5.Quit\n");
        printf("please enter your choice=");
        scanf("%d",&choice);
        if(choice==5)
            break;
        switch(choice){
            case 1:
                printf("enter the element will be pushed=");
                scanf("%d",&x);
                add_element(x);
                break;
            case 2:
                delete_element();
                break;
            case 3:
                show_size();
                break;
            case 4:
                display();
                break;
            default:
                printf("not valid choice!\n");
        }
    }
    return 0;
}*/
/*********QUEUE***********/
/********Array Implementation********/
/*
int arr[20];
int rear;
int front;
void initialize_queue(){
    front++;
}
void add_element(int x){
      rear++;
      arr[rear]=x;
}
void delete_element(){
    int temp=arr[front];
    front++;
}
void show_size(){
    int size=rear-front+1;
    printf("%d",size);
}
void display (){
    printf("\nQueue is:");
    for(int i=front;i<=rear;i++){
        printf(" %d ",arr[i]);
    }
}

int main(){
    int choice,x;
    rear = -1;
    front = -1;
    initialize_queue();
    while(1){
        printf("\n1.Enqueue element to queue\n");
        printf("2.Dequeue element from queue\n");
        printf("3.Show size of the queue\n");
        printf("4.Show terms of the queue\n");
        printf("5.Quit\n");
        printf("please enter your choice=");
        scanf("%d",&choice);
        if(choice==5)
            break;
        switch(choice){
            case 1:
                printf("enter the element will be enqueue=");
                scanf("%d",&x);
                add_element(x);
                break;
            case 2:
                delete_element();
                break;
            case 3:
                show_size();
                break;
            case 4:
                display();
                break;
            default:
                printf("not valid choice!\n");
        }
    }
    return 0;
}*/
/*********Linked List Implementation*********/
/*
struct node{
    int info;
    struct node*link;
};
struct node*front,*rear;

void add_element(int x){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->info=x;
    temp->link=NULL;
    if(front==NULL)
        front=temp;
    else
        rear->link=temp;
    rear=temp;
}
void delete_element(){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp=front;
    front=front->link;
    free(temp);
}
void show_size(){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    int counter=0;
    temp=front;
    while(temp!=NULL){
        counter++;
        temp=temp->link;
    }
    printf("size is:%d",counter);
}
void display(){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp=front;
    printf("Queue:");
    while(temp!=NULL){
        printf(" %d ",temp->info);
        temp=temp->link;
    }
}

int main(){
    int choice,x;
    front=NULL;
    rear=NULL;
    while(1){
        printf("\n1.Enqueue element to queue\n");
        printf("2.Dequeue element from queue\n");
        printf("3.Show size of the queue\n");
        printf("4.Show terms of the queue\n");
        printf("5.Quit\n");
        printf("please enter your choice=");
        scanf("%d",&choice);
        if(choice==5)
            break;
        switch(choice){
            case 1:
                printf("enter the element will be enqueue=");
                scanf("%d",&x);
                add_element(x);
                break;
            case 2:
                delete_element();
                break;
            case 3:
                show_size();
                break;
            case 4:
                display();
                break;
            default:
                printf("not valid choice!\n");
        }
    }
    return 0;
}*/
/************Circular Queue************/


/*************Deque******************/
