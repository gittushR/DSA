class Solution {
public:
    vector<string> splitWords(string sen){
        stringstream ss(sen);
        string word;
        vector<string> words;
        while (ss >> word) words.push_back(word);
        ss.clear();
        return words;
    }
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> words1 = splitWords(sentence1);
        vector<string> words2 = splitWords(sentence2);
        if(words1.size() < words2.size()) swap(words1, words2);
        int n1 = words1.size(), n2 = words2.size();
        int start = 0, end1 = n1-1,end2=n2-1;
        
        while(start<n2 and words1[start]==words2[start])start++;
        // cout<<"Here";
        cout<<end1<<"::::"<<end2<<endl;
        while(end2>=0 and words1[end1]==words2[end2]){
            end1--;
            end2--;
        }
        
        if(start>end2)return true;
        else return false;
    }
};