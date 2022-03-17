class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxm=0;
        int n=heights.size();
        for(int i=0;i<=n;i++){
            while(st.size() and (i==n or heights[st.top()]>=heights[i])){
                int tp=st.top();
                st.pop();
                //removing greater heights..
                //now for htp, heights[i] is next smaller and stack will always be in increasing order and after removing one again that would be prev smaller..
                int nextSmaller=i;
                int prevSmaller=(st.size()? st.top(): -1);
                maxm=max(maxm,heights[tp]*(nextSmaller-prevSmaller-1));
            }
            st.push(i);
        }
        return maxm;
    }
};