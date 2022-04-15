class Solution {
public:
    int longestWPI(vector<int>& hours) {
        //length of longest subarray with positive sum.
        int cs=0,maxm=0;
        unordered_map<int,int> m;
        for(int i=0;i<hours.size();i++){
            int ele=hours[i]>8? 1 : -1;
            cs+=ele;
            if(cs>0) maxm=i+1;
            else {
                //reqSum+x=cs  and cs-reqSum=x
                if(m.count(cs-1)) maxm=max(maxm,i-m[cs-1]);
            }
            if(!m.count(cs)) m[cs]=i;
        }
        return maxm;
    }
};