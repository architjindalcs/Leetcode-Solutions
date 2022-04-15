class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int cnt[10];
        memset(cnt,0,sizeof(cnt));
        for(int d: digits){
            cnt[d]++;
        }
        
        vector<int> ans;
        
        
        for(int fdig=1;fdig<=9;fdig++){
            for(int sdig=0;sdig<=9;sdig++){
                for(int tdig=0;tdig<=8;tdig+=2){
                    int num=fdig*100+sdig*10+tdig;
           
                    if(fdig==sdig and sdig==tdig){
                        //all three are equal..
                        if(cnt[fdig]>=3) {
                            int f=1;
                            while(f--) ans.push_back(num);
                        }
                    }
                    else if(fdig==sdig){
                        if(cnt[fdig]>=2 and cnt[tdig]){
                            int f=1;
                            while(f--) ans.push_back(num);
                        }
                    }
                    else if(sdig==tdig){
                        if(cnt[sdig]>=2 and cnt[fdig]){
                            int f=1;
                            while(f--) ans.push_back(num);
                        }
                    }
                    else if(fdig==tdig and cnt[sdig]){
                        if(cnt[fdig]>=2){
                            int f=1;
                            while(f--) ans.push_back(num);
                        }
                    }
                    else{
                        //all are unequal..
                        int minm=min(1,min(cnt[fdig],min(cnt[sdig],cnt[tdig])));
                        int num=fdig*100+sdig*10+tdig;
                        while(minm--) ans.push_back(num);
                    }
                }
            }
        }
        
        return ans;
    }
};