class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        vector<pair<int,int>> v;
        /*
            stone1-> a1,b1
            stone2-> a2,b2
            
            Alice- 
            stone1 -> a1-b2
            stone2 -> a2-b1
            
            stone1>stone2 -> a1+b1>a2+b2;
        */
        for(int i=0;i<aliceValues.size();i++)
            v.push_back({aliceValues[i],bobValues[i]});
        sort(v.begin(),v.end(),[&](pair<int,int>& p1,pair<int,int>& p2){
           return p1.first+p1.second>p2.first+p2.second; 
        });
        int alice=0,bob=0;
        bool f=true;
        for(auto p: v){
            if(f)
            alice+=p.first;
            else
            bob+=p.second;
            f=!(f);
        }
        return alice==bob? 0: (alice>bob? 1 : -1);
    }
};