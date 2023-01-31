class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.size();
        for(int l=n/2;l>0;l--)
        {
            int i=0;
            if(n%l==0)
            {
                while(i+l<n and s[i]==s[i+l])
            i++;
            if(i+l==n)
            return true;
            }
        }
        return false;
    }
};