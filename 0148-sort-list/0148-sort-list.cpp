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
    ListNode* sortList(ListNode* head) {
        if(head==NULL)return NULL;
        vector<int> ans;
        ListNode* t;
        t=head;
        while(t!=NULL){
            ans.emplace_back(t->val);
            t=t->next;
        }
        sort(ans.begin(),ans.end());
        ListNode* last;
        head->val=ans[0];
        last=head;
        for(int i=1;i<ans.size();i++){
            ListNode *t=new ListNode;
            t->val=ans[i];
            last->next=t;
            t->next=NULL;
            last=t;
        }
        return head;
    }
};