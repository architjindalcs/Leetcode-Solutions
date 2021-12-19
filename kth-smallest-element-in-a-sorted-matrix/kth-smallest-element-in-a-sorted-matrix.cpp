class Solution {
public:
    int getLTEqual(vector<vector<int>>& grid,int ele){
        int cnt=0;
        for(vector<int>& v: grid){
            auto it=upper_bound(v.begin(),v.end(),ele);
            cnt+=(it-v.begin());
        }
        return cnt;
    }
    int kthSmallest(vector<vector<int>>& grid, int k) {
        int r=grid.size(),c=grid[0].size();
        int st=grid[0][0],end=grid[r-1][c-1];
        while(st<end){
            int mid=(st+(end-st)/2);
            int cnt=getLTEqual(grid,mid);
            if(cnt<k) st=mid+1;
            else end=mid;
        }
        return end;
    }
};