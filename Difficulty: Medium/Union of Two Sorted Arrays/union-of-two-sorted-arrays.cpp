//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        //Your code here
        //return vector with correct order of elements
        vector<int> ans;
        int n1=0,n2=0;
        while(n1<n and n2<m){
            if(ans.size()!=0 and arr1[n1] == ans.back()){n1++;continue;}
            if(ans.size()!=0 and arr2[n2] == ans.back()){n2++;continue;}
            if(arr1[n1]==arr2[n2]){
                ans.push_back(arr1[n1]);
                n1++;n2++;
            }else if (arr1[n1]<arr2[n2]){
                ans.push_back(arr1[n1]);
                n1++;
            }else{
                ans.push_back(arr2[n2]);
                n2++;
            }
        }
        while(n1<n){
            if(ans.size()!=0 and arr1[n1] == ans.back()){n1++;continue;}
            ans.push_back(arr1[n1]);n1++;
        }
        while(n2<m){
            if(ans.size()!=0 and arr2[n2] == ans.back()){n2++;continue;}
            ans.push_back(arr2[n2]);n2++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--){
	    
	    
	    
	    int N, M;
	    cin >>N >> M;
	    
	    int arr1[N];
	    int arr2[M];
	    
	    for(int i = 0;i<N;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<M;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findUnion(arr1,arr2, N, M);
	    for(int i: ans)cout<<i<<' ';
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends