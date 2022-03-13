// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        QueueStack *qs = new QueueStack();

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            qs->push(a);
        }else if(QueryType==2){
            cout<<qs->pop()<<" ";

        }
        }
        cout<<endl;
    }
}
// } Driver Code Ends


/* The structure of the class is
class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};
 */

//Function to push an element into stack using two queues.
void QueueStack :: push(int x)
{
    q1.push(x);
    //1,2,3 -> top 3, stop 2, sstop 1
        // Your Code
    
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
    int n=q1.size();
    if(!n) return -1;
    for(int i=0;i<n-1;i++) {
        q1.push(q1.front());
        q1.pop();
    }
    int ans=q1.front();
    q1.pop();
    return ans;
        // Your Code       
}
