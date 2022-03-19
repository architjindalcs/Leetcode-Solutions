// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution{
    public:
    /*You are required to complete this method*/
     int max_path_sum(int A[], int B[], int n1, int n2)
    {
    
        int maxm=0;
        int i=0,j=0,s1=0,s2=0;
        while(i<n1 and j<n2){
            if(A[i]<B[j]){
                s1+=A[i++];
            }
            else if(A[i]>B[j]){
                s2+=B[j++];
            }
            else{
                maxm+=max(s1,s2);
                s1=0,s2=0;
                while(i<n1 and j<n2 and A[i]==B[j]){
                    maxm+=A[i];
                    i++;
                    j++;
                }
            }
        }
        
        while(i<n1) s1+=A[i++];
        while(j<n2) s2+=B[j++];
        
        maxm+=max(s1,s2);
        return maxm;
        //Your code here
    }
};

// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;

    while(T--)
    {
        int N,M;
        cin>>N>>M;
        fflush(stdin);
        int a[N],b[M];
        for(int i=0;i<N;i++)
            cin>>a[i];
        for(int i=0;i<M;i++)
            cin>>b[i];
        Solution obj;
        int result = obj.max_path_sum(a,b,N,M);
        cout<<result<<endl;
    }
}

  // } Driver Code Ends