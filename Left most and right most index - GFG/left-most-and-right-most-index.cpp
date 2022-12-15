//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    pair<long,long> indexes(vector<long long> v, long long x)
    {
        // code here
        int start=0,end=v.size()-1;
        int mid=start+(end-start)/2;
        int ans1=-1,ans2=-1;
        while(start<=end){
            if(v[mid]==x){
                ans1=mid;
                end=mid-1;
            }
            else if(v[mid]>x){
                end=mid-1;
            }else{
                start=mid+1;
            }
            mid=start+(end-start)/2;
        }
        start=0;
        end=v.size()-1;
        mid=start+(end-start)/2;
        while(start<=end){
            if(v[mid]==x){
                ans2=mid;
                start=mid+1;
            }
            else if(v[mid]>x){
                end=mid-1;
            }else{
                start=mid+1;
            }
            mid=start+(end-start)/2;
        }
        pair<int, int> ans;
        ans.first=ans1;
        ans.second=ans2;
        return ans;
        
    }
};

//{ Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        vector<long long>v;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cin>>x;
        Solution obj;
        pair<long,long> pair = obj.indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;

    }
	return 0;
}

// } Driver Code Ends