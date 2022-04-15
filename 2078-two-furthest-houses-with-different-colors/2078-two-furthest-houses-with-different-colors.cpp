class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int dist1,dist2=INT_MIN;
        int n=colors.size();
        int fhouse=colors[0],lhouse=colors.back();
        for(int i=0;i<colors.size();i++){
            if(colors[i]!=fhouse) dist1=i;
            if(colors[i]!=lhouse) {
                dist2=max(dist2,n-1-i);
            }
        }
        return max(dist1,dist2);
    }
};