class MedianFinder {
public:
    priority_queue<int> maxH;
    priority_queue<int,vector<int>,greater<int> > minH;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxH.empty() or num<maxH.top()){
            maxH.push(num);
        }
        else minH.push(num);
        
        int minHSize=minH.size(),maxHSize=maxH.size();
        if(minHSize-maxHSize>1){
            maxH.push(minH.top());
            minH.pop();
        }
        else if(maxHSize-minHSize>1){
            minH.push(maxH.top());
            maxH.pop();
        }
    }
    
    double findMedian() {
        return minH.size()==maxH.size()? (minH.top()+maxH.top())/2.0 : 
        (minH.size()>maxH.size()? minH.top(): maxH.top());
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */