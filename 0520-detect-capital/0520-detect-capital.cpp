class Solution {
public:
    bool detectCapitalUse(string word) {
        int capitals = 0;

        for (int i = 1; i < word.size(); i++) {
            if (isupper(word[i])) {
                capitals++;
            }
        }
        
        return capitals == 0 || capitals == word.size() - 1 && isupper(word[0]);
    }
};