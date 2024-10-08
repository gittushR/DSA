class Solution {
public:
    int minSwaps(string s) {
        int imbalance=0;
        for(auto it: s){
            if(it==']'){
                if(imbalance==0){
                    imbalance++;
                }else{
                    imbalance--;
                }
            }else{
                imbalance++;
            }
        }
        return (imbalance+1)/2;
    }
};