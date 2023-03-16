class Solution {
public:
    TreeNode*helper(vector<int> in, vector<int> post,int inS,int inE, int postS, int postE){
        if(inS>inE)return NULL;
        int rootData=post[postE];
        int rootIndex=-1;
        for(int i=inS;i<=inE;i++){
            if(in[i]==rootData){
                rootIndex=i;
                break;
            }
        }
        int leftInS=inS;
        int leftInE=rootIndex-1;
        int leftPostS=postS;
        int leftPostE=leftInE-leftInS+leftPostS;

        int rightInS=rootIndex+1;
        int rightInE=inE;
        int rightPostS=leftPostE +1;
        int rightPostE=postE-1;
        
        TreeNode *root=new TreeNode(rootData);
        root->left=helper(in,post,leftInS,leftInE,leftPostS,leftPostE);
        root->right=helper(in,post,rightInS,rightInE,rightPostS,rightPostE);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        return helper(inorder,postorder,0,n-1,0,n-1);
    }
};