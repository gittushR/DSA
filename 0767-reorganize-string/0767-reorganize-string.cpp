class Solution {
public:
    string reorganizeString(string str) {
        unordered_map<char,int> mp;
        for(int i=0;i<str.size();i++){
            mp[str[i]]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto [v,f] : mp){
            pq.push({f,v});
        }
        string ans="";
        while(pq.size()>=2){
            auto it1=pq.top();pq.pop();
            auto it2=pq.top();pq.pop();
            char ch1=it1.second;int freq1=it1.first;
            char ch2=it2.second;int freq2=it2.first;
            ans+=ch1;
            ans+=ch2;
            if (--freq1 > 0) pq.push({freq1, ch1});
            if (--freq2 > 0) pq.push({freq2, ch2});
        }
        if (!pq.empty()) {
            auto [freq, ch] = pq.top();
            if (freq > 1) return "";
            ans += ch;
        }
        return ans;
        // stack<char> st1,st2;
        // string ans="";
        // int ind=1;int n=str.size();
        // st1.push(str[0]);
        // while(ind!=n){
        //     if(str[ind]==st1.top()){
        //         st2.push(str[ind]);
        //         ind++;
        //     }else{
        //         st1.push(str[ind]);
        //         ind++;
        //         char ch=st2.top();
        //         st2.pop();
        //         st1.push(ch);
        //     }
        // }
        // if(!st2.empty())return "";
        // while(!st1.empty()){
        //     ans+=st1.top();
        //     st1.pop();
        // }
        // // cout<<ans<<"***";
        // return ans;
    }
};