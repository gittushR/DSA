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
    void putintoTemp(vector<int>&temp,ListNode *head){
        if(!head)return;
        while(head!=NULL){
            temp.push_back(head->val);
            head=head->next;
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> temp;
        if(lists.size()==0)return NULL;
        for(int i=0;i<lists.size();i++){
            putintoTemp(temp,lists[i]);
        }
        if(temp.size()==0)return NULL;
        sort(temp.begin(),temp.end());
        ListNode *first=new ListNode(temp[0]);
        ListNode *last=first;
        last->next=NULL;
        for(int i=1;i<temp.size();i++){
            ListNode *t=new ListNode(temp[i]);
            last->next=t;
            last=t;
            last->next=NULL;
        }
        return first;
        
    }
};