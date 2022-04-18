class Solution {
public:
    string reorganizeString(string s) {
        int f[26];
        memset(f,0,sizeof(f));
        for(char ch: s) f[ch-'a']++;
        string ans="";
        priority_queue<pair<int,char>> pq;
        for(int i=0;i<26;i++){
            if(!f[i]) continue;
            char ch=i+'a';

            pq.push({f[i],ch});
        }
        while(pq.size()>=2){
            char ch1=pq.top().second;
            int f1=pq.top().first;
            pq.pop();
            
            char ch2=pq.top().second;
            int f2=pq.top().first;
            pq.pop();
            ans+=ch1;
            ans+=ch2;
            if(f1-1) pq.push({f1-1,ch1});
            if(f2-1) pq.push({f2-1,ch2});
        }
        if(pq.size()){
            char ch=pq.top().second;
            int f=pq.top().first;
            if(f>1) return "";
            ans+=ch;
        }
        return ans;
    }
};