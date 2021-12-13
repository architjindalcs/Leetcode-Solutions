class Solution {
public:
    int partition(vector<int>& nums,int low,int high){
        int pivot=nums[high];
        int st=low-1;
        for(int i=low;i<=(high-1);i++){
            if(nums[i]<=pivot){
                swap(nums[++st],nums[i]);
            }
        }
        swap(nums[st+1],nums[high]);
        return st+1;
    }
    int rpat(vector<int>& nums,int low,int high){
        int ridx=low+(rand()%(high-low));
        swap(nums[ridx],nums[high]);
        return partition(nums,low,high);
    }
    int qs(vector<int>& nums,int low,int high,int k){
        if(high==low) return nums[low];
        if(low<high){
            int pidx=rpat(nums,low,high);
            if(pidx==k) return nums[pidx];
            else if(pidx<k) return qs(nums,pidx+1,high,k);
            return qs(nums,low,pidx-1,k);
        }
        return INT_MAX;
    }
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
      //  return qs(nums,0,nums.size()-1,k);
        nth_element(nums.begin(),nums.begin()+k,nums.end());
        return nums[k];
    }
};