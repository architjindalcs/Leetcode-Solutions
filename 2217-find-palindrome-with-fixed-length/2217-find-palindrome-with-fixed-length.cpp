class Solution {
public:
    long long getRev(long long k,int len){
        if(len&1) k/=10;
        //123 
        long long ans=0;
        while(k){
            ans=ans*10+(k%10);
            k/=10;
        }
        return ans;
    }
    int getD(int n){
        int cnt=0;
        while(n){
            cnt++;
            n/=10;
        }
        return cnt;
    }
    vector<long long> kthPalindrome(vector<int>& queries, int length) {
        /*
            len=15, len=14
            len=15
            
            len=6, len = 7
            
            len=6 ->  1 0 0 _ _ _ 
            
            1st -> 100 (rev(100))
            2nd -> 101 (rev(101))
            
            100th -> 199 (rev(199))
            
            
            101 -> 200 rev(200)
            
            
            len=7
            
            1st 1 0 0 0 [rev(100)]
            2nd 1 0 0 1 [rev(100)]
            3rd 
            _ _ _ _ _ _ _ [] _ _ _ _ _ _ _ 
        */
       
        int req=(length/2);
        
        //helper(v,0,req);
        
        
        vector<long long> ret;
        for(int q: queries){
            long long ans=0;
            long long initials=pow(10,(length%2==0? ((length/2)-1) : (length/2) ));
            //1000
            int oldd=getD(initials);
            initials+=(q-1);
            int newd=getD(initials);
            if(oldd!=newd){
                ret.push_back(-1);
                continue;
            }
            //initials+ append(reverse(initials));
            /* 
               len=4 , 2
               _ _ , _ _ 
               len=5
               _,_,_ [_,_]
            */ 
            
            long long rev=getRev(initials,length);
            ans= initials*(pow(10,length/2)) + rev;
            ret.push_back(ans);
        }
        return ret;
        
    }
};