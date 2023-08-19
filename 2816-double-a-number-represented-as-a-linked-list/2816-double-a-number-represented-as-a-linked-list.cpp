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
    ListNode* reverseLinkedList(ListNode* head){
        ListNode * curr=head;
        ListNode* prev=NULL;
        ListNode *n=NULL;
        while(curr!=NULL){
            n = curr->next;
            curr->next=prev;
            prev=curr;
            curr=n;
        }
        head=prev;
        return head;
    }
    ListNode* doubleIt(ListNode* head) {
        ListNode * rhead=reverseLinkedList(head);
        ListNode *ans=new ListNode();
        ListNode *last=ans;
        int carry=0;
        while(rhead!=NULL){
            int mul=rhead->val *2+carry;
            int pro=mul%10;
            carry=mul/10;
            ListNode*t=new ListNode(pro);
            last->next=t;
            last=t;
            rhead=rhead->next;
        }
        if(carry){
            last->next=new ListNode(carry);
        }
        return reverseLinkedList(ans->next);
    }
};