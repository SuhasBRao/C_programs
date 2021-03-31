/*
Purpose: This program searches for the maximum element in the given list/array.
         Dynamic array has been used so that the array size depends on the user input.
         Also it ensures that the memory is utilized efficiently.

Inputs: [1] Number of elements in the array
        [2] Array elements.

Output: [1] Maximum element position
        [2] Maximum element
*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
  int num, max_element, indx = -1;
  int *array = NULL;

  printf("Enter the number of elements in the array: ");
  scanf("%d", &num);
  printf("Enter the elements\n");

  array = malloc(num * (sizeof(int)));

  for(int i = 0 ; i<num; i++)
  {
    printf("Enter element %d \n",i+1);
    scanf("%d",&array[i]);
  }
  max_element = array[0];
  for(int i = 0; i<num; i++)
  {
    if(array[i] >= max_element)
    {
      max_element = array[i];
      indx = i;
    }
  }
  printf("#############################\n");
  printf("max element is at: %d \nmax value is: %d\n",indx + 1,max_element);

}
