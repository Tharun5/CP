//Time: O(n)
//Problem: https://leetcode.com/problems/reverse-linked-list

ListNode* reverseList(ListNode* head) {
    if(head==NULL) return NULL;
    ListNode* prev=NULL;
    ListNode *next=NULL;
    ListNode *curr=head;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
