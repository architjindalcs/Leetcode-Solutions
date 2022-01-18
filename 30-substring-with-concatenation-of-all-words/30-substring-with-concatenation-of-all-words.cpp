class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        unordered_map<string,int> f;
        int len=0;
        for(string& s: words) {
            f[s]++;
            len+=(s.size());
        }
        int wl=words[0].size();
        unordered_map<string,int> cpy;
        for(int i=0;i+len-1<=s.size()-1;i++){
            int j=i;
            cpy.clear();
            bool poss=true;
            string cs="";
            int cnt=0;
            while(j<s.size() and cnt<len){
                cs+=(s[j]);
                cnt++;
                if(cs.size()==wl){
                    if(!f.count(cs)){
                        poss=false;
                        break;
                    }
                    cpy[cs]++;
                    if(cpy[cs]>f[cs]){
                        poss=false;
                        break;
                    }
                    cs="";
                }
                j++;
            }
            for(auto& x: cpy){
                if(x.second!=f[x.first]){
                    poss=false;
                    break;
                }
            }
            if(poss) ans.push_back(i);
        }
        return ans;
    }
};