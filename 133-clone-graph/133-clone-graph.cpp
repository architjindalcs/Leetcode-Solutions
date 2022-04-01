/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node*> map;
    Node* dfs(Node* node){
        if(!node) return NULL;
        Node* nn=new Node(node->val);
        map[node]=nn;
        for(Node* nei: node->neighbors){
            if(map.count(nei)) nn->neighbors.push_back(map[nei]);
            else{
                dfs(nei);
                nn->neighbors.push_back(map[nei]);
            }
        }
        return nn;
    }
    Node* cloneGraph(Node* node) {
        return dfs(node);
    }
};