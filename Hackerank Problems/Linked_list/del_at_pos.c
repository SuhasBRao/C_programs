/*
This program consists the solution for the hackerrank problem given below
->https://www.hackerrank.com/challenges/delete-a-node-from-a-linked-list/problem
*/
SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* head, int position) {

    SinglyLinkedListNode* temp = NULL;
    SinglyLinkedListNode* ptr = head;
    if (position == 0)
    {
        //ptr = ptr->next;
        head = ptr->next;
        free(ptr);
    }
    else {
        for(int i = 0; i<position - 1; i++)
        {
            ptr = ptr->next;
        }
        temp = ptr->next;
        ptr->next = temp->next;
        free(temp);    
    }

    return head;

}
