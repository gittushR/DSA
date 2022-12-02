class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.size();       //to store the size of word1
            int m = word2.size();       //to store the size of word2
            
            vector<int> v1;
            vector<int> v2;

            map<char, int> mp1, mp2;
            
            
            if (n != m)                 // checking wether 2 strings have same size or not
                return false;
            
            for (int i = 0; i < n; i++)    //storing char and count of each char
            {
                mp1[word1[i]]++;
            }
            for (int i = 0; i < m; i++)
            {
                mp2[word2[i]]++;
            }

            if (mp1.size() != mp2.size())   
                return false;

            map<char, int>::iterator it1 = mp1.begin();
            map<char, int>::iterator it2 = mp2.begin();

            while (it1 != mp1.end())
            {
                if (it1->first == it2->first)
                    it1++, it2++;
                else
                    return false;
            }

            for (auto i: mp1)
            {
                v1.push_back(i.second);
            }
            for (auto i: mp2)
            {
                v2.push_back(i.second);
            }

            sort(v1.begin(), v1.end());
            sort(v2.begin(), v2.end());

            if (v1 == v2)
                return true;
            return false;
        
    }
};