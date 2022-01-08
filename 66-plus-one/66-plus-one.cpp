class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i=digits.size()-1;
        while(i>=0 and digits[i]==9){
            digits[i]=0;
            i--;
        }
        if(i==-1){ 
            digits.insert(digits.begin(),1);
            return digits;
        }
        digits[i]++;
        return digits;
    }
};