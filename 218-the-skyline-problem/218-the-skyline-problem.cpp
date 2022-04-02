class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ans;
        int currH=0;
        multiset<int> st;
        vector<pair<int,int>> v;
        for(vector<int>& vv: buildings){
            v.push_back({vv[0],-vv[2]});
            v.push_back({vv[1],vv[2]});
        }
        sort(v.begin(),v.end());
        st.insert(0);
        for(int i=0;i<v.size();i++){
            int x=v[i].first,h=v[i].second;
            if(h<0) st.insert(-h);   //added
            else st.erase(st.find(h));   //gone
            
            int maxH=*(st.rbegin());
            if(maxH!=currH){
                currH=maxH;
                ans.push_back({x,currH});
            }
        }
        return ans;
    }
};