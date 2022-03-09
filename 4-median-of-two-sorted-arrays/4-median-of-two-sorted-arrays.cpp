class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()) return findMedianSortedArrays(nums2,nums1);
        int x=nums1.size(),y=nums2.size();
        int st=0,end=x;
        while(st<=end){
            int partX=(st+end)/2;
            int partY=((x+y+1)/2)-partX;
            /*
                [__l1]r1______
                [_______l2]r2____
            */
            int l1=(partX? nums1[partX-1]: INT_MIN) ,l2=(partY? nums2[partY-1]: INT_MIN);
            
            int r1=(partX<x? nums1[partX]: INT_MAX) ,r2=(partY<y? nums2[partY]: INT_MAX);
            if(l1<=r2 and l2<=r1){
                if((x+y)&1)
                    return max(l1,l2);
                return (max(l1,l2)+min(r1,r2))/2.0;
            }
            else if(l1>r2){
                end=partX-1;
            }
            else st=partX+1;
        }
        return 0.0;
    }
};