#define ll long long
class Solution {
public:
    long long sttoLL(string n){
        long long i = 0;
        for (char c : n){
            i = i * 10 + (c - '0');
        }
        return i;
    }
    string nearestPalindromic(string s) {
        long long num=sttoLL(s);
        ll digits=0,n=num;
        while(n){
            digits++;
            n/=10;
        }
        vector<ll>candidates={(ll)pow(10,digits)+1,(ll)pow(10,digits)-1,
        (ll)pow(10,digits-1)+1,(ll)pow(10,digits-1)-1};
        ll mid=(digits+1)/2;
        ll prefix=num/(ll)(pow(10,digits-mid));
        vector<ll>v={prefix,prefix-1,prefix+1};
        for(auto i:v){
            string s=to_string(i);
            if(digits%2!=0)
                s.pop_back();
            reverse(s.begin(),s.end());
            string c=to_string(i)+s;
            candidates.push_back(stoll(c));
        }
        long long int res=INT_MAX;
        long long int minDiff = INT_MAX;
        for(auto i : candidates){
            if(i==num)continue;
            if(abs(num - i) == minDiff ){
                res = min (i, res);
            }
            if(abs(num - i) < minDiff){
                minDiff = abs(num- i);
                res = i;
            }
        }
        // cout<<res<<endl;
        return to_string(res);
    }
};