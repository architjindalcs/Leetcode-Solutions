class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for(int i=0;i<l.size();i++){
            int st=l[i],end=r[i];
            vector<int> v;
            for(int i=st;i<=end;i++) v.push_back(nums[i]);
            sort(v.begin(),v.end());
            if(v.size()<=1) ans.push_back(false);
            else{
                int d=v[1]-v[0];
              //  cout<<"d: "<<d<<endl;
                bool poss=true;
                for(int i=1;i<v.size();i++){
                    if(v[i]-v[i-1]!=d){
                        poss=false;
                        break;
                    }
                }
                ans.push_back(poss);
            }
        }
        return ans;
    }
};