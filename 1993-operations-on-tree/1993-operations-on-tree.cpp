class LockingTree {
public:
    vector<int> locked;
    vector<bool> unlocked;
    vector<int> parent;
    unordered_map<int,vector<int>> adj;
    LockingTree(vector<int>& parent) {
        int n=parent.size();
        locked=vector<int> (n,-1);
        unlocked=vector<bool> (n,true);  //initially all are unlocked..
        this->parent=parent;
        for(int i=0;i<parent.size();i++){
            if(parent[i]!=-1) adj[parent[i]].push_back(i);
        }
    }
    
    bool lock(int num, int user) {
        if(!unlocked[num]) return false;
        unlocked[num]=false;
        locked[num]=user;
        return true;
    }
    
    bool unlock(int num, int user) {
        if(!(locked[num]==user)) return false;
        locked[num]=-1;  //it is unlocked now..
        unlocked[num]=true;
        return true;
    }
    
    bool check(int i){
        if(i==-1) return true;
        if(locked[i]!=-1) return false;
        return check(parent[i]);
    }
    
    void helper(int src,int& cnt){
        if(locked[src]!=-1){
            cnt++;
            locked[src]=-1;    
            unlocked[src]=true;
        }
        for(int i: adj[src]){
            helper(i,cnt);
        } 
    }
    bool upgrade(int num, int user) {
        if(!unlocked[num]) return false;  //conditoon 1 gone wrong..
        if(!check(num)) return false;  //condition 3 gone wrong..
        int cnt=0;
        for(int i: adj[num]){
            helper(i,cnt);
        }
        if(cnt==0) return false;
        
        locked[num]=user;
        unlocked[num]=false;
        return true;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */