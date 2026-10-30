class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i{};
        int j{};
        int k{};
        vector<int> ogvect = nums1;
        while (i < m && j < n){
            if (ogvect[i] <= nums2[j]){
                nums1[k] = ogvect[i];
                i++;
            }else{
                nums1[k] = nums2[j];
                j++;
            }
            k++;
        }
        while (i < m){
            nums1[k] = ogvect[i];
            i++;
            k++;
        }
        while (j < n){
            nums1[k] = nums2[j];
            j++;
            k++;
        }
    }
};