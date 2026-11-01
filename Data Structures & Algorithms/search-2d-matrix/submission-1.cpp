class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l {0};
        int r {static_cast<int>(matrix.size()) - 1};

        while (l <= r){
            int m { (l+r)/2 };

            if (matrix[m][matrix[m].size() - 1] > target){
                r = m - 1;
            }
            if (matrix[m][0] < target){
                l = m + 1;
            }
            if (matrix[m][0] <= target 
            && matrix[m][matrix[m].size() -1] >= target){
                return binarySearch(matrix[m], target);
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
