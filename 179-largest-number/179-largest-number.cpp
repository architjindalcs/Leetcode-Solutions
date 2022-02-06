class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string ans="";
        sort(nums.begin(),nums.end(),[&](int& s1,int& s2){
            return to_string(s1)+to_string(s2)>to_string(s2)+to_string(s1);
        });
        for(int& s: nums) ans+=to_string(s);
        int i=0;
        while(i<ans.size() and ans[i]=='0') i++;
        return i==ans.size()? "0": ans.substr(i);
        
    }
};