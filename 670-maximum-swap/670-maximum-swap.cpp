class Solution {
public:
    int maximumSwap(int num) {
        int temp=num;
        int f[10];
        memset(f,0,sizeof(f));
        vector<int> numv;
        while(temp) {
            f[temp%10]++;
            numv.push_back(temp%10);
            temp/=10;
        }
        reverse(numv.begin(),numv.end());
        vector<pair<int,int>> v;
        for(int i=0;i<10;i++){
            if(f[i]) v.push_back({i,f[i]});
        }
        sort(v.begin(),v.end(),[&](pair<int,int>& p1,pair<int,int>& p2){
           return p1.first>p2.first; 
        });   
        int idx=0;
        bool go=true;
        for(pair<int,int>& p: v){
            if(!go) break;
            int ele=p.first;
            int f=p.second;
            while(idx<numv.size() and numv[idx]==ele){
                idx++;
                f--;
            }
            if(f==0) continue;
            //numv[idx]!=ele..
            //5 9 9 -> 9 5 9 or 9 9 5 -> swap with the last occurence..
            for(int st=numv.size()-1;st>=0;st--){
                if(numv[st]==ele){
                    swap(numv[idx],numv[st]);
                    go=false;
                    break;
                }
            }
        }
        int ret=0;
        for(int i: numv) ret=ret*10+i;
        return ret;
    }
};