class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        bool fnd[1<<n];
        memset(fnd,false,sizeof(fnd));
        for(string& s: nums){
            int val=0;
            for(char ch: s) val=val*2+(ch-'0');
            fnd[val]=true;
        }
        for(int i=0;i<(1<<n);i++){
            if(!fnd[i]){
                if(!i) return string(n,'0');
                string ans="";
                int num=i;
                int cnt=0;
                while(num) {
                    ans+=((num&1)+'0');
                    num>>=1;
                    cnt++;
                }
                while(cnt<n) {
                    ans+="0";
                    cnt++;
                }
                reverse(ans.begin(),ans.end());
                return ans;
            }
        }
        return "";
    }
};