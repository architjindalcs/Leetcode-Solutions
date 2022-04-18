class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
      //  vector<int> ans;
        unordered_map<int,int> m;
        for(int num: nums1) {
            if(!m.count(num)) m[num]=1;
        }
        
        unordered_set<int> ans;
    
        for(int num: nums2){
            if(m.count(num)) {
                ans.insert(num);
                if(m[num]==1) m[num]++;
            }
        }
        for(int num: nums2) m[num]++;
        
        for(int num: nums3){
            if(m.count(num)) ans.insert(num);
        }
        return vector<int> (ans.begin(),ans.end());
        
    }
};