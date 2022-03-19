// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


void printPostOrder(int in[], int pre[], int n);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int pre[N],in[N];
        for(int i=0;i<N;i++)
            cin>>in[i];
        for(int i=0;i<N;i++)
            cin>>pre[i];
        printPostOrder(in,pre,N);
        cout<<endl;

    }
}
// } Driver Code Ends


/*prints the post order traversal of the 
tree */
void helper(int in[],int pre[],int inStrt,int inEnd,int& pI,unordered_map<int,int>& m){
    if(inStrt>inEnd) return;
    int node=pre[pI++];
    if(inStrt==inEnd){
        cout<<node<<" ";
        return;
    }
    
    int idx=m[node];
    helper(in,pre,inStrt,idx-1,pI,m);
    helper(in,pre,idx+1,inEnd,pI,m);
    cout<<node<<" ";
}
void printPostOrder(int in[], int pre[], int n)
{
    unordered_map<int,int> m;
    for(int i=0;i<n;i++) m[in[i]]=i;
    int pI=0;
    helper(in,pre,0,n-1,pI,m);
//Your code here
}