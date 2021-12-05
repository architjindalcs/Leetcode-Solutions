class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto cmp=[&](pair<int,int>& p1,pair<int,int>& p2){
            double val1=(p1.first/(1.0*p1.second));
            double val2=(p2.first/(1.0*p2.second));
            
            double nval1=((p1.first+1)/(1.0*(p1.second+1)));
            double nval2=((p2.first+1)/(1.0*(p2.second+1)));
            
            double inc1=nval1-val1;
            double inc2=nval2-val2;
            
            //jisme jyada increment aayega, we will keep that on the top..
            if(inc1>inc2) return false;
            return true;
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp);
        for(auto c: classes) pq.push({c[0],c[1]});
        while(extraStudents--){
            auto tp=pq.top();
            pq.pop();
            int num=tp.first,den=tp.second;
            pq.push({num+1,den+1});
        }
        double ans=0.0;
        while(pq.size()){
            ans+=((pq.top().first)/(1.0*pq.top().second));
            pq.pop();
        }
        return ans/(1.0*classes.size());
    }
};