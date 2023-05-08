//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t;
        t = Integer.parseInt(br.readLine());
        while(t-- > 0){
            
            String str;
            str = br.readLine();
            
            Solution obj = new Solution();
            String res = obj.stringMirror(str);
            
            System.out.println(res);
            
        }
    }
}

// } Driver Code Ends


class Solution {
    public static String stringMirror(String str) {
        // code here
        int k = 0;
        
        if(str.length() == 1 || str.charAt(0) == str.charAt(1))return str.substring(0,1) + str.substring(0,1) ;

        while(k <str.length() -1  && str.charAt(k+1) <= str.charAt(k) ) k++;
        
        String s1 = str.substring(0, k+1);
        String s2 = "";
        
        //reverse
        for(int i = 0; i<s1.length(); i++) s2 = s1.charAt(i) + s2;
        
        return s1+s2;
    }
}
        
