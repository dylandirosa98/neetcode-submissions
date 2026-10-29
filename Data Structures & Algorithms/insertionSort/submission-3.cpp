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
    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) {
        vector<vector<Pair>> stateofArray{};
        if (pairs.size() == 0){
            return stateofArray;
        }
        stateofArray.push_back(pairs);
        for(int i{}; i < pairs.size()-1; i++){
            int j = i;
            while(j >= 0 && pairs[j + 1].key < pairs[j].key){
                Pair temp = pairs[j];
                pairs[j] = pairs[j+1];
                pairs[j+1] = temp;
                j--;
            }
            stateofArray.push_back(pairs);
        }
        return stateofArray;
    }
};
