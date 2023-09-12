// class Solution {
// public:
//     int lowerBound(int i , vector<int> &freq){
//         return freq[freq.begin()-lower_bound(freq.begin(),freq.end(),i)];
//     }
    
//     int minDeletions(string s) {
//         vector<int> missingFreq;
//         missingFreq.push_back(0);
//         vector<int> freq;
//         map<int,int> mp;
//         for(auto it:s)mp[it]++;
//         for(auto it:mp){
//             freq.push_back(it.second);
//         }
//         int max_freq=freq[freq.size()-1];
//         for(int i=1;i<max_freq;i++){
//             if(lowerBound(i,freq)!=i){
//                 missingFreq.push_back(i);
//             }
//         }
//         int ans=0;
//         int ind1=missingFreq.size()-1;
//         for(int i=1;i<freq.size();i++){
//             if(freq[i]==freq[i-1]){
//                 ans+=freq[i]-missingFreq[ind1];
//                 ind1--;
//             }
//         }
//         return ans;
//     }
// };
class Solution {
public:
    int minDeletions(string s) {
      vector<int> freq(26, 0);
      for(char it : s) freq[it-'a']++;
      sort(freq.begin(), freq.end());
      stack<int> a;
      a.push(0);
      int j=0, ans=0;
      for(int i=1; i<=freq[25]; i++){
        while(freq[j]==0) j++;
        if(i<freq[j]){
          a.push(i);
        }
        else{
          while(j<25 and freq[j]==freq[j+1]){
            ans+=freq[j]-a.top();
            if(a.top()) a.pop();
            j++;
          }
          if(i==freq[j]) j++;
        }
      }
      return ans;        
    }
};