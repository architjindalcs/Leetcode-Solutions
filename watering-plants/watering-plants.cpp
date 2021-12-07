class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int i=0;
        int steps=0;
        int ori=capacity;
        while(i<plants.size()){
            if(capacity>=plants[i]){
                capacity-=plants[i];
                steps++;
                i++;
            }
            else{
                capacity=ori;
                steps+=(2*i+1);
                capacity-=plants[i];
                i++;
            }
          //  cout<<steps<<endl;
        }
        return steps;
    }
};