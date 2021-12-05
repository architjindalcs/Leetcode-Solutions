class BrowserHistory {
public:
    stack<string> future;
    stack<string> past;
    BrowserHistory(string homepage) {
        past.push(homepage);
    }
    
    void visit(string url) {
        past.push(url);
        while(future.size()) future.pop();
    }
    
    string back(int steps) {
        //a.com(h) ,                      b.com,c.com
        while(past.size()>1 and steps){
            future.push(past.top());
            past.pop();
            steps--;
        }
        return past.top();
    }
    
    string forward(int steps) {
        while(future.size() and steps){
            past.push(future.top());
            future.pop();
            steps--;
        }
        return past.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */