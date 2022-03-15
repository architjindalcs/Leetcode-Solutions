class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ans;
        multiset<int> st;
        vector<pair<int,int>> v;
        for(auto& vv: buildings){
            int st=vv[0],end=vv[1],ht=vv[2];
            v.push_back({st,-ht});
            v.push_back({end,ht});
        }
        sort(v.begin(),v.end()); //sorted by x coordinates..
        st.insert(0);
        int currHeight=0;
        for(int i=0;i<v.size();i++){
            int x=v[i].first,h=v[i].second;
            if(h<0){
                st.insert(-h);
            }
            else st.erase(st.find(h));  //erase the first instance only..
            
            
            int biggestHeight=*(st.rbegin());
            if(currHeight!=biggestHeight){
                currHeight=biggestHeight;
                ans.push_back({x,currHeight});
            }
        }
        return ans;
    }
};