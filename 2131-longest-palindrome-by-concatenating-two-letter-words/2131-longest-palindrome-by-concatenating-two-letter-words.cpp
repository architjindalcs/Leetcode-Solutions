class Solution {
public:
    string rev(string& s){
        string temp=s;
        swap(temp[0],temp[1]);
        return temp;
    }
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> m;
        for(string& s: words){
            m[s]++;
        }
       
        int ans=0,maxEq=0;
        bool odd=false;
        for(auto& x: m){
            if(!(x.second)) continue;
            string s1=x.first;
            int f1=x.second;
            string s2=rev(s1);
            
            if(s1!=s2 and m.count(s2)){
                //lc  - it requires cl for sure..
                int f2=m[s2];
                ans+=(min(f1,f2)*4);
                m[s2]=0;
                
            }
            else if(s1==s2){
                //aa -> aa and f=4;
                if(f1&1) odd=true;  //for 2 chars extra addition..
                
                ans+=(f1%2==0? f1*2: 2*f1-2);
            }
        }
 //       cout<<"ans: "<<ans<<endl;
        return ans+ (odd? 2: 0);
    }
};