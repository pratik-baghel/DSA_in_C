#include<stdio.h>
#include<stdlib.h>

struct stack{
    int info;
    struct stack *link;
}; 
struct stack *TOP = NULL;

void push(int value);
void pop();
void display();

int main(){
    push(10);
    push(20);
    push(30);
    
    display();
    pop();
    pop();

    display();
    return 0;
} 

void push(int value) {
    struct stack *ptr;
    ptr = (struct stack*)malloc(sizeof(struct stack));

    ptr->info = value;
    ptr->link = TOP;
    TOP = ptr;

    printf("Pushed %d\n", value);
}

void pop() {
    if(TOP == NULL) {
        printf("Stack Underflow! Cannot pop\n");
        return;
    }
    struct stack *ptr = TOP;
    printf("Popped %d\n", ptr->info);
    TOP = ptr->link;
    free(ptr);
}

void display() {
    if(TOP == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Top element: %d\n", TOP->info);
}