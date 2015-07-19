/*
    build a bst with its inorder and postorder tranversal

*/
#include "basic.h"

// itertive edition
ListNode* iter_reverse(ListNode *head){
    ListNode *begin = new ListNode(INT_MIN);
    begin->next = head;
    ListNode *tmp = NULL;
    while(head->next){
        tmp = head->next;
        head->next = tmp->next;
        tmp->next = begin->next;
        begin->next = tmp;
    }
    return begin->next;
}

// recursive solution
ListNode* rec_reverse(ListNode *head){
	if(head->next == NULL)
		return head;
	ListNode *newhead = rec_reverse(head->next);
	ListNode *tmp = newhead;
	while(tmp->next)
		tmp = tmp->next;
	tmp->next = head;
	head->next = NULL;
	return newhead;
}


int main(int argc, char* argv[]){
    int x[] = {5,4,3,2,1};
    int len = sizeof(x)/sizeof(x[0]);
    ListNode *a = getList(x,len);
    print(a);
    /*ListNode *b = iter_reverse(a);
    print(b);*/
    ListNode *c = rec_reverse(a);
    print(c);
}