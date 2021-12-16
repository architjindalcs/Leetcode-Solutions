class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int maxm=0,cs=0,maxEle=INT_MIN,mod=1000000007;
        int arrSum=0;
        for(int i=0;i<arr.size();i++){
            cs=max(arr[i],cs+arr[i]);
            maxm=max(maxm,cs);
            arrSum+=arr[i];
        }
        //when there is not even a single positive element in the array, or the value of the k
        //is 0 [no concat is allowed..]
        if(k==1) return maxm;
        
        cs=0;
        
        // cout<<"csss: "<<cs<<endl;
        int suff=INT_MIN,pre=INT_MIN;
        for(int i=arr.size()-1;i>=0;i--){
            // cout<<"cs: "<<cs<<endl;
            cs+=arr[i];
            // cout<<"cs: "<<cs<<endl;
            suff=max(suff,cs);
        }
        cs=0;
        for(int i=0;i<arr.size();i++){
            cs+=arr[i];
            pre=max(pre,cs);
        }
        if(arrSum<=0){
            //no need to concat...
            return max(long(maxm),(long)pre+(long)suff)%1000000007;
        }
        return max((long)maxm,(long)pre+(long)suff+(k-2)*(long)arrSum)%1000000007;
        return -1;
    }
};