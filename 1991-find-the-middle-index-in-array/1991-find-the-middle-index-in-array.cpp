class Solution {
public:
    int findMiddleIndex(vector<int>& a) {
        int prevsum=0;
        int remsum=0;
        int Ts=0;
        int n=a.size();
        for(int i=0;i<n;i++)
        {
            Ts=Ts+a[i];
        }
        for(int i=0;i<n;i++)
        {
            remsum=Ts-a[i]-prevsum;
            if (prevsum==remsum)
            {
                return (i);
            }
            prevsum=prevsum+a[i];
        }
        return -1;
    }
};