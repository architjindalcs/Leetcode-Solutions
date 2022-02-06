class Solution {
public:
    long long smallestNumber(long long num) {
        if(!num) return 0;
        vector<int> v;
        long long temp=num;
        bool neg=false;
        if(temp<0) {
            neg=true;
            temp=-temp;
        }
        while(temp) {
            v.push_back(temp%10);
            temp/=10;
        }
        sort(v.begin(),v.end());
        if(v.back()==0) return 0;  //zero hi h number..
        if(neg){
            long long ans=0;
            for(int i=v.size()-1;i>=0;i--){
                ans=ans*10+v[i];
            }
            return -ans;
        }
        //0,1,3 
        int i=0;
        int cnt=0;
        while(i<v.size() and v[i]==0){
            cnt++;
            i++;
        }
        long long ans=v[i];
        i++;
        while(cnt--){
            ans=ans*10;
        }
        while(i<v.size()){
            ans=ans*10+v[i++];
        }
        return ans;
    }
};