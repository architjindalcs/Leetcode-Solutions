class Solution {
public:
    bool vowel(char ch){
        return ch=='a' or ch=='e' or ch=='i' or ch=='o' or ch=='u';
    }
    int helper(string& s,int k){
        int f[26],uq=0,ans=0;
        memset(f,0,sizeof(f));
        int st=0,i=0;
        while(i<s.size()){
            if(!vowel(s[i])) {
                //a complete reset, as we require only vowels presence 
                st=(++i);
                memset(f,0,sizeof(f));
                uq=0; 
                continue;
            }
            f[s[i]-'a']++;
            if(f[s[i]-'a']==1) uq++;
            while(st<i and uq>k){
                f[s[st]-'a']--;
                if(f[s[st]-'a']==0) uq--;
                st++;
            }
            if(uq<=k){
                ans+=(i-st+1);
            }
            i++;
        }
        return ans;
    }
    int countVowelSubstrings(string s) {
        //number of substrings having exactly k=5 distinct chars which are vowels..         
        return helper(s,5)-helper(s,4);
    }
};