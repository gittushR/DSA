class Solution {
public:
    void rotate(vector<int>& arr, int k) {
        vector<int> temp;
        int n=arr.size();
        int t=k%n;
        t=n-t;
        for(int i=0;i<t;i++)temp.push_back(arr[i]);
        for(int i=t;i<n;i++){
            arr[i-t]=arr[i];
        }
        int j=0;
        for(int i=n-t;i<n;i++){
            arr[i]=temp[j++];
        }
    }
};