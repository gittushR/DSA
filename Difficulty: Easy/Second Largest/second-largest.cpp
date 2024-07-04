//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    int print2largest(vector<int> &arr) {
        if(arr.size()<2)return -1;
        // Code Here
        int n1,n2;
        n1=arr[0];n2=arr[1];
        for(int i=0;i<arr.size();i++){
            if(arr[i]>n1){
                n2=n1;
                n1=arr[i];
            }else if(arr[i]<n1 and arr[i]>n2){
                n2=arr[i];
            }
        }
        return n2;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.print2largest(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends