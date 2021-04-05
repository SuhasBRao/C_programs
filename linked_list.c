#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *link;
};

struct node *create_Linked_list(int no_nodes, struct node *head)
{
  /*
  Purpose : Function is used to create a linked list with n number of nodes.

  Inputs : [1] no_nodes - integer
            indicates the number of nodes in the linked list.
           [2] *head - struct pointer
            Head pointer is used to point to the head of the linked list.
  Output : head pointer
           head pointer that points to the modified linked list.


  */
  for(int i = 0; i < no_nodes;i++)
  {
    struct node *ptr = NULL;
    struct node *temp = malloc(sizeof(struct node));


    printf("Enter the data for node %d:\n",i+1);
    scanf("%d", &(temp->data));
    printf("***************************\n");
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
  return head;
}

void print(struct node *head)
{
  /*
  Purpose : The fucntion is used to print the contents of the linked create_Linked_list
            pointed by the head pointer.
  INputs : head - Pointer
           Head pointer that points to the linked list to be printed.
  Outputs : head - Pointer
            head pointer which points to the modified linked list.
  */
  struct node *ptr = NULL;

  printf("The data in the linked list is as follows\n");
  printf("###################################\n");
  ptr = head;
  while(ptr != NULL)
  {
  printf("%d->",ptr->data);
  ptr = ptr->link;
  }
  printf("\n");
  printf("###################################\n");
}

struct node *add_at_end(struct node *head)
{
  /*
  Purpose: This function adds any node at the end of the list.
  Input:  *head : pointer
          head pointer which points to a single linked list.
  Output: *head : pointer
          Return the head pointer that points to the new linked list.
  */

  int data;
  struct node *temp = malloc(sizeof(struct node));
  struct node *ptr = NULL;

  printf("Enter the data node should have\n");

  scanf("%d",&data);

  temp->data = data;
  temp->link = NULL;

  ptr = head;
  while(ptr->link != NULL)
  {
    ptr = ptr->link;
  }
  ptr->link = temp;

  return head;
}

struct node *add_at_beg(struct node *head)
{
  /*
  Purpose : This function adds a node at the front of the linked list.
  INputs : head - Pointer
           Function takes a head pointer which points to the head of the linked list.
  Outputs: head - pointer
          The function returns head pointer which points to the modified list.

  */
  int data;
  struct node *temp = malloc(sizeof(struct node));

  printf("***************************\n");
  printf("Enter the data for node:\n");
  scanf("%d", &data);
  printf("***************************\n");

  temp->data = data;
  temp->link = head;

  head = temp;
  return head;
}

int main()
{

  printf("Welcome, This program creates a single linked list\n");

  struct node *head = malloc(sizeof(struct node));
  struct node *temp = malloc(sizeof(struct node));
  int no_nodes;
  int ops,data;

  printf("*****************************\n");
  printf("Enter the number of nodes you want to create\n");
  scanf("%d", &no_nodes);
  printf("*****************************\n");

  head = create_Linked_list(no_nodes, head);


// Prompts the user to choose an operation to perform on the linked list

  printf("Select operations you want to perform on Linked list:\n");
  printf("[1] Insert node at END\n[2] Insert node at Beginning\n[3] Display linked list\n");

  printf("-------------------\n");
  scanf("%d", &ops);
  printf("-------------------\n");
  printf("******* Chosen Operation ******\n");

// Below switch statement executes the particular operation
// as chosen by the user.
  switch (ops) {
    case 1: printf("Insert node at End.\n");
            head = add_at_end(head);
            printf("Node inserted at the end.\n");
            print(head);
            break;

    case 2: printf("Insert node at Beginning.\n");
            head = add_at_beg(head);
            printf("Node inserted at the Beginning.\n");
            print(head);
            break;

    case 3: printf("Display the linked list\n");
            print(head);
            break;

    default: printf("Please choose available operations.\n");
  }

  return 0;

}
