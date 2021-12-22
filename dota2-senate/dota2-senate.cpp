class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> qr,qd;
        for(int i=0;i<senate.size();i++){
            if(senate[i]=='R') qr.push(i);
            else qd.push(i);
        } 
        while(qr.size() and qd.size()){
            int rfr=qr.front(); qr.pop();
            int dfr=qd.front(); qd.pop();
            if(rfr<dfr){
                qr.push(rfr+senate.size());
            }
            else{
                qd.push(dfr+senate.size());
            }
        }
        return qr.size()? "Radiant": "Dire";
    }
};