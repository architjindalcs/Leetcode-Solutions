class TrieNode{
    public:
    char ch;
    vector<TrieNode*> children;
    bool terminal;
    int traversed;
    TrieNode(char ch){
        this->ch=ch;
        children=vector<TrieNode*> (256,NULL);
        terminal=false;
        traversed=1;
    }
};
class Solution {
public:
    void insert(TrieNode* root,string& s){
        TrieNode* temp=root;
        for(char ch: s){
            if(temp->children[ch]){
                temp=temp->children[ch];
                (temp->traversed)++;
            }
            else{
                TrieNode* nn=new TrieNode(ch);
                temp->children[ch]=nn;
                temp=temp->children[ch];
            }
        }
        temp->terminal=true;
    }  
    string helper(TrieNode* root,string s){
        string cs="";
        TrieNode* temp=root;
        for(char ch: s){
            if(!(temp->children[ch])) break;
            cs+=ch;
            temp=temp->children[ch];
            if(temp->terminal) return cs;
        }
        return s;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        TrieNode* root=new TrieNode('\0');
        for(string& s: dictionary) insert(root,s);
        string ans="";
        
        string cs="";
        for(char ch: sentence){
            if(ch==' '){
                ans+=helper(root,cs)+" ";
                cs="";
            }
            else cs+=ch;
        }
        ans+=helper(root,cs);
        return ans;
    }
};