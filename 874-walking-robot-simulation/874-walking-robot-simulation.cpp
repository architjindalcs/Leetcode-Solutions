class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int maxm=0;
        unordered_set<string> obs;
        for(vector<int>& v: obstacles){
            string tmp=to_string(v[0])+"#"+to_string(v[1]);
            obs.insert(tmp);
        }
        int x=0,y=0;
        char dir='N';
        for(int c: commands){
            int px=x,py=y;
            if(c==-2){
                if(dir=='N') dir='W';
                else if(dir=='S') dir='E';
                else if(dir=='W') dir='S';
                else if(dir=='E') dir='N';
            } 
            else if(c==-1){
                if(dir=='N') dir='E';
                else if(dir=='S') dir='W';
                else if(dir=='W') dir='N';
                else dir='S';
            }
            else{
                if(dir=='N') {
                    int cnt=0;
                    while(cnt<c){
                        int px=x,py=y;
                        y++;
                        string tmp=to_string(x)+"#"+to_string(y);
                        if(obs.count(tmp)){
                            x=px;
                            y=py;
                            break;
                        }
                        cnt++;
                    }
                }
                else if(dir=='S'){
                    int cnt=0;
                    while(cnt<c){
                        int px=x,py=y;
                        y--;
                        string tmp=to_string(x)+"#"+to_string(y);
                        if(obs.count(tmp)){
                            x=px;
                            y=py;
                            break;
                        }
                        cnt++;
                    }
                }
                else if(dir=='E') {
                    int cnt=0;
                    while(cnt<c){
                        int px=x,py=y;
                        x++;
                        string tmp=to_string(x)+"#"+to_string(y);
                        if(obs.count(tmp)){
                            x=px;
                            y=py;
                            break;
                        }
                        cnt++;
                    }
                }
                else {
                    int cnt=0;
                    while(cnt<c){
                        int px=x,py=y;
                        x--;
                        string tmp=to_string(x)+"#"+to_string(y);
                        if(obs.count(tmp)){
                            x=px;
                            y=py;
                            break;
                        }
                        cnt++;
                    }
                }
            }
            maxm=max(maxm,x*x+y*y);

        }
        return maxm;
    }
};