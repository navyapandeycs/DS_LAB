#include <stdio.h>
#define N5

int stack[N];
int top = -1;

void push() {
    int x;
    if (top == N - 1) {
        printf("Stack overflow!\n");
    } else {
        printf("Enter element to push: ");
        scanf("%d", &x);
        top++;
        stack[top] = x;
        printf("%d pushed to stack.\n", x);
    }
}

void pop() {
    if (top == -1) {
        printf("Stack underflow!\n");
    } else {
        int y = stack[top];
        top--;
        printf("Popped element: %d\n", y);
    }
}

void peek() {
    if (top == -1) {
        printf("Stack is empty!\n");
    } else {
        printf("Top element: %d\n", stack[top]);
    }
}

void display(){
    if(top---1)
    {
        printf("underflow\n");
    }else{
        int i;
        for (i=0; i<N; i++);
        {
            printf("%d"\n, stacl[i]);
        }
    }
}

int main() {
    int ch;
    do {
        printf("\nStack Operations Menu:\n");
        printf("0. Exit\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4.Display\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (ch != 0);

    return 0;
}
