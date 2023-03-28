//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/

class Solution {
public:
    Node* helper(int pre[],int in[],int preS, int preE,int inS, int inE ){
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
        
        Node *root=new Node(rootData);
        root->left=helper(pre,in,leftPreS,leftPreE,leftInS,leftInE);
        root->right=helper(pre,in,rightPreS,rightPreE,rightInS,rightInE);
        return root;
    }
    Node* buildTree(int in[],int pre[], int n) {
        return helper(pre,in,0,n-1,0,n-1);
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends