class Solution {
public:
    int a[51]={0};
    int tribonacci(int n) {
        if( a[n]) return a[n]; 
        if( n==0)return  0;
        if(n==1)return 1;
        if( n==2)return 1;
        return a[n]= tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);
    }
};