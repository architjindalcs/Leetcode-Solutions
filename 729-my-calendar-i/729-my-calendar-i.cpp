class Node{
    public:
    int st,end;
    Node* left;
    Node* right;
    Node(int st,int end){
        this->st=st;
        this->end=end;
        left=NULL;
        right=NULL;
    }
};
Node* insert(Node* root,int st,int end){
    if(!root) return new Node(st,end); 
    if(end<root->st){
        root->left=insert(root->left,st,end);
        return root;
    }
    root->right=insert(root->right,st,end);
    return root;
}
bool check(Node* root,int st,int end){
    if(!root) return false; //it will return whether it is a clash or not..
    if(!(root->st>end or root->end<st))  //agr aisa h toh overlap h..
        return true;  //yes overlap krra h..
    if(root->st>end) {
        return check(root->left,st,end);
    }
    return check(root->right,st,end);
}
class MyCalendar {
public:
    Node* root;
 vector<pair<int,int>> v;
    
    MyCalendar() {
        root=NULL;
    }
    
    bool book(int st, int end) {
        end--;
       
        for(pair<int,int>& p: v){
            int pst=p.first,pend=p.second;
            if(!(pst>end or st>pend)) return false;
        }
        v.push_back({st,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */