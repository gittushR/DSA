// User function Template for Java

// a,b : the arrays
class Solution {
    // Function to return a list containing the union of the two arrays.
    public static ArrayList<Integer> findUnion(int a[], int b[]) {
        // add your code here
        int n = a.length;
        int m = b.length;
        
        int ind1=0,ind2=0;
        
        ArrayList<Integer> ans = new ArrayList<>();
        
        while(ind1<n && ind2<m){
            if(ans.size() > 0 && ans.get(ans.size()-1)==a[ind1]){
                ind1++;
                continue;
            }
            if(ans.size() > 0 && ans.get(ans.size()-1)==b[ind2]){
                ind2++;
                continue;
            }
            if(a[ind1]<b[ind2]){
                ans.add(a[ind1]);
                ind1++;
            }else if(a[ind1]>b[ind2]){
                ans.add(b[ind2]);
                ind2++;
            }else{
                ans.add(a[ind1]);
                ind1++;
                ind2++;
            }
        }
        while(ind1<n){
            if(ans.size() > 0 && ans.get(ans.size()-1)==a[ind1]){
                ind1++;
                continue;
            }
            ans.add(a[ind1]);
        }
        while(ind2<m){
            if(ans.size() > 0 && ans.get(ans.size()-1)==b[ind2]){
                ind2++;
                continue;
            }
            ans.add(b[ind2]);
        }
        return ans;
    }
}
