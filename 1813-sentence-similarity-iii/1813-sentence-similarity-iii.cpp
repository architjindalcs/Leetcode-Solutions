class Solution {
public:
    vector<string> helper(string& s){
        int i=0;
        string cs="";
        vector<string> ans;
        while(i<=s.size()){
            if(i==s.size() or s[i]==' '){
                ans.push_back(cs);
                cs="";
                i++;
            }
            else cs+=s[i++];
        }
        return ans;
    }
    bool areSentencesSimilar(string s1, string s2) {
        if(s1.size()<s2.size()) return areSentencesSimilar(s2,s1);
        
        vector<string> v1=helper(s1);
        vector<string> v2=helper(s2);
        if(v1.size()==v2.size()) return v1==v2;
        
        //now v1.size()>v2.size();
        int i=0,j1=v1.size()-1;
        int j2=v2.size()-1;
        /*[My,name,is,Haley]
              i
          [My, Haley]
               i
               j
        
         */
        while(i<=j2 and v1[i]==v2[i]) i++;
        if(i==v2.size()) return true;
        while(i<=j2 and v1[j1]==v2[j2]) {

            j1--;
            j2--;
        }
        

    
         return (i-j2)==1;
    }
};