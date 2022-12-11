//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define ll long long

pair<long long, long long> getMinMax(long long a[], int n) ;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll a[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        pair<ll, ll> pp = getMinMax(a, n);

        cout << pp.first << " " << pp.second << endl;
    }
    return 0;
}
// } Driver Code Ends

#define ll long long
pair<long long, long long> getMinMax(long long a[], int n) {
    ll mini=INT_MAX;
    ll maxi=INT_MIN;
    for(int i=0;i<n;i++){
        mini=min(a[i],mini);
        maxi=max(a[i],maxi);
    }
    pair<ll,ll> ans;
    ans.first=mini;
    ans.second =maxi;
    return ans;
    
}