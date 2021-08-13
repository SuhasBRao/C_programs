/*
  The below program creates a single linked list and performs specific operations
  asked by the user.
*/
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
  if(head == NULL)
  {
    printf("Nothing to display.\n");
  }
  else
  {
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

struct node *add_at_pos(int max_no_nodes, struct node *head)
{
  /*
  Purpose : this function adds a node at a position specified by the user.
  Inputs : head - Pointer
          points to the linked list which has to be modified.
  Output : head - Pointer
          points to the linked list after modification.
  */
  struct node *temp = malloc(sizeof(struct node));
  struct node *ptr = NULL;
  int pos;

  here:
  printf("Enter a position less than or equal%d\n",max_no_nodes);
  scanf("%d",&pos);
  if(pos > max_no_nodes)
  {
    goto here;
  }
  printf("Enter the data in the node\n");
  scanf("%d",&(temp->data));

  ptr = head;

  for(int i = 0; i < pos - 2; i++)
  {
    ptr = ptr->link;
  }
  temp->link = ptr->link;
  ptr->link = temp;

  return head;
}

struct node *del_node_beg(struct node *head)
{
  /*
  Purpose : This function deletes a node at the beginning of the linked list.
  Input : head - Pointer
         pointer that points to the linked list that has to be modified.
  Output : head - Pointer
        pointer that points to the modified linked list.
  */
  if(head == NULL)
  {
    printf("List is empty.\n");
  }
  else
  {
    struct node *temp = malloc(sizeof(struct node));
    temp = head;
    head = temp->link;
    free(temp);
    temp = NULL;
  }

  return head;
}

struct node *del_node_end(struct node *head)
{
   /*
  Purpose : This function deletes a node at the end of the linked list.
  Input : head - Pointer
         pointer that points to the linked list that has to be modified.
  Output : head - Pointer
        pointer that points to the modified linked list.
  */

  if(head == NULL)
  {
    printf("List is empty\n");
  }
  else
  {
    struct node *temp = malloc(sizeof(struct node));
    struct node *temp2 = malloc(sizeof(struct node));
    temp = head;
    temp2 = head;
    while(temp->link != NULL)
    {
      temp2 = temp;
      temp = temp->link;
    }
    // now the temp pointer is pointing to the last but one node.
    //temp2 pointer ponints to the last  node.
    temp2->link = NULL;
    free(temp);
    temp = NULL;
  }
  return head;
}

struct node *reverse_list(struct node *head)
{
   /*
  Purpose : This function reverses the given linked list.
  Input : head - Pointer
         pointer that points to the linked list that has to be modified.
  Output : head - Pointer
        pointer that points to the modified linked list.
  */
  struct node *current,*prev,*next;
  current = head;
  prev = NULL;
  while(current != NULL)
  {
    next = current->link;
    current->link = prev;
    prev = current; 
    current = next;
  }
  head = prev;
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

  print(head);

// Prompts the user to choose an operation to perform on the linked list

  printf("Select operations you want to perform on Linked list:\n");
  printf("[1] Insert node at END\n[2] Insert node at Beginning\n[3] Display linked list\n");
  printf("[4] Insert node at a Position\n[5] Delete node at Beginning\n");
  printf("[6] Delete node at last(select this if no of nodes is more than one)\n");
  printf("[7] Reverse the list.\n");

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
    case 4 : printf("Insert node at a position\n");
             head = add_at_pos(no_nodes,head);
             printf("Node inserted at the specified position.\n");
             print(head);
             break;
    case 5 : printf("Delete node at beginning.\n");
             head = del_node_beg(head);
             printf("Node delected succesfully.\n");
             print(head);
             break;
    case 6 : printf("Delete node at End\n");
             head = del_node_end(head);
             printf("Node deleted succesfully\n");
             print(head);
             break;
    case 7 : printf("Reverse the list\n");
             head = reverse_list(head);
             printf("The list is reversed\n");
             print(head);
             break;

    default: printf("Please choose available operations.\n");
  }

  return 0;

}
