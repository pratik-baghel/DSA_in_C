#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int arr[MAX];
int TOP = -1;

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
    if(TOP == MAX - 1) {
        printf("Stack Overflow! Cannot push %d\n", value);
        return;
    }
    TOP++;
    arr[TOP] = value;
    printf("Pushed %d\n", value);
}

void pop() {
    if(TOP == -1) {
        printf("Stack Underflow! Cannot pop\n");
        return;
    }
    printf("Popped %d\n", arr[TOP]);
    TOP--;
}

void display() {
    if(TOP == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Top element: %d\n", arr[TOP]);
}