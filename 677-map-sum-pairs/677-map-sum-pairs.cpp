class TrieNode{
    public:
    char ch;
    vector<TrieNode*> children;
    bool terminal;
    int traversed;
    TrieNode(char ch){
        this->ch=ch;
        children=vector<TrieNode*> (26,NULL);
        terminal=false;
        traversed=0;
    }
};
void insert(TrieNode* root,string& s){
    TrieNode* temp=root;
    for(char ch: s){
        int c=ch-'a';
        if(temp->children[c]) {
            temp=temp->children[c];
            (temp->traversed)++;
        }
        else{
            TrieNode* nn = new TrieNode(ch);
            temp->children[c]=nn;
            temp=temp->children[c];
        }
    }
    temp->terminal=true;
}
class MapSum {
public:
    unordered_map<string,int> mp;
    TrieNode* root;
    MapSum() {
        root=new TrieNode('\0');
    }
    
    void insert(string key, int val) {
        int sub=(mp.count(key)? mp[key]: 0);
        mp[key]=val;
        TrieNode* temp=root;
        for(char ch: key){
            int c=ch-'a';
            if(temp->children[c]){
                temp=temp->children[c];
                (temp->traversed)+=(val-sub);
            }
            else{
                TrieNode* nn=new TrieNode(ch);
                temp->children[c]=nn;
                nn->traversed=(val);
                temp=nn;
            }
        }
        temp->terminal=true;
    }
    
    int sum(string prefix) {
        TrieNode* temp=root;
        int ans;
        for(char ch: prefix){
            int c=ch-'a';
            if(!(temp->children[c])) return 0;
            temp=temp->children[c];
        }
        return temp->traversed;
    }
};
