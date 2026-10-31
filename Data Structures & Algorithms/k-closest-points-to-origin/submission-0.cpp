class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        quickSort(points, 0, points.size() - 1);
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
private:
    void quickSort(vector<vector<int>>& points, int start, int end){
        if (end - start <= 0){
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

        vector<int> temp = points[end];
        points[end] = points[j];
        points[j] = temp;

        quickSort(points, start, j -1);
        quickSort(points, j + 1, end);
    }

    int distance(vector<int> point){
        return std::pow(point[0], 2) + std::pow(point[1], 2);
    }
};
