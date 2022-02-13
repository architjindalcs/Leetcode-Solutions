class Solution {
public:
    void helper(unordered_map<int,int>& m,int& maxF,int& maxEle,int& smaxF,int& smaxEle){
        for(auto& x: m){
            int ele=x.first;
            int f=x.second;
            if(f>=maxF){
                smaxF=maxF;
                maxF=f;
                smaxEle=maxEle;
                maxEle=ele;
            }
            else if(f>=smaxF){
                smaxF=f;
                smaxEle=ele;
            }
        }
    }
    int minimumOperations(vector<int>& nums) {
        /*
             [3,1,3,2,4,3]
            nums[i]!=nums[i-1]
            nums[i]==nums[i-2];
            
        */
        int n=nums.size();
        int ans=0;
        unordered_map<int,int> even;
        unordered_map<int,int> odd;
        for(int i=0;i<nums.size();i+=1){
            if(i%2==0) even[nums[i]]++;
            else odd[nums[i]]++;
        } 
        int eveIdx=(n+1)/2;
        int oddIdx=(n-eveIdx);   //0,1,2,3,4-> 
        
        int maxEveF=0,maxEveEle=-1;
        int smaxEveF=0,smaxEveEle=-1;
        
        
        int maxOddF=0,maxOddEle=-1;
        int smaxOddF=0,smaxOddEle=-1;
        
        helper(even,maxEveF,maxEveEle,smaxEveF,smaxEveEle);
        helper(odd,maxOddF,maxOddEle,smaxOddF,smaxOddEle);
        
        int opsEven=(eveIdx-maxEveF);
        if(maxEveEle!=maxOddEle) opsEven+=(oddIdx-maxOddF);
        else opsEven+=(oddIdx-smaxOddF);
        
        int opsOdd=(oddIdx-maxOddF);
        if(maxOddEle!=maxEveEle) opsOdd+=(eveIdx-maxEveF);
        else opsOdd+=(eveIdx-smaxEveF);
        
        return min(opsEven,opsOdd);
    }
};