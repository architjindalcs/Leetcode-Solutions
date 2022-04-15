class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int prev=-1,cnt=0;
        for(int i=1;i<arr.size();i++){
            if(arr[i]>arr[0]){
                swap(arr[0],arr[i]);
            }
            int winner=arr[0];
           // cout<<"winner: "<<winner<<endl;
            if(winner==prev or prev==-1){
                cnt++;
                prev=winner;
                if(cnt==k) return winner;
            }
            else{
                prev=winner;
                cnt=1;
            }
        }
        return arr[0];
    }
};