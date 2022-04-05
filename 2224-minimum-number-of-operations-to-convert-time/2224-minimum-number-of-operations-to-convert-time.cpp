class Solution {
public:
    int getMins(string s){
        int hrs=stoi(s.substr(0,2));
        int mins=stoi(s.substr(3));
        return hrs*60+mins;
    }
    int convertTime(string current, string correct) {
        int ans=0;
        int mins1=getMins(current);
        int mins2=getMins(correct);
    
        int diff=mins2-mins1;
        
        vector<int> v={1,5,15,60};
        
        int idx=v.size()-1,ops=0;
        while(diff){
            if(diff<v[idx]){
                idx--;
                continue;
            }
            while(diff>=v[idx]){
                diff-=v[idx];
                ops++;
            }
            idx--;
        }
        return ops;
    }
};