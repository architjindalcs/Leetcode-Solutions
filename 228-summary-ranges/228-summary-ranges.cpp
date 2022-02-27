class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int i=0;
        while(i<nums.size()){
            long st=nums[i],end=nums[i];
            while(i<nums.size() and nums[i]==end){
                end++;
                i++;
            }
            end--;
            if(st==end){
                ans.push_back(to_string(st));
            }
            else{
                string kk=to_string(st)+"->"+to_string(end);
                ans.push_back(kk);
            }
        }
        return ans;
    }
};