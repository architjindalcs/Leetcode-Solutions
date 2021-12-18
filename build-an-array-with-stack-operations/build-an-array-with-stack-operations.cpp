class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
       vector<string> ans;
        int ele=1;
        for(int i=0;i<target.size();i++){
            if(target[i]==ele){
                ans.push_back("Push");
                ele++;
            }
            else{
                while(ele!=target[i]){
                    ans.push_back("Push");
                    ans.push_back("Pop");
                    ele++;
                }
                ans.push_back("Push");
                ele++;
            }
        }
        return ans;
    }
};