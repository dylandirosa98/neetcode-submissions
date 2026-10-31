class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        quickSort(points, 0, points.size() - 1, k);
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
private:
    void quickSort(vector<vector<int>>& points, int start, int end, int k){
        if (end - start <= 0 || k == end + 1){
            return;
        }
        int j {start};
        int p {distance(points[end])};
        for(int i {start}; i < end; i++){
            if (distance(points[i]) < p){
                vector<int> temp = points[i];
                points[i] = points[j];
                points[j] = temp;
                j++;
            }
        }

        std::swap(points[end], points[j]);

        if (k < j) {
            quickSort(points, start, j-1, k);
        } else
        quickSort(points, j + 1, end, k);
    }

    int distance(vector<int> point){
        return std::pow(point[0], 2) + std::pow(point[1], 2);
    }
};
