class MedianFinder {
public:
    priority_queue<int> maxH;
    priority_queue<int,vector<int>,greater<int>> minH;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxH.empty() or num<maxH.top()) maxH.push(num);
        else minH.push(num);
        
        if(((int)minH.size()-(int)maxH.size())>1){
            //minH me jyada elements aa gye bhot..
            maxH.push(minH.top());
            minH.pop();
        }
        else if(((int)maxH.size()-(int)minH.size())>1) {
            minH.push(maxH.top());
            maxH.pop();
        }
        
    }
    
    double findMedian() {
        return minH.size()==maxH.size()? (minH.top()+maxH.top())/2.0 : 
        (minH.size()>maxH.size() ? minH.top() : maxH.top()); 
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */