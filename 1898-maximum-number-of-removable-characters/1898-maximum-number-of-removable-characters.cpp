class Solution {
public:
    bool poss(string& s,string& p,bool rmv[]){
        int i=0,j=0;
        while(i<s.size() and j<p.size()){
            if(rmv[i]){
                i++;
                continue;
            }
            if(s[i]==p[j]){
                i++;
                j++;
            }
            else i++;
        }
        return j==p.size();
    }
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int st=0,end=removable.size();
        int ans;
        int n=s.size();
        bool rmv[n]; //rmv[i]= true, we are removing the  ith index..
        memset(rmv,false,sizeof(rmv));
        while(st<=end){
            int mid=(st+end)/2;
            for(int i=0;i<mid;i++){
                rmv[removable[i]]=true;
            }
            if(poss(s,p,rmv)){
                ans=mid;
                st=mid+1;
            }
            else end=mid-1;
            for(int i=0;i<mid;i++){
                rmv[removable[i]]=false;
            }
        }
        return ans;
    }
};