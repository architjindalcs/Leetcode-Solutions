class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        int len[n],cnt[n];
        memset(len,0,sizeof(len));
        memset(cnt,0,sizeof(cnt));
        int maxLen=0,ans=0;
        for(int i=0;i<n;i++){
            cnt[i]=1; len[i]=1;
            for(int j=i-1;j>=0;j--){
                if(nums[j]<nums[i]){
                    if(1+len[j]>len[i]){
                        len[i]=1+len[j];
                        cnt[i]=cnt[j];
                    }
                    else if(1+len[j]==len[i]) cnt[i]+=cnt[j];
                }
            }
            if(len[i]>maxLen){
                maxLen=len[i];
                ans=cnt[i];
            }
            else if(len[i]==maxLen)
                ans+=cnt[i];
        }
        return ans;
    }
};