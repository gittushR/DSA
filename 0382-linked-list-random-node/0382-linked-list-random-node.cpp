class Solution {
public:
    vector<int> vec;
    void traverse(ListNode* root){
        if(!root) return;
        else{
            vec.push_back(root->val);
            traverse(root->next);
        }
    }
    Solution(ListNode* head) {
        traverse(head);
    }
    
    int getRandom() {
        return vec[rand()%vec.size()];
    }
};