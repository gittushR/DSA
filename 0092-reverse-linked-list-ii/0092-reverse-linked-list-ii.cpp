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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right)return head;
        int k=right-left+1;
        ListNode *start=head;
        ListNode*rhead=NULL;
        while(left!=1){
            rhead=start;
            start=start->next;
            left--;
        }
        ListNode *prev=NULL;
        ListNode *current=start;
        ListNode *temp;
        int cnt=1;
        while(current!=NULL&&cnt<=k){
            temp=current->next;
            current->next=prev;
            prev=current;
            current=temp;
            cnt++;
        }
        if(start==head){
            start->next=temp;
            head=prev;
            return head;
        }
        rhead->next=prev;
        start->next=temp;
        return head;
    }
};