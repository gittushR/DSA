class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto it: stones){
            pq.push(it);
        }
        while(pq.size()>1){
            int a=pq.top();
            pq.pop();
            int b=pq.top();
            pq.pop();
            if(a==b)continue;
            else{
                pq.push(a-b);
            }
        }
        if(pq.size()==1)return pq.top();
        else return 0;
    }
};