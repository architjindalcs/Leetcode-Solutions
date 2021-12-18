class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        //profit of -10, -170, 350, 10  [send to A over B,]
        // -170, -10, 10, 350   -> send initials to A, 
        sort(costs.begin(),costs.end(),[&](vector<int>& v1,vector<int>& v2){
           return v1[0]-v1[1]<v2[0]-v2[1]; 
        });
        int n=costs.size(),ans=0;
        for(int i=0;i<costs.size();i++){
            ans+=(i<n/2? costs[i][0]: costs[i][1]);
        }
        return ans;
    }
};