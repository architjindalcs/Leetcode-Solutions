// { Driver Code Starts
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
    stack<int> st;
  //  int minEle=INT_MIN;
    public:
    
       /*returns min element from stack*/
       int getMin(){
           if(st.empty()) return -1;
           //Write your code 
           return minEle;
       }
       
       /*returns poped element from stack*/
       int pop(){
           if(st.empty()) return -1;
           int tp=st.top();
           st.pop();
           int ret;
           if(tp<minEle){
               ret=minEle;
               minEle=2*minEle-tp;  //this would have been the 'x' we pushed, so 2x-(2x-minEle(oldminEle)) -> oldMinEle
            }
           else{
               ret=tp;
           }
           return ret;
           //Write your code here
       }
       
       /*push element x into the stack*/
       void push(int x){
           if(st.empty()){
               minEle=x;
               st.push(x);
               return;
           }
           if(x<minEle){
               /*
                    x<minEle
                    x-minEle<0
                    2x-minEle< x
                    push 2x-minEle and update minEle=x => st.top() now be less than minEle
               */
               st.push(2*x-minEle);
               minEle=x;
           }
           else{
               st.push(x);
           }
           //Write your code here
       }
};

// { Driver Code Starts.

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