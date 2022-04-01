class Solution {
public:
    int histo(vector<int>& nums){
        stack<int> st;
        int ans=0;
        for(int i=0;i<=nums.size();i++){
            while(st.size() and (i==nums.size() or nums[st.top()]>=nums[i])){
                int cidx=st.top();
                st.pop();
                int nsidx=i;
                int psidx=(st.empty()? -1: st.top());
                
                int x=nsidx-i,y=i-psidx;
                ans=max(ans,(x+y-1)*nums[cidx]);
            }
            st.push(i);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> v;
        for(char ch: matrix[0]) v.push_back(ch=='1'? 1: 0);
        int ans=histo(v);
        for(int i=1;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]=='1') v[j]++;
                else v[j]=0;
            }
            ans=max(ans,histo(v));
        }
        return ans;
    }
};