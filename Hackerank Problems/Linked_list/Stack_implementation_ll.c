/*
This program implements stack data structure using linked list.
*/
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int x)
{   
    printf("%d",x);
    struct node *temp = malloc(sizeof(struct node));
    temp->data = x;
    temp->next = top;
    top = temp;
    printf("Pushed %d onto the stack\n",x);
}

void pop(){
    if(top == NULL){
        printf("Stack is Empty\n");
        exit(1);
    }
    printf("%d\n",top->data);
    top = top->next;
}

void isEmpty(){
    if(top == NULL){
        printf("True\n");
    }
    else{
    printf("False\n");
    }
}

void display(){
    struct node *ptr = top;
    printf("Stack elements are:\n");
    if (top != NULL){
        while (ptr != NULL)
        {
            printf("%d ",ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
    else{
        printf("Empty stack\n");
    }
}

int main()
{
    int val,ele;
    again:
        printf("Please select the operations to be performed on Stack.\n");
        printf("[1]Push\n[2]Pop\n[3]Top\n[4]Isempty\n[5]Stop\n");
        scanf("%d",&val);

        switch(val){
            case 1:printf("Enter element to push:");
                   scanf("%d",&ele);
                   push(ele);
                   //1
                   display();
                   break;

            case 2:pop();
                   display();
                   break;

            case 3:if (top != NULL){
                    printf("%d\n",top->data);
                    }
                    else{
                    printf("Empty stack\n");
                    }
                    break;

            case 4:isEmpty();
                    break;

            case 5:exit(1);
            default: printf("Please select crt operation!!!\n");
                     goto again;
        }
    goto again;
    return 0;
}