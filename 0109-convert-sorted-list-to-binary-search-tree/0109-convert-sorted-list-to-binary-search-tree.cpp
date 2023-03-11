class Solution {
public:
    TreeNode* helper(vector<int> nums,int left,int right){
        if(left>right) return NULL;
        int mid=(left+right)/2;
        TreeNode *root=new TreeNode(nums[mid]);
        root->left=helper(nums,left,mid-1);
        root->right=helper(nums,mid+1,right);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        while(head!=NULL){
            nums.push_back(head->val);
            head=head->next;
        }
        return helper(nums,0,nums.size()-1);
        
    }
};