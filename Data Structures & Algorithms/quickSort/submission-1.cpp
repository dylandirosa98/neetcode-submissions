// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    vector<Pair> quickSort(vector<Pair>& pairs) {
        privSort(pairs, pairs.size()-1, 0);
        return pairs;
    }
private:
    void privSort(vector<Pair>& pairs, int high, int low){
        if (high - low <= 0){
            return;
        }
        int k {high};
        int pivot {pairs[k].key};
        int j {low};
        for(int i {j}; i < k; i++){
            if (pairs[i].key < pivot) {
                Pair temp = pairs[j];
                pairs[j] = pairs[i];
                pairs[i] = temp;
                j++;
            }
        }
        Pair temp = pairs[k];
        pairs[k] = pairs[j];
        pairs[j] = temp;

        privSort(pairs, j-1, low);
        privSort(pairs, k, j+1);
    }
};
