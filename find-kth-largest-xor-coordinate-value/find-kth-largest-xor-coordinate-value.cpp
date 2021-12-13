class Solution {
public:
    int kthLargestValue(vector<vector<int>>& grid, int k) {
        int r=grid.size(),c=grid[0].size();
        for(int i=1;i<r;i++) grid[i][0]=grid[i][0] xor grid[i-1][0];
        for(int j=1;j<c;j++) grid[0][j]=grid[0][j] xor grid[0][j-1];
        for(int i=1;i<r;i++){
            for(int j=1;j<c;j++){
                grid[i][j]=grid[i][j] xor grid[i-1][j] xor grid[i][j-1] xor grid[i-1][j-1];
            }
        }
        vector<int> nums;
        for(auto& v: grid){
            for(int i: v) nums.push_back(i);
        }
        k--;
        int n=nums.size();
        k=(n-1-k);
        nth_element(nums.begin(),nums.begin()+k,nums.end());
        return nums[k];
    }
};