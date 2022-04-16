class Solution {
public:
    string largestMerge(string s1, string s2) {
        int i=0,j=0;
        string ans="";
        while(i<s1.size() and j<s2.size()){
            if(s1[i]>s2[j]) ans.push_back(s1[i++]);
            else if(s1[i]<s2[j]) ans.push_back(s2[j++]);
            else{
                int x=i,y=j;        
                int f=0;
                while(x<s1.size() and y<s2.size()){
                    if(s1[x]<s2[y]){
                        f=2;
                        break;
                    }
                    else if(s1[x]>s2[y]){
                        f=1;
                        break;
                    }
                    x++;
                    y++;
                }
                if(!f) {
                    //all are barabar, or one string has ended..
                    if(x==s1.size()){
                        f=2;
                    }
                    else f=1;
                }
                if(f==1) ans+=s1[i++];
                else ans+=s2[j++];
            }    
        }
        while(i<s1.size()) ans+=s1[i++];
        while(j<s2.size()) ans+=s2[j++];
        return ans;
    }
};