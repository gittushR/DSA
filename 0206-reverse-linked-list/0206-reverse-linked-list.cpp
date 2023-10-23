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
    ListNode* reverseList(ListNode* head) {
        ListNode* dummyNode=NULL;
        ListNode *nextt;
        while(head!=NULL){
            nextt=head->next;
            head->next=dummyNode;
            dummyNode=head;
            head=nextt;
        }
        return dummyNode;
    }
};