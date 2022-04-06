class Encrypter {
public:
   // unordered_set<string> permittedAfterDecryption;
    unordered_map<char,string> charToString;
    unordered_map<string,int> perm;
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        for(int i=0;i<keys.size();i++){
            charToString[keys[i]]=values[i];
        }
        for(string& s: dictionary) perm[encrypt(s)]++;
    }
    
    string encrypt(string word1) {
        string ans="";
        for(char ch: word1) {
            if(!charToString.count(ch)) return "";
            ans+=(charToString[ch]);
        }
        return ans;
    }
    
   
    int decrypt(string word2) {
        return perm[word2];
    }
};
