class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int i=0,j=0;
        vector<vector<int>> ans;
        while(i<nums1.size() and j<nums2.size()){
            int st1=nums1[i][0],end1=nums1[i][1];
            int st2=nums2[j][0],end2=nums2[j][1];
            /* 
                _______
                         _________         [case 1]
                         
                         
                      __________
               ____________________                [st1<end2]       
            */
            if(end1<st2)
                i++;
            else if(end2<st1)
                j++;
            else{
                ans.push_back({max(st1,st2),min(end1,end2)});
                if(end2<end1){
                    j++;
                }
                else i++;
            }
            
        }
        return ans;
    }
};