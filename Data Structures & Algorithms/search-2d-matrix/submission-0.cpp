class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (int i {}; i < matrix.size(); i++){
            if (binarySearch(matrix[i], target) == true){
                return true;
            }
        }
        return false;
    }
private:
    bool binarySearch(vector<int>& row, int target){
        int l {0};
        int r {static_cast<int>(row.size()) - 1};

        while (l <= r){
            int m { (l+r)/2 };

            if (row[m] < target) {
                l = m + 1;
            }
            if (row[m] > target){
                r = m -1;
            }
            if (row[m] == target){
                return true;
            }
        }
        return false;
    }
};
