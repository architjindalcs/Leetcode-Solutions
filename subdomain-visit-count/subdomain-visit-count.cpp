class Solution {
public:
    string rev(string temp){
        string ans="";
        for(int i=temp.size()-1;i>=0;i--) ans.push_back(temp[i]);
        return ans;
    }
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> ans;
        unordered_map<string,int> mp;
        for(string& s: cpdomains){
            int i=s.size()-1;
            string temp="";
            int num=0,mf=1;
            vector<string> vec;
            while(i>=0 and s[i]!=' '){
                while(i>=0 and !(s[i]=='.' or s[i]==' ')){
                    temp.push_back(s[i]);
                    i--;
                }
                if(s[i]=='.'){
                   // cout<<rev(temp)<<endl;
                    vec.push_back(rev(temp));
                   temp+=".";
                    i--;
                }
                else{
                    vec.push_back(rev(temp));
                    i--;
                    while(i>=0){
                        num+=(mf*(s[i]-'0'));
                        mf*=10;
                        i--;
                    }
                  //  cout<<num<<endl;
                    break;
                }
            }
            
            for(string& s: vec) {
                mp[s]+=num;
            }
        }
   //     vector<string> ans;
        for(auto x: mp){
            int cnt=x.second;
            string tmp=to_string(cnt)+" ";
            tmp+=(x.first);
            ans.push_back(tmp);
        }
        return ans;
    }
};