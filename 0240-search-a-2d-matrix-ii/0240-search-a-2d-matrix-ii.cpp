class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=matrix[0].size()-1;
        int j=0;
        while(i>=0 && j<matrix.size()){
            if(matrix[j][i]==target) return true;
            else if(matrix[j][i]<target) j++;
            else i--;
        }
        return false;

    }
};