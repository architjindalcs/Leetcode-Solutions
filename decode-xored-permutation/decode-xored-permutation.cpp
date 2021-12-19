class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int fz=0;
        for(int i=1;i<=encoded.size()+1;i++) fz=fz xor i;
        int eone=0;
        for(int i=1;i<encoded.size();i+=2) eone=eone xor encoded[i];
        int fele=eone xor fz;
        vector<int> ans={fele};
        for(int i: encoded)
            ans.push_back(ans.back() xor i);
        return ans;
    }
};