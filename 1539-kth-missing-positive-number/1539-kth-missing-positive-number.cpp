class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int prev=0, cnt=0;
        for(int num: arr){
            if(!(num>prev+1)) {
                prev=num;
                continue;
            }
            int canUse=min(k,num-prev-1);
            k-=canUse;
            if(k==0) return prev+1+(canUse-1);
            prev=num;
        }
        return arr.back()+k;
    }
};