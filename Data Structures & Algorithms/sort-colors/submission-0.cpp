class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> colors = {0,0,0};
        for(int i {}; i < nums.size(); i++){
            colors[nums[i]]++;
        }

        int i {};
        for (int j{}; j < colors.size(); j++){
            for(int k{}; k < colors[j]; k++){
                nums[i] = j;
                i++;
            }
        }
    }
};