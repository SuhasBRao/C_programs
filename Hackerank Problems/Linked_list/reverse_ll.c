/*
This c program implements the solution for the given hackerrank problem
->https://www.hackerrank.com/challenges/reverse-a-linked-list/problem?h_r=next-challenge&h_v=zen
*/
SinglyLinkedListNode* reverse(SinglyLinkedListNode* head) {

    SinglyLinkedListNode *cur;
    SinglyLinkedListNode *prev;
    SinglyLinkedListNode *nxt;
    prev = NULL;
    cur = head;
    //printf("%d",cur->data);
    while(cur != NULL)
    {
        //printf("y");
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    head = prev;
    return head;
}
