class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        /*
            1,2,3,5
            0,1,2,3
            
            1/5 (0,3) < 1/3 (0,2) < 1/2 (0,1)
            2/5 (1,3) < 2/3 (1,2)
            3/5 (2,3)
        
        */
        auto cmp=[&](pair<int,int>& p1,pair<int,int>& p2){
            int num1=arr[p1.first],den1=arr[p1.second];
            int num2=arr[p2.first],den2=arr[p2.second];
            return  num1*den2>num2*den1;   // num1/den1 > num2/den2 -> minm fraction should be at top
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>, decltype(cmp) > pq(cmp);
        
        int n=arr.size();
        for(int i=0;i<arr.size()-1;i++) pq.push({i,arr.size()-1});
        
        vector<int> ans;
        while(pq.size()){
            pair<int,int> tp=pq.top();
            pq.pop();
            int nidx=tp.first,didx=tp.second;
            k--;
            if(k==0) return {arr[nidx],arr[didx]};
            if(nidx<didx-1)
            pq.push({nidx,didx-1});
        }
        return {-1,-1};
    }
};