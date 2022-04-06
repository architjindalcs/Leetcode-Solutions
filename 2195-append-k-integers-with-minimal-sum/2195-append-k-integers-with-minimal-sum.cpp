class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        for(int i: nums) cout<<i<<" ";
        cout<<endl;
        int prev=0;
        long long ans=0;
        /*
            a , a+1, a+2, a+3
            a[0,1,2,3]
        */
        for(int num: nums){
            if(!(num>prev+1)){
                prev=num;
                continue;
            }
            if(k==0) return ans;
             /*
              0,5,10  1,2,3,4
              prev= 0  num=5
              num-prev-1 -> can be appended..starting from prev+1 (num-prev-1) integers..
            */
            
            int canBeAppended=min(k,num-prev-1);
            k-=canBeAppended;
            long long a=prev+1, n = canBeAppended;
            long long add= (n*(2*a+(n-1)))/2;
            ans+=add;
            prev=num;
        }
        if(k){
            int canBeAppended=min(k,INT_MAX);
            k-=canBeAppended;
            long long a=prev+1, n = canBeAppended;
            long long add= (n*(2*a+(n-1)))/2;
            ans+=add;
        }
        return ans;
    }
};