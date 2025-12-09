#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top=NULL;
struct Node *front=NULL;
struct Node *rear=NULL;

struct Node *createNode(int data){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    if(!newNode){
        printf("Memory alloaction failed\n");
        exit(0);
    }
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

void push(int value){
    struct Node *newNode=createNode(value);
    newNode->next=top;
    top=newNode;
    printf("%d pushed onto the stack\n",value);
}

void pop(){
    if (top==NULL){
        printf("Stack empty");
        return;
    }
    struct Node *temp=top;
    printf("Popped %d",top->data);
    top=top->next;
    free(temp);
}

void displayStack(){
    struct Node *temp=top;
    if (top==NULL){
        printf("Stack empty");
        return;
    }
    printf("Stack (Top to Bottom): ");
    while (temp!=NULL){
        printf("%d ", temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void enqueue(int value){
    struct Node *newNode=createNode(value);
    if (rear==NULL){
        front=rear=newNode;
    }else{
        rear->next=newNode;
        rear=newNode;
    }
    printf("%d enqueued to queue\n",value);
}

void dequeue(){
    if (front==NULL){
        printf("Queue empty");
        return;
    }

    struct Node *temp=front;
    printf ("Dequeued %d ", front->data);
    front=front->next;

    if (front==NULL)
        rear=NULL;

    free(temp);
}

void displayQueue(){
    struct Node *temp=front;
    if (temp==NULL){
        printf("Queue empty\n");
        return;
    }

    printf(" Queue (Front to Rear): ");
    while (temp!=NULL){
        printf("%d ", temp->data);

        temp=temp->next;
    }
    printf("\n");
}



int main(){
    int ch,value,choice;

    while(1){
        printf("\n---Singly Linked List Operations---\n1. Stack operations\n 2. Queue operations\n 3. exit\n");
        printf("enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            while(1){
                main_menu:printf("\n---Stack Menu---\n 1. push\n 2. pop\n 3. Display\n 4. Back to main menu\n");
                printf("enter your choice: ");
                scanf("%d", &ch);

                switch (ch){
                    case 1:
                        printf("Enter value to push:  ");
                        scanf("%d", &value);
                        push(value);
                        break;

                    case 2:
                        pop();
                        break;

                    case 3:
                        displayStack();
                        break;

                    case 4:
                        exit(0);

                    default:
                        printf("Invalid choice\n");
                }

            }

            break;


        case 2:
            while(1){
                printf("\n---Queue Menu---\n 1. enqueue\n 2. dequeue\n 3. Display\n 4. Back to Main Menu\n");
                printf("enter your choice: ");
                scanf("%d", &ch);

                switch (ch){
                    case 1:
                        printf("Enter value to enque:  ");
                        scanf("%d", &value);
                        enqueue(value);
                        break;

                    case 2:
                        dequeue();
                        break;

                    case 3:
                        displayQueue();
                        break;

                    case 4:
                       exit(0);

                    default:
                    printf("Invalid choice\n");
                }

            }
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid choice");
        }
    }
    return 0;
}