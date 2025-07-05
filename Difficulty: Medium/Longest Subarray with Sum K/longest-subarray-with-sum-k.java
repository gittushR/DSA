// User function Template for Java

class Solution {
    public int longestSubarray(int[] arr, int k) {
        // code here
        Map<Integer,Integer> mp = new HashMap<>();
        int maxLen = 0;
        int sum = 0;
        
        for(int i=0;i<arr.length;i++){
            sum += arr[i];
            if(sum==k){
                maxLen = Math.max(maxLen,i+1);
            }
                int rem = sum - k;
                if(mp.containsKey(rem)==true){
                    int len = i - mp.get(rem);
                    maxLen=Math.max(maxLen,len);
                }
 
            if(mp.containsKey(sum)==false)mp.put(sum,i);
        }
        return maxLen;
    }
}


/*
    int lenOfLongSubarr(int arr[],  int n, int k) 
    { 
        // Complete the function
        int sum=0;
        int maxLen=0;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            int len=0;
            sum+=arr[i];
            if(sum==k){
                len=i+1;
                maxLen=max(len,maxLen);
            }
            int remSum=sum-k;
            if(mp.find(remSum)!=mp.end()){
                len=i-mp[remSum];
                maxLen=max(maxLen,len);
            }
            if(mp.find(sum)==mp.end())mp[sum]=i;
        }
        return maxLen;
    } 
*/