class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> r;
        queue<int>d;
        for(int i=0;i<senate.size();i++){
            if(senate[i]=='R')r.push(i);
            else d.push(i);
        }
        while(r.size() and d.size()){
            int rturn=r.front();
            r.pop();
            int dturn=d.front();
            d.pop();
            
            if(rturn<dturn){
                r.push(rturn+senate.size());
            }else{
                d.push(dturn+senate.size());
            }
        }
        if(r.size()==0)return "Dire";
            else return "Radiant";
    }
};