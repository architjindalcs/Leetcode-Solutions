class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        if(nums1.size()>nums2.size()) return findMedianSortedArrays(nums2,nums1);
        
        int x=nums1.size(),y=nums2.size();
        
        int st=0,end=x;
        while(st<=end){
            int partX=(st+end)/2;            
            /*
               [partX]__________
               
               [partY__]_________________
                
                
                [1,2],3,4
                
                px=2, py= (5-2) =3
                [5,6,7],8,9
                
                1,2,3,4
                px=2, py = (4-2) =2 
                5,6,7,8
                
                It breaks in such a way, that left array have one element extra of same as 
                of right array
            */
            int partY=((x+y+1)/2)-partX;
            int l1=(partX? nums1[partX-1]: INT_MIN);
            int l2=(partY? nums2[partY-1]: INT_MIN);
            int r1=(partX<nums1.size()) ? nums1[partX] : INT_MAX;
            int r2=(partY<nums2.size()) ? nums2[partY] : INT_MAX;
            
            if(l1<=r2 and l2<=r1){
                int siz=(x+y);
                if(siz&1)
                    return max(l1,l2);
                
                return (max(l1,l2)+min(r1,r2))/2.0;
            }
            else if(l1>r2) end=partX-1;
            else st=partX+1;
            
        }
        
        return 0.0;
        
        

    }
};