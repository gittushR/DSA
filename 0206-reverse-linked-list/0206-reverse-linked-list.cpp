/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 ListNode* dummyNode=NULL;
        ListNode *nextt;
        while(head!=NULL){
            nextt=head->next;
            head->next=dummyNode;
            dummyNode=head;
            head=nextt;
        }
        return dummyNode;
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev=NULL;
        ListNode* front;
        while(head!=NULL){
            front=head->next;
            head->next=prev;
            prev=head;
            head=front;
        }
        return prev;
    }
};