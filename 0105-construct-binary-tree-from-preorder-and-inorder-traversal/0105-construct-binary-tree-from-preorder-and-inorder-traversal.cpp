class Solution {
public:
    TreeNode* helper(vector<int> pre,vector<int> in,int preS, int preE,int inS, int inE ){
        if(inS>inE)return NULL;
        int rootData=pre[preS];
        int rootIndex=-1;
        for(int i=inS;i<=inE;i++){
            if(in[i]==rootData){
                rootIndex=i;
                break;
            }
        }
        int leftInS=inS;
        int leftInE=rootIndex-1;
        int leftPreS=preS+1;;
        int leftPreE=leftPreS+leftInE-leftInS;
        
        int rightInS=rootIndex+1;
        int rightInE=inE;
        int rightPreS=leftPreE+1;
        int rightPreE=preE;
        
        TreeNode *root=new TreeNode(rootData);
        root->left=helper(pre,in,leftPreS,leftPreE,leftInS,leftInE);
        root->right=helper(pre,in,rightPreS,rightPreE,rightInS,rightInE);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        return helper(preorder,inorder,0,n-1,0,n-1);
    }
};