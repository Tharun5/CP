/*
  Refer: https://leetcode.com/problems/merge-two-sorted-lists/discuss/1826666/C%2B%2B-oror-Easy-To-Understand-oror-2-Approaches-oror-Recursive-oror-Iterative
  Problem: https://leetcode.com/problems/merge-two-sorted-lists/submissions/
  Time: O(m+n)
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *temp,*res;
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        
        res=list1;
        if(list1->val > list2->val){
            res=list2;
            list2=list2->next;
        }else{
            list1=list1->next;
        }
        temp=res;
        
        while(list1!=NULL && list2!=NULL){
            if(list1->val < list2->val){
                temp->next=list1;
                list1=list1->next;
            }else{
                temp->next=list2;
                list2=list2->next;
            }
            temp=temp->next;
        }
        
        if(list1!=NULL){
            temp->next=list1;
        }
        if(list2!=NULL){
            temp->next=list2;
        }
        
        
        return res;
    }
};
