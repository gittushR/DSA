//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool checkSorted(vector<int> &nums) {
        // code here.
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]==i+1)continue;
            swap(nums[i],nums[nums[i]-1]);
            count++;
        }
       bool flag=true;
       for(int i=0;i<n-1;i++){
           if(nums[i]>nums[i+1])flag=false;
       }
       return (count<=2 && flag==true);
    } 
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        vector<int> arr;
        while (ss >> num)
            arr.push_back(num);

        Solution ob;
        bool ans = ob.checkSorted(arr);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
}

// } Driver Code Ends