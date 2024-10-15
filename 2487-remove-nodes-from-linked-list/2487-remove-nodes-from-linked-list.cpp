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
    ListNode* removeNodes(ListNode* h) {
        vector<int> arr;
        while(h!=NULL){
            arr.push_back(h->val);
            h=h->next;
        }
        int n=arr.size();
        stack<int> st;
        st.push(arr[n-1]);
        for(int i=n-2;i>=0;i--){
            if(arr[i]>=st.top()){
                st.push(arr[i]);
            }
        }
        ListNode* head=new ListNode();
        head->val=st.top();
        ListNode* curr=head;
        curr->next=NULL;
        st.pop();
        while(!st.empty()){
            curr->next=new ListNode(st.top());
            st.pop();
            curr=curr->next;
        }
        return head;
    }
};