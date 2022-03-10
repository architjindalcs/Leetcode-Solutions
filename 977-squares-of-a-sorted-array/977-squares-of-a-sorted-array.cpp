class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        int i=0;
        while(i<nums.size() and nums[i]<0){
            i++;
        }
        if(i==nums.size()){
            //saare negative h..
            vector<int> ans;
            for(int i=nums.size()-1;i>=0;i--) ans.push_back(nums[i]*nums[i]);
            return ans;
        }
        else if(i==0){
            vector<int> ans;
            for(int& i: nums) ans.push_back(i*i);
            return ans;
        }
        
       // vector<int> ans;
    //    cout<<"i: "<<i<<endl;
        int j=i-1;
  //      cout<<"j: "<<j<<endl;
        while(i<nums.size() and j>=0){
            int sqi=nums[i]*nums[i],sqj=nums[j]*nums[j];
            if(sqi<=sqj){
                ans.push_back(sqi);
                i++;
            }
            else {
                ans.push_back(sqj);
                j--;
            }
        }
        while(i<nums.size()) ans.push_back(nums[i]*nums[i++]);
        while(j>=0) ans.push_back(nums[j]*nums[j--]);
        return ans;
    }
    
};