class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int n=nums.size();
        int pre[n][101];
        memset(pre,0,sizeof(pre));
        for(int i=0;i<nums.size();i++){
            for(int ele=1;ele<=100;ele++){
                if(nums[i]==ele) pre[i][ele]=1+((i? pre[i-1][ele]: 0));
                else pre[i][ele]=(i? pre[i-1][ele]: 0);
            }
        }
        
        for(vector<int>& q: queries){
            int st=q[0],end=q[1];
            int f[101];
            memset(f,0,sizeof(f));
            for(int ele=1;ele<=100;ele++){
                f[ele]=(pre[end][ele]-(st? pre[st-1][ele]: 0));
            }
            int prev=-1;
            int minDiff=INT_MAX;
            for(int ele=1;ele<=100;ele++){
                if(!f[ele]) continue;
                if(prev!=-1){
                    minDiff=min(minDiff,ele-prev);
                }
                prev=ele;
            }
            if(minDiff==INT_MAX or minDiff==0) ans.push_back(-1);
            else ans.push_back(minDiff);
        }
        return ans;
    }
};