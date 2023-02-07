class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int last_fruit=-1;
        int second_fruit=-1;
        int lastcount=0;
        int currentmax=0;
        int maxi=0;
        for(auto it: fruits){
            if(it==last_fruit || it==second_fruit){
                currentmax++;
            }else{
                currentmax=lastcount+1;
            }
            if(it==last_fruit){
                lastcount++;
            }else{
                lastcount=1;
            }
            if(it!=last_fruit){
               second_fruit=last_fruit;
                last_fruit=it;
            }
            maxi=max(maxi,currentmax);
        }
        return maxi;
    }
};