//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    int minEle;
    stack<int> s;
    vector<pair<int, int> > stv;
    public:
    
       /*returns min element from stack*/
       int getMin(){
           
           //Write your code here
           if(stv.size() == 0) return -1;
           return stv.back().second;
       }
       
       /*returns poped element from stack*/
       int pop(){
           
           //Write your code here
           if(stv.size() == 0) return -1;
           int temp = stv.back().first;
           stv.pop_back();
           return temp;
       }
       
       /*push element x into the stack*/
       void push(int x){
           
           //Write your code here
            if(stv.empty()){
                pair<int, int> p = make_pair(x, x);
                stv.push_back(p);
            }
            else{
                pair<int, int> p;
                p.first = x;
                p.second = min(x, stv.back().second);
                stv.push_back(p);
            }
       }
};

//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}

// } Driver Code Ends