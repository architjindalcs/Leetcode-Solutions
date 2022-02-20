class Solution {
public:
    vector<int> ans;
    void helper(int st,int low,int high){
        queue<int> q;
        q.push(st);
        while(q.size()){
            int fr=q.front();
            // cout<<"fr: "<<fr<<endl;
            q.pop();
            if(fr>=low and fr<=high){
                ans.push_back(fr);
            }
            if((fr%10)==9) continue;
            long long k=fr*10+((fr%10+1));
            if(k<=high)
                q.push(k);
        }
    }
    vector<int> sequentialDigits(int low, int high) {
    //    vector<int> ans;
        for(int st=1;st<=9;st++)
            helper(st,low,high);
        sort(ans.begin(),ans.end());
        return ans;        
    }
};