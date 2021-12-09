class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        unordered_map<string,int> m;
        for(string& s: nums) if(s.size()<target.size()) m[s]++;
        int ans=0;
        for(auto x: m){
            string s1=x.first;
            int f=x.second;
            string s2=target.substr((int)s1.size());
            if(s1+s2==target){
                if(s1==s2){
                    ans+=(f*(f-1));
                }
                else{
                    ans+=f*m[s2];
                }
            }
        }
        return ans;
    }
};