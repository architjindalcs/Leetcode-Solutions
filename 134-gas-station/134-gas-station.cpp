class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int st=0;
        int sum=0;
        int deficit=0;
        for(int i=0;i<gas.size();i++){
            sum+=(gas[i]-cost[i]);
            if(sum<0){
                st=i+1;
                deficit+=(sum);
                sum=0;
            }
        }
        return sum+deficit>=0? st: -1;
    }
};