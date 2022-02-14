class Solution {
public:
    int gs(vector<int>& nums){
        int sum=0;
        for(int ele: nums) sum+=ele;
        return sum;
    }
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        if(nums[0]>0) return k%2==0? gs(nums): gs(nums)-2*nums[0];
    
        if(nums[0]==0) return gs(nums);
        
        if(nums.back()<0){
            //all the numbers are negative..
            int i=0;
            while(i<nums.size() and nums[i]<0 and k){
                nums[i]=-nums[i];
                i++;
                k--;
            }
            if(k%2==0) return gs(nums);
            //-5,-4,-2,-1 -> 5,4,2,1  
            return gs(nums)-2*nums.back();
        }
        
        int i=0;
        while(i<nums.size() and nums[i]<0 and k) {
            nums[i]=-nums[i];
            i++;
            k--;
        }
        if(k%2==0) return gs(nums);  //we are left with even number of negations.. 
        if(nums[i]==0) return gs(nums); //nums[i]=0, even or odd, both can be handled 
        if(abs(nums[i])<abs(nums[i-1])){
            nums[i]=-nums[i];
            return gs(nums);
        }
        return gs(nums)-2*nums[i-1];
    }
};