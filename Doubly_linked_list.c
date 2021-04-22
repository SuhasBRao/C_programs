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
int main()
{
   struct node *head = malloc(sizeof(struct node));
   struct node *ptr;
   head = create_doubly_ll(head);
   printf("Created a doubly linked list\n");
   head = add_at_end(head);
   ptr = head;
   printf("Updated Doubly linked list is\n");
   while(ptr != NULL)
   {
       printf("%d->",ptr->data);
       ptr = ptr->next;
   }

}