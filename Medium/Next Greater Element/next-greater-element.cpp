//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        vector<long long> right(n);
        right[n-1]=-1;
        stack<int> st;
        st.push(n-1);
        
        for(int i=n-2;i>=0;i--){
            while(!st.empty() and arr[st.top()]<=arr[i])st.pop();
            if(st.empty())right[i]=-1;
            else right[i]=arr[st.top()];
            st.push(i);
        }
        return right;
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
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends