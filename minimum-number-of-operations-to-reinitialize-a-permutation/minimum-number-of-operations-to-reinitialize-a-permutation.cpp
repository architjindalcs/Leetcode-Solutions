class Solution {
public:
    int reinitializePermutation(int n) {
        int graph[n];
        for(int i=0;i<n;i++){
            graph[i]=(i%2==0? (i/2): ((n/2)+(i-1)/2));
        }
        int curr=graph[1],ans=1;
        while(curr!=1){
            ans++;
            curr=graph[curr];
        }
        return ans;
    }
};