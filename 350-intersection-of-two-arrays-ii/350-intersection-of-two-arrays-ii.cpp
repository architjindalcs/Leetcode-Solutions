class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i=0,j=0;
        vector<int> ans;
        while(i<nums1.size() and j<nums2.size()){
            if(nums1[i]<nums2[j]) i++;
            else if(nums2[j]<nums1[i]) j++;
            else{
                int ele1=nums1[i],ele2=nums2[j];
                while(i<nums1.size() and nums1[i]==ele1 and j<nums2.size() and nums2[j]==ele2){
                    ans.push_back(ele1);
                    i++;
                    j++;
                }
            }
        }
        return ans;
    }
};