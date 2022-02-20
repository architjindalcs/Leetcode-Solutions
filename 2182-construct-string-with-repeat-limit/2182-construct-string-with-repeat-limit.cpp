class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
       
        vector<int> f(26,0);
        for(char ch: s) f[ch-'a']++;
        priority_queue<pair<char,int>> pq;  //max pq, on basic of char value..
        for(int i=0;i<26;i++){
            char ch=i+'a';
            int ff=f[i];
            if(!ff) continue;
            pq.push({ch,ff});
        }
        
        string ans="";
        while(pq.size()){
            pair<char,int> tp=pq.top();
            pq.pop();
            char ch=tp.first;
            int f1=tp.second;
            int app=min(f1,repeatLimit);
            int oapp=app;
            while(app--) ans.push_back(ch);
            if(f1-oapp>0){
                //means current char ke occurences bache hue h...
                if(pq.size()){
                    char ch2=pq.top().first;
                    int f2=pq.top().second;
                    pq.pop();
                    ans.push_back(ch2);
                    f2--;
                    if(f2) pq.push({ch2,f2});
                    
                    pq.push({ch,f1-oapp});
                }
                else return ans;
            }
        }
        return ans;
    }
};