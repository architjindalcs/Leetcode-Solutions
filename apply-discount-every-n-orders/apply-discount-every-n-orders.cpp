class Cashier {
public:
    int cnt=1;
    int nval;
    double disc;
    unordered_map<int,int> m;
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        nval=n; disc=discount;
        for(int i=0;i<products.size();i++){
            m[products[i]]=prices[i];
        }
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        double ans=0;
        for(int i=0;i<product.size();i++){
            ans+=(amount[i]*m[product[i]]);
        }
        if(cnt==nval){
            cnt=1;
            return ans*((100-disc)/100.0);
        }
        cnt++;
        return ans;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */