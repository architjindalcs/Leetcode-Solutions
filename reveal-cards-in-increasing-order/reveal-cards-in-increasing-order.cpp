class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        deque<int> dq;
        sort(deck.begin(),deck.end(),greater<int>());
        //5,3,2
        //5,3
        
        //dq -> 3,2,5
        dq.push_back(deck[0]);
        for(int i=1;i<deck.size();i++){
            dq.push_front(dq.back());
            dq.pop_back();
            dq.push_front(deck[i]);
        }
        return vector<int> (dq.begin(),dq.end());
    }
};