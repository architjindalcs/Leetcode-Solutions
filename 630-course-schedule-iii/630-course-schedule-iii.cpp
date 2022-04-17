class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),[&](vector<int>& v1,vector<int>& v2){
            return v1[1]<v2[1];
        });  //sorted acc to the lastday, try to finish the tasks, whose expiry is minm
        priority_queue<int> pq;
        int sum=0;
        for(vector<int>& v: courses){
            int dur=v[0],dl=v[1];
            sum+=dur;
            pq.push(dur);
            if(sum>dl){
                //i need to skip a task with maxm duration that i have picked earlier..
                sum-=pq.top();
                pq.pop();
            }
        }
        return pq.size();;
    }
};