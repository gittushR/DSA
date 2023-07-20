class Solution {
public:
    bool find(string s, string temp, int k){
        int j=0,count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==temp[j]){
                j++;
                if(j==temp.size()){
                    count++;
                    j=0;
                    if(count==k){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    string longestSubsequenceRepeatedK(string s, int k) {
        int alphabet=26;
        queue<string> q;
        q.push("");
        string ans="";
        while(!q.empty()){
            string curr=q.front();
            q.pop();
            for(int i=0;i<alphabet;i++){
                string temp=curr+char('a'+i);
                if(find(s, temp, k)){
                    ans=temp;
                    q.push(temp);
                }
            }
        }
        return ans;
    }
};