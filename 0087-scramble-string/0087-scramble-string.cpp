class Solution {
public:
    map <string, bool> mp;
    bool isScramble(string s1, string s2) {
        if (mp.find(s1 + s2) == mp.end()) {
            if (s1 == s2) {
                mp[s1 + s2] = true;
                return true;
            }
            vector <int> h1(26, 0), h2(26, 0), h3(26, 0);
            int n = s1.length(), i;
            for (i=0;i<n-1;i++) {
                h1[s1[i] - 'a']++;
                h2[s2[i] - 'a']++;
                h3[s2[n-i-1] - 'a']++;
                if (h1 == h2) {
                    if (isScramble(s1.substr(0, i+1), s2.substr(0, i+1)) && isScramble(s1.substr(i+1), s2.substr(i+1))) {
                        mp[s1 + s2] = true;
                        return true;
                    }
                }
                if (h1 == h3) {
                    if (isScramble(s1.substr(0, i+1), s2.substr(n-i-1)) && isScramble(s1.substr(i+1), s2.substr(0, n-i-1))) {
                        mp[s1 + s2] = true;
                        return true;
                    }
                }
            }
            mp[s1 + s2] = false;
        }
        return mp[s1 + s2];
    }
};