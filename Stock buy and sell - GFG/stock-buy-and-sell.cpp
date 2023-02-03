//{ Driver Code Starts
// Program to find best buying and selling days
#include <bits/stdc++.h>

using namespace std;

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int *, int);

// Driver program to test above functions
int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, i;
        cin >> n;
        int price[n];
        for (i = 0; i < n; i++) cin >> price[i];
        // function call
        stockBuySell(price, n);
    }
    return 0;
}

// } Driver Code Ends


// User function template for C++

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int prices[], int n) {
  // code here
    int i=0;
    int totalP=0;
    while(i<n-1) {
        while(i<n-1 && prices[i]>=prices[i+1]) i++;
        int buy=i++;
        while(i<n && prices[i]>prices[i-1]) i++;
        int sell=i-1;
        if(buy!=sell)    {
            totalP+=(prices[sell]-prices[buy]);
            cout<<"("<<buy<<" "<<sell<<")"<<" ";
        }
    }
    if(totalP==0)cout<<"No Profit";
    cout<<endl;
}