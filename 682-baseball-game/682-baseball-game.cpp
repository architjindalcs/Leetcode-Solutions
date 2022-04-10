class Solution {
public:
    int calPoints(vector<string>& ops) {
        int ans=0;
        vector<int> v;
        for(string& s: ops){
            if(s=="+"){
                int n=v.size();
                v.push_back(v[n-1]+v[n-2]);
            }
            else if(s=="D"){
                v.push_back(2*v.back());
            }
            else if(s=="C"){
                v.pop_back();
            }
            else{
                int val=stoi(s);
                v.push_back(val);
            }
        }
        
        //int ans=0;
        for(int i: v) ans+=i;
        return ans;
    }
};