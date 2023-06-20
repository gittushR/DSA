//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        int sum=0;
        int a=0;
        int i=0;
        vector<int> arr1;
        vector<int> arr2;
        arr2.push_back(-1);
        while(i<=n){
        if (sum == s) {
            arr1.push_back(a + 1);
            arr1.push_back(i);
            break;
        }  if (sum > s) {
            sum -= arr[a];
            a++;
            
        } else {
            sum += arr[i++];
        }
    }
    if(sum==s and sum!=0)
        return arr1;
        else
        return arr2;
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
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends