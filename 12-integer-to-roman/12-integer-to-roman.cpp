class Solution {
public:
    string intToRoman(int num) {
        string ans="";
        vector<int> v={1,4,5,9,10,40,50,90,100,400,500,900,1000};
        vector<string> strs={"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        int i=v.size()-1;
        while(i>=0 and num){
            if(v[i]>num){
                i--;
                continue;
            }
            while(num>=v[i]){
                //1994 -> 1000  ans=M -> 1994 994-> 900 -> 
                ans+=strs[i];
                num-=v[i];
            }
            i--;
        }
        return ans;
    }
};