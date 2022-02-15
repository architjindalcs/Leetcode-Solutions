class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int map[256],rmap[256];
        memset(map,-1,sizeof(map));
        memset(rmap,-1,sizeof(rmap));
        for(int i=0;i<s.size();i++){
            int ch1=s[i];
            int ch2=t[i];
            if(map[ch1]==-1 and rmap[ch2]==-1){
                map[ch1]=ch2;
                rmap[ch2]=ch1;
            }
            else if(map[ch1]==-1 or rmap[ch2]==-1)
                return false;
            else if(!(map[ch1]==ch2 and rmap[ch2]==ch1)){
                return false;
            }
        }
        return true;
    }
};