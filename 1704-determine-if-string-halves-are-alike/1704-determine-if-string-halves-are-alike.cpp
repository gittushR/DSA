class Solution {
public:
    int count(string s){
        int c=0;
        for(int i = 0;i<s.size();i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='I' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='O' || s[i]=='U'){
                c++;
            }
        }
        return c;
    }
    bool halvesAreAlike(string s) {
        int c1= count(s.substr(0,s.size()/2));
        int c2= count(s.substr(s.size()/2,s.size()));
        return c1==c2;
        
    }
};