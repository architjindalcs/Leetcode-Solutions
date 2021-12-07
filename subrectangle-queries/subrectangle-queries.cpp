class SubrectangleQueries {
public:
    vector<vector<int>> updates;
    vector<vector<int>> grid;
    
    
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        grid=rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        updates.push_back({row1,col1,row2,col2,newValue});
    }
    
    int getValue(int row, int col) {
        for(int i=updates.size()-1;i>=0;i--){
            int r1=updates[i][0],c1=updates[i][1],r2=updates[i][2],c2=updates[i][3];
            if(row>=r1 and row<=r2 and col>=c1 and col<=c2)
                return updates[i].back();
        }
        return grid[row][col];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */