class Solution {
public:
    bool poss(vector<int>& pos,int ncow,int minGap){
        //it will return whether it is possible to place ncow..such that gap>=minGap
        int cnt=1;
        int lpos=pos[0];
        for(int i=1;i<pos.size();i++){
            if(pos[i]-lpos>=minGap){
                lpos=pos[i];
                cnt++;
            }
            if(cnt>=ncow) return true;
        }
        return cnt>=ncow;
    }
    int maxDistance(vector<int>& pos, int m) {
        sort(pos.begin(),pos.end());
        int st=INT_MAX,end=pos.back()-pos[0];
        for(int i=1;i<pos.size();i++) st=min(st,pos[i]-pos[i-1]);
        int ans=-1;
        while(st<=end){
            int gap=(st+end)/2;
            if(poss(pos,m,gap)){
                ans=gap;
                st=gap+1;
            }
            else end=gap-1;
        }
        return ans;
    }
};