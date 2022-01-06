class ProductOfNumbers {
public:
    vector<int> pre;
    int pro=1;
    int lidxZero=-1;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(num==0){
            lidxZero=pre.size();  
            pre.push_back(1);
            //0,1,2
            //1,1,2
            return;
        }
        if(pre.empty()){
            pre.push_back(num);
        }
        else {
            pre.push_back(pre.back()*num);
        }
    }
    
    int getProduct(int k) {
        int end=pre.size()-1;
        int st=end-k+1;  //end=3 , st= 3-2+1
        if(st<=lidxZero) return 0;
        
        return (pre[end]/(st? pre[st-1]: 1));
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */