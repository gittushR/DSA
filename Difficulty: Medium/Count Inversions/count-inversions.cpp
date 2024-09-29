//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long merge(vector<long long> &arr, int low,int mid, int high){
        vector<int> temp;
        long long count=0;
        int left=low,right=mid+1;
        while(left<=mid and right<=high){
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left]);
                left++;
            }else{
                temp.push_back(arr[right]);
                right++;
                count+=mid-left+1;
            }
        }
        while(left<=mid){
            temp.push_back(arr[left]);
            left++;
        }
        while(right<=high){
            temp.push_back(arr[right]);
            right++;
        }
        for(int i=low;i<=high;i++){
            arr[i]=temp[i-low];
        }
        return count;
    }
    long long mergeSort(vector<long long> &arr, int low, int high){
        long long ans=0;
        if(low>=high)return ans;
        int mid = low + (high-low)/2;
        ans+=mergeSort(arr,low,mid);
        ans+=mergeSort(arr, mid+1,high);
        ans+=merge(arr,low,mid,high);
        return ans;
    }
    long long int inversionCount(vector<long long> &arr) {
        // Your Code Here
        int n=arr.size();
        return mergeSort(arr,0,n-1);
    }
};

//{ Driver Code Starts.

int main() {

    long long T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<long long> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        long long num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
    }

    return 0;
}

// } Driver Code Ends