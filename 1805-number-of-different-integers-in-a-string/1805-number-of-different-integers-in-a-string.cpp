class Solution {
public:
    int numDifferentIntegers(string word) {
        int n = word.length() , i ;
        unordered_map<string,int> mp ;
        for(i=0;i<n;i++){
            string str = "" ;
            bool flag = false ;
            while(i<n && word[i]>='0' && word[i]<='9'){
                str += word[i] ;
                i++ ;
                flag = true ;
                if(str=="0"){
                    str = "" ;
                }
            }
            if(flag){
                mp[str]++;
            }
        }
        return mp.size() ;
    }
};