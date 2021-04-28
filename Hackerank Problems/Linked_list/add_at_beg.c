/*
This program implements solution to the following hackerrank problem
->https://www.hackerrank.com/challenges/insert-a-node-at-the-head-of-a-linked-list/problem?h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen
*/
SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* llist, int data) {

    SinglyLinkedListNode *temp = malloc(sizeof(SinglyLinkedListNode));
    temp->data = data;
    temp->next = NULL;

    if(llist == NULL)
    {
        llist = temp;
    }
    else
    {
        temp->next = llist;
        llist = temp;
    }

    return llist;

}
