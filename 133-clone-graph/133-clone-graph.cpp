class Solution {
public:
    unordered_map<Node*,Node*> map;
    Node* dfs(Node* node){
        if(!node) return NULL;
        Node* nn=new Node(node->val);
        map[node]=nn;  //kind of marking as visited..
        for(Node* nei: node->neighbors){
            if(map.count(nei)) {
                //visited case, value is already present in map, directly push to neighbors the mapped value
                nn->neighbors.push_back(map[nei]);
            }
            else{
                //not visited case, make a dfs call, to simulate the further process..
                dfs(nei);
                //now we may use map[nei], as mapping would have been created already.
                nn->neighbors.push_back(map[nei]);
            }
        }
        return nn;
    }
    Node* cloneGraph(Node* node) {
        return dfs(node);
    }
};
