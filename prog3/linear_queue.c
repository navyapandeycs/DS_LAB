#include<stdio.h>

#define N 10

int queue[N];
int front=-1;
int rear=-1;
 
int enqueue(){
    int x;

    printf("Enter element to insert:");
    scanf("%d",&x);

    if(rear==N-1){
        printf("Queue is full");
    }
    else if (front==-1 && rear==-1){
        front=rear=0;
        queue[rear]=x;
    }
    else{
        rear++;
        queue[rear]=x;
    }
}

int dequeue(){
    if(front==-1 && rear==-1){
        printf("Queue is empty");
    }
    else if(front==rear){
        printf("Dequeued elements is %d", queue[rear]);
        front=rear=-1;
    }
    else{
        printf("Dequeued elements is %d", queue[front]);
        front++;
    }
}

void display(){
    if(front ==rear==-1){
        printf("Queue is empty");
    }
    else{
        for(int i=front;i<=rear;i++){
            printf("%d  ",queue[i]);
        }
    }
}

int main(){
    int   choice;

    while(choice!=4){
        printf("\nEnter operation to perform:\n1.Insert \n2.Delete \n3.Display \n4.Exit \n");
        scanf("%d",&choice);

        switch(choice){
            case 1:enqueue();
            break;

            case 2:dequeue();
            break;

            case 3:display();
            break;

            case 4: break;

            default: printf("Invalid Choice");
        }
    }
}