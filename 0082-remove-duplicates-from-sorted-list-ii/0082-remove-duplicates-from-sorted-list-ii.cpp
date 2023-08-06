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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)return NULL;
        map<int,int> mp;ListNode *t=head;
        while(t!=NULL){
            mp[t->val]++;
            t=t->next;
        }
        vector<int> dist;
        for(auto [k,v]:mp){
            if(v==1)dist.push_back(k);
        }
        if(dist.size()==0)return NULL;
        head->val=dist[0];
        head->next=NULL;
        ListNode* last=head;
        for(int i=1;i<dist.size();i++){
            ListNode *t=new ListNode(dist[i]);
            last->next=t;
            last=t;
        }
        return head;
    }
};