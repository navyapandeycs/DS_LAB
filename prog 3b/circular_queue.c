#include<stdio.h>

#define N 3


int queue[N];
int front=-1;
int rear=-1;

int enqueue(){
    int x;
    printf("Enter element to insert:");
    scanf("%d",&x);

    if(front==-1 && rear==-1){
        front=rear=0;
        queue[rear]=x;
    }
    else if(((rear+1)%N)==front){
        printf("Queue is full");
    }
    else{
        rear=(rear+1)%N;
        queue[rear]=x;
    }
}

int dequeue(){
    if(front==-1 && rear==-1){
        printf("Queue is empty");
    }
    else if(front==rear){
        printf("Dequeued element is %d", queue[rear]);
        front=rear=-1;
    }
    else{
        printf("Dequeued element is %d", queue[front]);
        front=(front+1)%N;
    }
}

void display(){
    if(front==-1 && rear==-1){
        printf("Queue is empty");
    }
    else if(front<rear){
        for(int i=front;i<=rear;i++){
            printf("%d  ",queue[i]);
        }
    }
    else{
        for(int j=0;j<=rear;j++){
            printf("%d  ",queue[j]);
        }
        for(int i=front;i<N;i++){
            printf("%d  ",queue[i]);
        }
    }
}

int main(){
    int choice;

    while(choice!=4){
        printf("\nEnter choice:\n1.Insert \n2.Delete \n3.Display \n4.Exit \n");
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