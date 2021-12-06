class Bank {
public:
    vector<long long> acc;
    int siz;
    Bank(vector<long long>& balance) {
        int n=balance.size();
        siz=n;
        acc=vector<long long> (n+1,0);
        for(int i=0;i<n;i++){
            acc[i+1]=balance[i];
        }
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(!(account1>=1 and account1<=siz and account2>=1 and account2<=siz))
            return false;
        if(acc[account1]<money) return false;
        acc[account1]-=money;
        acc[account2]+=money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if(!(account>=1 and account<=siz)) return false;
        acc[account]+=money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(!(account>=1 and account<=siz)) return false;
        if(acc[account]<money) return false;
        acc[account]-=money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */