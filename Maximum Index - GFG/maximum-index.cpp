//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int A[], int N) {
       int left[N];
       int right[N];
       left[0]=A[0];
       right[N-1]=A[N-1];
       for(int i=1;i<N;i++){
           left[i]=min(left[i-1],A[i]);
       }
       for(int i=N-2;i>=0;i--){
           right[i]=max(right[i+1],A[i]);
       }
       int maxi=INT_MIN;
       int i=0,j=0;
       
       while(i<N&&j<N){
           if(left[i]<=right[j]){
               maxi=max(maxi,j-i);
               j++;
           }
           else{
           i++;
           }
       }
       return maxi;
    }
};

//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends