//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        unordered_map<int,int> mp;
        int n=arr.size(),i=0,j=0;
        int maxLength=0;
        while(j<n){
            mp[arr[j]]++;
            if(mp.size()<=2){
                maxLength= max(maxLength,(j-i+1));
            }else{
                while(mp.size()>2){
                    mp[arr[i]]--;
                    if(mp[arr[i]]==0)mp.erase(arr[i]);
                    i++;
                }
            }
            j++;
        }
        return maxLength;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        int ans = ob.totalElements(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends