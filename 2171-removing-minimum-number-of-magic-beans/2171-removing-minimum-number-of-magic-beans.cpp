class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {

        sort(beans.begin(),beans.end());
        /*
            //1,4,5,6
            
        */
        int n=beans.size();
        long long ans=LONG_MAX;
        long long tsum=0;
        for(int ele: beans) tsum+=(ele);
        long long psum=0;
        
        for(int i=0;i<beans.size();i++){
            int ele=beans[i];  //i+1 se n-1 sbko iske barabar laana h hme..
            long long ops=psum+(tsum-psum)-(n-i)*((long long)beans[i]);
            ans=min(ans,ops);
            psum+=(long long)beans[i];
        }
        return ans;
    }
};