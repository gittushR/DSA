#User function Template for python3

class Solution:
    def maxSumBS(self, arr):
        # code here
        dp1,dp2 = [0] * len(arr) ,[0] * len(arr)
        n = len(arr)
        for ind in range(len(arr)):
            val=0
            for prev in range(ind):
                if arr[ind]>arr[prev]:
                    val = max(val,dp1[prev])
            dp1[ind]= arr[ind]+val
        
        for ind in range(n-1,-1,-1):
            val=0
            for prev in range(n-1,ind,-1):
                if arr[ind]>arr[prev]:
                    val = max(val,dp2[prev])
            dp2[ind]=arr[ind]+val
        
        ans = 0
        for i in range(len(arr)):
            ans = max(ans,dp1[i]+dp2[i]-arr[i])
        
        return ans

#{ 
 # Driver Code Starts
if __name__ == "__main__":
    t = int(input().strip())
    for _ in range(t):
        nums = list(map(int, input().strip().split()))
        ob = Solution()
        res = ob.maxSumBS(nums)
        print(res)
        print("~")

# } Driver Code Ends