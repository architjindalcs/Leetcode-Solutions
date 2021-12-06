class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ans;
        string tmp="";
        sort(products.begin(),products.end());
        for(char ch: searchWord){
            tmp+=ch;
            auto it=lower_bound(products.begin(),products.end(),tmp);
            if(it==products.end()){
                ans.push_back({});
                continue;
            }
            int cnt=0;
            vector<string> v;
          for(int i=0;i<3 and (it+i<products.end());i++)
            {
                if((*(it+i)).find(tmp)!=string::npos)
                {
                    v.push_back(*(it+i));
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};