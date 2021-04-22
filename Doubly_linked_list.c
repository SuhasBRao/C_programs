/*
This c program implements doubly linked list.
*/
#include<stdio.h>
#include<stdlib.h>

struct node
{
   struct node *prev;
   int data;
   struct node *next;
};
struct node *create_doubly_ll(struct node *head)
{
    int data;
    printf("Enter the data:");
    scanf("%d",&data);

    head->prev = NULL;
    head->data = data;
    head->next = NULL;

    return head;
}
struct node *add_at_end(struct node *head)
{
    struct node *temp = malloc(sizeof(struct node));
    struct node *ptr;
    int data;
    ptr = head;

    printf("Enter the data:");
    scanf("%d",&data);
    temp->data = data;
    //printf("%d\n",temp->data);
    while(ptr->next != NULL)
    {
        //printf("%d->",ptr->data);
        ptr = ptr->next;
    }
    
    temp->prev = ptr;
    temp->next = NULL;
    ptr->next = temp;
    head = ptr;
    
    return head;
}

struct node *add_at_beg(struct node *head)
{
    int data;
    struct node *temp = malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d",&data);
    temp->prev = NULL;
    temp->data = data;
    temp->next = head;
    head->prev = temp;

    head = temp;
    return head;
}

int display(struct node *head)
{  
    struct node *ptr;
    ptr = head;
    while(ptr != NULL)
    {
        printf("%d->",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    return 0;

}
int main()
{
   struct node *head = malloc(sizeof(struct node));
   
   head = create_doubly_ll(head);
   printf("Created a doubly linked list\n");
   display(head);
   head = add_at_end(head);
   printf("Added at end\n");
   display(head);
   head = add_at_beg(head);
   printf("Added at beginning\n");
   display(head);
   
   return 0;
}