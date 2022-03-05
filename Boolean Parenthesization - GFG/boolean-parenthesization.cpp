// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int countWays(int N, string S){
        // code here
        if(N==1) return S[0]=='T';
        long long dpt[N][N],dpf[N][N];
        int mod=1003;
        memset(dpt,0,sizeof(dpt));
        memset(dpf,0,sizeof(dpf));
        for(int i=0;i<N;i+=2){
            dpt[i][i]=(S[i]=='T');
            dpf[i][i]=(S[i]=='F');  
        }

        for(int l=3;l<=N;l++){
            for(int i=0;i<=(N-l);i+=2){
                /*
                    [T & F | T]
                     i       k
                
                */
                long  cntt=0,cntf=0;;
                int k=i+l-1;
                for(int z=1;z<=k;z+=2){
                    char op=S[z];
                    int tl=dpt[i][z-1],fl=dpf[i][z-1];
                    int tr=dpt[z+1][k],fr=dpf[z+1][k];
                    
                    if(op=='&'){
                        cntt+=(tl*tr)%mod;
                        cntf+=((fl*fr)%mod+(tl*fr)%mod+(tr*fl)%mod)%mod;
                    }
                    else if(op=='|'){
                        cntt+=((tl*tr)%mod+(tl*fr)%mod+(tr*fl)%mod)%mod;
                        cntf+=(fl*fr)%mod;
                    }
                    else {
                        cntt+=((tl*fr)%mod+(tr*fl)%mod)%mod;
                        cntf+=((tl*tr)%mod+(fl*fr)%mod)%mod;
                    }
                }
                dpt[i][k]=cntt%mod;
                dpf[i][k]=cntf%mod;
            }
        }
        return dpt[0][N-1]%mod;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends