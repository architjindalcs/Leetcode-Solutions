class Solution {
public:
    bool valid(vector<int>& f){
        int cnt=0;
        for(int i=0;i<26;i++){
            if(f[i]&1) cnt++;   
        }
        return cnt=1;
    }
    long long wonderfulSubstrings(string word) {
        long long ans=0;
        unordered_map<int,int> m;
        int mask=0;
        m[0]=1;
        for(int i=0;i<word.size();i++){
            mask=mask ^ (1<<(word[i]-'a'));  
            ans+=(m[mask]);
            
            for(char ch='a';ch<='j';ch++){
                ans+=m[mask^(1<<(ch-'a'))];
            }
            m[mask]++;
        }
        return ans;
    }
};