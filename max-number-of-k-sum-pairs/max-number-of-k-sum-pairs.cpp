class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(int i: nums) m[i]++;
        int ans=0;
        for(auto x: m){
         //   if(x.second==0) continue;
            int ele=x.first,f=x.second;
            
            if(ele==k-ele) {
                //cout<<"her.e.."<<ele<<endl;
                ans+=(f/2);
            }
            else{
                if(m.count(k-ele)){
                    ans+=min(f,m[k-ele]);
                    m[k-ele]=0;
                }
            }
        }
        return ans;
    }
};