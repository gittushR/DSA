class Solution {
public:
    string convert(string s, int numRows) { 
        string ans="";
        int n=s.length();
        if(numRows==1)
        return s;
        for(int i=0;i<numRows;i++)
        { 
            int j=i;
          while(j<n)
              { 
                  if(i==0 || i==numRows-1)
                  { 
                      ans=ans+s[j];
                     
                  }
                  else
                  { 
                      ans=ans+s[j];
                      int y=(numRows-1)*2-(2*i);
                      if((j+y)<n && j+y>=0)
                      ans=ans+s[j+y];
                      
                  }
                   j=j+(numRows-1)*2;
              }
        }
        return ans;                
    }
};