//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.
Node*helper(int in[],int post[],int inS,int inE, int postS, int postE){
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
        
        Node *root=new Node(rootData);
        root->left=helper(in,post,leftInS,leftInE,leftPostS,leftPostE);
        root->right=helper(in,post,rightInS,rightInE,rightPostS,rightPostE);
        return root;

}

Node *buildTree(int in[], int post[], int n) {
    // Your code here
    return helper(in,post,0,n-1,0,n-1);
}

