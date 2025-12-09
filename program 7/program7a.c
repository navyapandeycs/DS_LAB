#include <stdio.h>
#include <stdlib.h>

struct Node {
int data;
struct Node *prev, *next;
};

struct Node *head=NULL,*tail=NULL;

void createList(int n) {
    int i, data;
    struct Node *newNode;

    for (i = 1; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->prev = newNode->next = NULL;

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
}

void insertAtFront(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=head;
    newNode->prev=NULL;

    if(head==NULL)
        head=tail=newNode;
    else{
        head->prev=newNode;
        head=newNode;
    }
    printf("%d inserted at front\n",data);
}

void insertAtEnd(int data){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    newNode->prev=tail;

    if(tail==NULL)
        head=tail=newNode;
    else{
        tail->next=newNode;
        tail=newNode;
    }
    printf("%d inserted at end\n",data);
}

void insertAtPosition(int data,int pos){
    int i;
    struct Node *newNode,*temp=head;

    if(pos<1){
        printf("enter valid position\n");
        return;
    }
    if(pos==1){
        insertAtFront(data);
        return;
    }

    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;

    for(i=1;1<pos-1&&temp!=NULL;i++){
        temp=temp->next;
    }

    if(temp==NULL||temp->next==NULL){
        insertAtEnd(data);
        return;
    }

    newNode->next=temp->next;
    newNode->prev=temp;
    temp->next->prev=newNode;
    temp->next=newNode;
    printf("%d inserted at %d postion\n",data,pos);
}

void deleteAtFront(){
    struct Node *temp=head;

    if(head==NULL){
        printf("List is empty\n");
        return;
    }

    head=head->next;
    if(head!=NULL)
        head->prev==NULL;
    else
        tail=NULL;
    printf("%d deleted\n",temp->data);
    free(temp);
}

void deleteAtEnd(){
    struct Node*temp;
    if(tail==NULL){
        printf("List is empty\n");
        return;
    }

    temp=tail;
    tail=tail->prev;

    if(tail!=NULL)
        tail->next=NULL;
    else
        head=NULL;
    printf("%d deleted\n",temp->data);
    free(temp);
}

void deleteByValue(int value){
    struct Node *temp=head;

    if(head==NULL){
        printf("List is empty\n");
        return;
    }

    while(temp!=NULL && temp->data!=value)
        temp=temp->next;

    if(temp==NULL){
        printf("Value not found\n");
        return;
    }

    if(temp==head)
        deleteAtFront();
    else if(temp==tail)
        deleteAtEnd();
    else{
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
    }
    printf("%d deleted\n",value);
}

void displayForward(){
    struct Node *temp=head;
    printf("List (Forward): ");
    while(temp!=NULL){
        printf("%d <->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

void displayBackward(){
    struct Node *temp=tail;
    printf("List (Backward): ");
    while(temp!=NULL){
        printf("%d <->",temp->data);
        temp=temp->prev;
    }
    printf("NULL\n");
}

int main() {
    int n,x;

    printf("Enter number of nodes to create: ");
    scanf("%d", &n);
    createList(n);

    displayForward();
    displayBackward();

    insertAtFront(10);
    insertAtEnd(99);
    insertAtPosition(77, 2);

    displayForward();

    deleteAtFront();
    deleteAtEnd();
    printf("enter value to delete ");
    scanf("%d",&x);
    deleteByValue(x);

    displayForward();

    return 0;
}