//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void getMiniandMaxi(int &low, int &high, vector<int> arr){
        for(int i=0;i<arr.size();i++){
            low=min(low,arr[i]);
            high=max(high,arr[i]);
        }
    }
    bool isPossible(int day, vector<int> arr, int m, int k){
        int cnt=0,numBouq=0;
        for(int i=0;i<arr.size();i++){
            if(day>=arr[i]){
                cnt++;
            }else{
                numBouq+=cnt/k;
                cnt=0;
            }
        }
        numBouq+=cnt/k;
        if(numBouq>=m)return true;
        else return false;
    }
    int solve(int m, int k, vector<int> &bloomDay){
      // Code here
        long long total = (long long)m* (long long)k;
        if((long long)bloomDay.size()<total)return -1;
        int low=1e8,high=-1e8;
        getMiniandMaxi(low,high,bloomDay);
        int ans;
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(isPossible(mid,bloomDay,m,k)){
                ans=mid;
                high=mid-1;
            }else low=mid+1;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, k;
    cin >> m >> k;
    string s;
    getline(cin, s);
    getline(cin, s);
    int n = s.length();
    int num = 0;
    bool f = 0;
    vector<int> bloomDay;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == ' ')
      {
        if (!f)
          continue;
        bloomDay.push_back(num);
        num = 0;
        f = 0;
      }
      else
      {
        num = (num * 10) + (s[i] - '0');
        f = 1;
      }
    }
    if (f)
    {
      bloomDay.push_back(num);
    }
    Solution obj;
    cout<<obj.solve(m, k, bloomDay)<<endl;
    }
    return 0;
}
// } Driver Code Ends