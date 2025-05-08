#{ 
 # Driver Code Starts
#Initial Template for Python 3
import sys


# } Driver Code Ends

#User function Template for python3
class Solution:
    def minCost(self, height):
        # code here\
        n = len(height)
        memo = [-1] * n

        def fn(ind):
            if ind==0:
                return 0
            if memo[ind]!=-1:
                return memo[ind]
            oneStep = abs(height[ind]-height[ind-1]) + fn(ind-1)
            twoStep = 1e8
            if ind>=2:
                twoStep =  abs(height[ind]-height[ind-2]) + fn(ind-2)
            memo[ind]= min(oneStep,twoStep)
            return memo[ind]
            
            
        return fn(n-1)


#{ 
 # Driver Code Starts.

if __name__ == "__main__":
    input_lines = sys.stdin.read().splitlines()
    
    pointer = 0
    
    t = int(input_lines[pointer].strip())
    pointer += 1
    
    for _ in range(t):
        arr = list(map(int, input_lines[pointer].strip().split()))
        pointer += 1
        
        ob = Solution()
        print(ob.minCost(arr))
        print("~")

# } Driver Code Ends