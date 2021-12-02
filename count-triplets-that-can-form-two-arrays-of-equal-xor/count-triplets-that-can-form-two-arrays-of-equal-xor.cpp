class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int ans=0;
        for(int i=0;i<arr.size();i++){
            int xval=arr[i];
            for(int j=i+1;j<arr.size();j++){
                xval=xval xor arr[j];
                if(!xval) ans+=(j-i);
            } 
        }
        return ans;
    }
};