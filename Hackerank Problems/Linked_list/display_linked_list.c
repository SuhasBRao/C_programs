/*
This program implements solution to the below hackerrank problem
->https://www.hackerrank.com/challenges/print-the-elements-of-a-linked-list/problem
*/
void printLinkedList(SinglyLinkedListNode* head)
{
    SinglyLinkedListNode *ptr = head;
    if(head == NULL)
    {
        return;
    }
    else
    {
        while(ptr != NULL)
        {
            printf("%d\n",ptr->data);
            ptr = ptr->next;
        }
    }
}
