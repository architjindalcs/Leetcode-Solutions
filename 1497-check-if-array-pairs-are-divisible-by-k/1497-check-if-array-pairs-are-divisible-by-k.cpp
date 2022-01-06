class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int f[k];
        memset(f,0,sizeof(f));
        for(int i: arr) f[(i%k+k)%k]++;
        int l=1,r=k-1;
        while(l<r){
            if(f[l]!=f[r]) return false;
            l++;
            r--;
        }
        if(f[0]%2) return false;;
        return (l!=r or (f[l]%2==0));
    }
};