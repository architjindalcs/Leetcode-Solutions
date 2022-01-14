class Solution {
public:
    vector<int> closestDivisors(int num) {
        int n1=num+1,n2=num+2;
        int minDiff=INT_MAX;
        vector<int> ans;
        for(int i=1;i*i<=n2;i++){
            if(n1%i==0){
                int val1=i,val2=n1/i;
                if(abs(val1-val2)<minDiff){
                    minDiff=abs(val1-val2);
                    ans={val1,val2};
                }
            }
            if(n2%i==0){
                int val1=i,val2=n2/i;
                if(abs(val1-val2)<minDiff){
                    minDiff=abs(val1-val2);
                    ans={val1,val2};
                }
            }
        }
        return ans;
    }
};