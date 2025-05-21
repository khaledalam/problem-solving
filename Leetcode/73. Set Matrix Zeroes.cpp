class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // Khaled Alam <khaledalam.net@gmail.com>
        set<int>r, c;
        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[i].size(); j++) {
                if (matrix[i][j] == 0) {
                    r.insert(i);
                    c.insert(j);
                }
            }
        }
        for(const int& row: r) {
             for(int j=0; j<matrix[row].size(); j++) {
                matrix[row][j] = 0;
             }
        }
        for(const int& column: c) {
             for(int i=0; i<matrix.size(); i++) {
                matrix[i][column] = 0;
             }
        }
    }
};
