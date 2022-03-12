class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int f[26];
        memset(f,0,sizeof(f));
        for(char ch: tasks) f[ch-'A']++;
        sort(f,f+26,greater<int>());
        int idle=(f[0]-1)*n;
        //idle represents the idle slots..
        for(int i=1;i<26 and f[i];i++){
            //f[0]-1 is taken due to case like 5,5,5,4,4,4
            idle-=min(f[0]-1,f[i]);
        }
        //max(0,idle) is taken in case idle becomes negative..also if idle becomes negative
        //no issues, after tasks.size() time, all the tasks can be run one after other..
        return max(0,idle)+tasks.size();
    }
};