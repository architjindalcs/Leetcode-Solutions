class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size())
            return findMedianSortedArrays(nums2,nums1);
        int x=nums1.size(),y=nums2.size();
        int st=0,end=x;
        while(st<=end){
            int partX=(st+end)/2;
            int partY=((x+y+1)/2)-partX;
            int tmax=(partX? nums1[partX-1]: INT_MIN);
            int bmax=(partY? nums2[partY-1]: INT_MIN);
            int tmin=(partX<nums1.size() ? nums1[partX]: INT_MAX);
            int bmin=(partY<nums2.size() ? nums2[partY]: INT_MAX);
            if(tmax<=bmin and bmax<=tmin){
                if((x+y)&1){
                    return 1.0*max(tmax,bmax);
                }
                return (max(tmax,bmax)+min(tmin,bmin))/2.0;
                //I am at the correct position
            }
            else if(tmax>bmin){
                end=partX-1;
            }
            else st=partX+1;
        }
        return 0.0;
    }
};