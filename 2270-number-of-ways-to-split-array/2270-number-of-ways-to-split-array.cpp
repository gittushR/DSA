class Solution {
public:
    int waysToSplitArray(vector<int>& a) {
        long long int prevsum=0;
        long long int remsum=0;
        long long int Ts=0;
        int n=a.size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            Ts=Ts+a[i];
        }
        prevsum=prevsum+a[0];
        for(int i=1;i<n;i++)
        {
            remsum=Ts-prevsum;
            if (prevsum>=remsum)
            {
                count++;
            }
            prevsum=prevsum+a[i];
        }
        return count;
    }
};