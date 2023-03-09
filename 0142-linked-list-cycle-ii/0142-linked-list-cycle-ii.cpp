/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL)return NULL;
        if(!head->next)return NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        
        bool flag=true;
        while(true){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast || !fast || !fast->next ){
                break;
            }  
        }
        if(!fast||!fast->next){
            return NULL;
        }
        else{
        slow=head;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
        }
    }
};