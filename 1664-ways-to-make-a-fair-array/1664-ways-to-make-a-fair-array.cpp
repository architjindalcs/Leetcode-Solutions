class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        /*
            [6,1,7,4,1]
            
        */
        int osum=0,esum=0;
        for(int i=0;i<nums.size();i++){
            if(i%2==0) esum+=nums[i];
            else osum+=nums[i];
        }
        int cnt=0;
        int pesum=0,posum=0;
        for(int i=0;i<nums.size();i++){
            //i am considering removing the current index..
            if(i%2==0) esum-=nums[i];
            else osum-=nums[i];
            //6,1,7,4,1 -> esum = 6+7+1 = 8, osum=5 
            //now esum and osum will actually swap
         
            if(posum+esum == pesum+osum)
                cnt++;
            
            pesum+=(i%2==0? nums[i]: 0);
            posum+=(i%2==1? nums[i]: 0);
        }
        return cnt;
    }
};