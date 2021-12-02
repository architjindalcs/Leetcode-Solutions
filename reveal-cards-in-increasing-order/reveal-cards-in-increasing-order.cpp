class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        int i=0,j=0;
        int n=deck.size();
        bool filled[n];
        memset(filled,false,sizeof(filled));
        vector<int> res(n);
        bool skip=false;
        while(i<deck.size()){
            /*
                2,3,5,7,11,13,17
                        i
                2 13 3 11 5 17 7  -> fill
            */
            if(filled[j]){
                j=(j+1)%n;
                continue;
            }
            if(skip){
                skip=false;
            }
            else{
                skip=true;
                res[j]=deck[i++];
                filled[j]=true;
            }
            j=(j+1)%n;
        }
        return res;
    }
};