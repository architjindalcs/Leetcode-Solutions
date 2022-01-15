class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        vector<pair<int,int>> v;
        int n=nums1.size();
        sort(nums1.begin(),nums1.end());
        for(int i=0;i<nums2.size();i++) v.push_back({nums2[i],i});
        sort(v.begin(),v.end());
        vector<int> ans(n,0);
        int low=0,high=nums1.size()-1;
        for(int i=v.size()-1;i>=0;i--){
            int idx=v[i].second,ele=v[i].first;
            if(ele<nums1[high]){
                ans[idx]=nums1[high];
                high--;
            }
            else{
                ans[idx]=nums1[low];
                low++;
            }
        }
        return ans;
    }
};