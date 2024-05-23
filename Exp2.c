#include<stdio.h>
#include<stdlib.h>
#define size 10
int stack[size], top=-1;
int isEmpty(){
    return (top==-1)?1:0;
}
int isFull(){
    return(top==size-1)?1:0;
}
void push(){
    if(isFull())
        printf("Stack Overflow!!");
    else{
        top++;
        int val;
        printf("Enter Value: ");
        scanf("%d",&val);
        stack[top]=val;
        printf("Element Added!!");
    }
}
void show(){
    if(isEmpty())
        printf("Stack is Empty!!");
    else{
        int i;
        printf("Stack Elements are: \n");
        for(i=top; i>=0; i--){
            printf("%d\t",stack[i]);
        }
    }
}
void pop(){
    if(isEmpty())
        printf("Stack Underflow!!");
    else{
        printf("Removed element is %d",stack[top]);
        top--;
    }
}
void peek(){
    if(isEmpty())
        printf("Stack Underflow!!");
    else
        printf("Top element is %d",stack[top]);
}
int main(){
    while(1){
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Show\n");
        printf("5. Exit\n");
        int choice;
        printf("Enter Choice: ");
        scanf("%d",&choice);
        switch(choice){
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
                show();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid Choice!!");
                break;
        }
        printf("\n\n");
        system("pause");
        system("cls");
    }
    return 0;
}