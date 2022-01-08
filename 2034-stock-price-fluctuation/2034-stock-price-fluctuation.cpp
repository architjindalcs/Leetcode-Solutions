class StockPrice {
public:
    multiset<int> prices;
    map<int,int> rec;
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if(rec.count(timestamp)){
            prices.erase(prices.find(rec[timestamp]));
        }
        rec[timestamp]=price;  //this is the price at current timestamp..
        
        prices.insert(price);
    }
    
    int current() {
        return rec.rbegin()->second;  
    }
    
    int maximum() {
        auto it=prices.end();
        it--;
        return *it;
    }
    
    int minimum() {
        return *(prices.begin());
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */