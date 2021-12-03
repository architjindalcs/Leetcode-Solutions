class Solution {
public:
    /*  
        3,2,4,1
        4,2,3,1
        1,3,2,4
        3,1,2,4
        2,1,3,4
        
    */
    void reverse(vector<int>& arr,int l,int r){
        while(l<r) swap(arr[l++],arr[r--]);
    }
    int getIdx(vector<int>& arr,int ele){
        for(int i=0;i<arr.size();i++) if(arr[i]==ele) return i;
        return -1;
    }
    
    vector<int> pancakeSort(vector<int>& arr) {
        int maxm=arr.size();
        vector<int> ans;
        for(int i=0;i<arr.size();i++){
            int idx=getIdx(arr,maxm);
            reverse(arr,0,idx);
            ans.push_back(idx+1);
            reverse(arr,0,arr.size()-1-i);
            ans.push_back(arr.size()-i);
            maxm--;
        }
        return ans;
    }
};