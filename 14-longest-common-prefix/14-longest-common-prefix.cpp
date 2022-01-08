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
        traversed=1;
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
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        TrieNode* root=new TrieNode('\0');
        for(string& s: strs) insert(root,s);
        string cs="";
        int tval=strs.size();
        for(char ch: strs[0]){
            int c=ch-'a';
            if(root->children[c]==NULL) return cs;
          
            else if(root->children[c]->traversed!=tval){
              //    cout<<root->children[c]->traversed<<endl;
                return cs;
            }
            cs.push_back(ch);
            root=root->children[c];
        }
        return cs;
        
    }
};