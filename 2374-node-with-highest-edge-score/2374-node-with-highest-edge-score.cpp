class Solution {
public:
    int edgeScore(vector<int>& edges) {
        vector<long long int> hash(edges.size(),0);
        for(int i=0;i<edges.size();i++){
            hash[edges[i]]+=i;
        }
        long long int maxIn=INT_MIN,ind=0;
        for(int i=0;i<hash.size();i++){
            if(hash[i]>maxIn){
                ind=i;
                maxIn=hash[i];
            }
        }
        
        return ind;
    }
};