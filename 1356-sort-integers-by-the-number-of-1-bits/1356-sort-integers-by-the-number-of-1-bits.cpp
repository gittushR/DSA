class Solution {
public:
    int static counter(int n){
        int count=0;
        while(n){
            if(n&1)count++;
            n=n>>1;
        }
        return count;
    }
    bool static compare(int a, int b){
        if(counter(a)!=counter(b)) return (counter(a)<counter(b));
        else return a<b;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),compare);
        return arr;
    }
};