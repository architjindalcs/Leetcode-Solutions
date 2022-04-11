class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int r=grid.size(),c=grid[0].size();
        vector<int> nums;
        for(vector<int>& v: grid){
            for(int i: v) nums.push_back(i);
        }
        int n=nums.size();
        if(k%n==0) return grid;
        k=k%n;
        //1,2,3,4,5,6,7,8,9  -> k=1    9,1,2,3,4,5,6,7,8
        int idx1=nums.size()-k;
        int idx2=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(idx1<nums.size())
                grid[i][j]=(nums[idx1++]);
                else grid[i][j]=nums[idx2++];
            }
        }
        return grid;
    }
};