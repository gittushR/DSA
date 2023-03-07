class Solution {
public:
    #define ll long long
    long long minimumTime(vector<int>& time, int totalTrips) {
   ll low=0,ans=0,currtime;
        ll n=(ll) totalTrips; 
    ll high= n*(ll)*max_element(time.begin(),time.end());
    
       
        while(low<=high){
            currtime=low+(high-low)/2;
            long long trips=0;
            for(auto  bustym : time) trips+=currtime/bustym;
            
             if(trips>=n) {ans=currtime; high=currtime-1;}
            else low=currtime+1;
        }
        return ans;
    }
};