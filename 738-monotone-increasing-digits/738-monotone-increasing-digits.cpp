class Solution {
public:
    vector<int> getV(int num){
    
        int ndig=1+log10l(num);
        vector<int> ans(ndig);
        int idx=ans.size()-1;
        while(num){
            ans[idx]=num%10;
            num/=10;
            idx--;
        }
        return ans;
    }
    int monotoneIncreasingDigits(int n) {
        if(!n) return 0;
        vector<int> nums=getV(n);
        int i=nums.size()-2;
        int idx=-1;
        while(i>=0){
            if(nums[i]>nums[i+1]){
                int ele=nums[i];
                while(i>=0 and nums[i]==ele){
                    idx=i;
                    i--;
                }
            }
            else i--;
        }
        if(idx==-1) return n;
        //5 5 3
        nums[idx]--;
        for(int j=idx+1;j<nums.size();j++) nums[j]=9;
        int ans=0;
        for(int num: nums) ans=ans*10+num;
        return ans;
    }   
};