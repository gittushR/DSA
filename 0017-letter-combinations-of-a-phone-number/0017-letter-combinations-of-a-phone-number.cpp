class Solution {
    vector<string> vt = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
    
    void helper(int idx, string &digits, string &till){
        if(idx==digits.size()){
            if(!till.empty()) ans.push_back(till);
            return;
        }
        int id = digits[idx]-'0';
        for(int i=0; i<vt[id].size(); i++){
            till.push_back(vt[id][i]);
            helper(idx+1, digits, till);
            till.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        string till = "";
        helper(0, digits, till);
        return ans;
    }
};
