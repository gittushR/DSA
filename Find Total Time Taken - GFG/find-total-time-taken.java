//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.io.*;

class GFG {
    public static void main(String args[])throws IOException
    {
        BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out=new PrintWriter(System.out);
        int t=Integer.parseInt(in.readLine());
        while(t-->0){
            
            int n=Integer.parseInt(in.readLine().trim());
            int a[]=new int[n];
            String s[]=in.readLine().trim().split(" ");
            for(int i=0;i<n;i++){
                a[i]=Integer.parseInt(s[i]);
            }
            s=in.readLine().trim().split(" ");
            int time[]=new int[n];
            for(int i=0;i<n;i++){
                time[i]=Integer.parseInt(s[i]);
            }
            Solution ob=new Solution();
            long ans=ob.totalTime(n,a,time);
            out.println(ans);
        }
        out.close();
    }
}

// } Driver Code Ends


//User function Template for Java

class Solution
{
    public static long totalTime(int n,int arr[],int time[])
    {  
       int result=0;
        int count[]=new int[n+1];
       for(int i=0;i<n;i++)
       {
          if(i==0)
          { 
            count[arr[i]]++;
            result=0;  
          }
          else
          {
             if((searching(count,arr[i]))==true)
             {
                 count[arr[i]]++;
                 result++;
             }
             else
             {
                 result=result+time[arr[i]-1];
             }
          }
       }
       return result;
    }
    public static boolean searching(int count[],int elem)
    {
       if(count[elem]==0)
       {
           return true;
       }
      
       return false;
    }
    
}