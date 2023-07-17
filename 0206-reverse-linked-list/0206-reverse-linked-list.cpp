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
        if(!head)return NULL;
        stack<ListNode*> st;
        ListNode* t=head;
        ListNode* last=head;
        while(t!=NULL){
            st.push(t);
            last=t;
            t=t->next;
            last->next=NULL;
        }
        head=st.top();
        last=head;
        last->next=NULL;
        st.pop();
        while(!st.empty()){
            auto it =st.top();
            st.pop();
            last->next=it;
            last=it;
            it->next=NULL;
        }
        return head;
    }
};