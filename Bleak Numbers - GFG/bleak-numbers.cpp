//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int countSetBits(int n){
        int cnt=0;
        while(n>0){
            cnt+=n&1;
            n=n/2;
        }
        return cnt;
    }
	int is_bleak(int n)
	{
	    // Code here.
	    /* n-30 because basically here we are checking if if any number x+csb(x)==n. 
	    now number od set bits in a number is equal to log of that number. 
	    so maximum numner of set bits that can occur in this question is log(1e9)~=29.8.x+[1 to 30]=n. 
	    Therefore x has a range of [n-30 to n-1]*/
	    for(int i=n-30;i<=n-1;i++){
	        if(i+countSetBits(i)==n)return 0;
	    }
	    return 1;
	}
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	Solution ob;
    	int ans = ob.is_bleak(n);
    	cout << ans << "\n";
    }
	return 0;
}

// } Driver Code Ends