class Solution {
public:
    int f(string& s){
        int fr[26];
        memset(fr,0,sizeof(fr));
        for(char ch: s) fr[ch-'a']++;
        for(int i=0;i<26;i++) if(fr[i]) return fr[i];
        return -1;
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> nums;
        for(string& s: words) nums.push_back(f(s));
        vector<int> ans;
        sort(nums.begin(),nums.end());
        for(string& q: queries){
            int idx=upper_bound(begin(nums),end(nums),f(q))-begin(nums);
            ans.push_back(nums.size()-idx);
        }
        return ans;
    }
};