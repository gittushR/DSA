class Solution {
  public:
    int lowerBound(vector<int> &arr, int x){
        int low=0;
        int high=arr.size()-1;
        int ans=0;
        while(low<=high){
            int mid =  low + (high-low)/2;
            if(arr[mid]<=x){
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return ans;
    }
    vector<int> printKClosest(vector<int> arr, int k, int x) {
        // Code here
        if(arr.size()==1)return arr;
        
        int ind = lowerBound(arr,x);
        int ind1=arr.size()-1;
        
        if(ind+1<arr.size())ind1=ind+1;
        else{
            ind1=ind;
            ind-=1;
        }
        vector<int> ans;
        
        while(k and ind>=0 and ind1<arr.size()){
            //cout<<arr[ind]<<"astdg"<<arr[ind1]<<endl;
            if(arr[ind]==x){
                ind-=1;
                continue;
            }
            if(abs(arr[ind]-x)<abs(arr[ind1]-x)){
                ans.push_back(arr[ind]);
                ind--;
            }else{
                ans.push_back(arr[ind1]);
                ind1++;
            }
            k--;
        }
        while(k and ind>=0){
            ans.push_back(arr[ind]);
            ind--;
            k--;
        }
        while(k and ind1<arr.size()){
            ans.push_back(arr[ind1]);
            ind1++;
            k--;
        }
        return ans;
    }
};