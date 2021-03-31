#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *link;
};

int main()
{
  printf("I'm creating a single linked list\n");
  struct node *head = malloc(sizeof(struct node));
  struct node *ptr = NULL;
  struct node *temp = malloc(sizeof(struct node));
  /*head->data = 90;
  head->link = NULL;

  // Create a single linked list
  struct node *temp = malloc(sizeof(struct node));
  temp->data = 45;
  temp->link = NULL;

  head->link = temp;
  temp = malloc(sizeof(struct node));

  temp->data = 22.4;
  temp->link = NULL;

  head->link->link = temp;
  */
  for(int i = 0; i < 4;i++)
  {
    temp = malloc(sizeof(struct node));
    printf("Enter the data for node %d:\n",i+1);
    scanf("%d",&(temp->data));
    temp->link = NULL;
    if(i == 0)
    {
      head = temp;
    }
    else
    {
    ptr = head;
    while(ptr->link != NULL)
    {
      ptr = ptr->link;
    }
    ptr->link = temp;
    }

  }
  printf("The data in the linked list is \n");
  ptr = head;
  while(ptr != NULL)
  {
  printf("%d->",ptr->data);
  ptr = ptr->link;
  }
  printf("\n");

}
