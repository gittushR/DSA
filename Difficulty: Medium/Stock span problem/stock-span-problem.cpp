//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void pge(vector<int> &prevGreatest, vector<int> &arr){
        stack<int> st;
        for(int i=0;i<arr.size();i++){
            while(st.size() and arr[i]>=arr[st.top()]){
                st.pop();
            }
            prevGreatest[i]=st.size()?st.top():-1;
            st.push(i);
        }
    }
    vector<int> calculateSpan(vector<int>& arr) {
        // write code here
        int n=arr.size();
        vector<int> prevGreatest(n);
        pge(prevGreatest, arr);
        vector<int> ans(n);
        for(int i=0;i<arr.size();i++){
            //cout<<prevGreatest[i]<<" "<<i<<endl;
            ans[i]=i-prevGreatest[i];
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> ans = obj.calculateSpan(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends