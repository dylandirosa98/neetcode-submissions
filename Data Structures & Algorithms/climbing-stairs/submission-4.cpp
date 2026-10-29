class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        int total {};
        int prevtotal{2};
        int prevprevtotal {1};
        for(int i {3}; i <= n; i++){
            total = prevtotal + prevprevtotal;
            int temp = prevtotal;
            prevtotal = total;
            prevprevtotal = temp;
        }
        return total;
    }
};
