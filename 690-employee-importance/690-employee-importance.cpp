/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    unordered_map<int,Employee*> m;
    int helper(Employee* e){
        if(!e) return 0;
        int ans=e->importance;
        for(int sub: e->subordinates) ans+=helper(m[sub]);
        return ans;
    }
    int getImportance(vector<Employee*> employees, int id) {
        for(auto& e: employees){
            m[e->id]=e;
        }
        return helper(m[id]);
    }
};