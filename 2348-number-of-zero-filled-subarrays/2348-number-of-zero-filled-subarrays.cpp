class Solution {
public:
    long long zeroFilledSubarray(vector<int>& a) {
       int n=a.size(); 
      long long total=0;
       for(int i=0;i<n;i++)
       {
          if(a[i]==0)
          {
              int j=i+1;
              while(j<n&&a[j]==0)
              j++;
              long long cnt1=(j-i);
              total+=((cnt1*(cnt1+1))/2);
              i=j;
          }
       }
       return total;
    }
};