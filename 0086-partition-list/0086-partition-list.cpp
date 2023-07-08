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
    ListNode* partition(ListNode* head, int x) {
        ListNode* left = new ListNode();
        ListNode* right = new ListNode();
        ListNode* head1 = left;
        ListNode* head2 = right;
        ListNode* curr = head;
        while(curr!=NULL){
            if(curr->val>=x){
                right->next = curr;
                right = right->next;
                curr = curr->next;
            }
            else{
                left->next = curr; 
                left= left->next;
                curr = curr->next;
            }
        }
        left->next = head2->next;
        right->next = NULL;
        return head1->next;

    }
};