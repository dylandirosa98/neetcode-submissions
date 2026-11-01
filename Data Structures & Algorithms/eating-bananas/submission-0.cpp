class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int r {*std::max_element(piles.begin(), piles.end())};
        int l { 1 };
        int m {};
        if (h == piles.size()){
            return r;
        }
        while(l < r){
            m = (r + l)/2;
            int numHours {hours(piles, m)};
            if (numHours > h){
                l = m + 1;
            } else if (numHours <= h){
                r = m;
            }
        }
        if (hours(piles, m) <= h){
            return m;
        }
        return r;
    }

private:
    int hours(vector<int>& piles, int k){
        int hours {};
        for (int i {}; i < piles.size(); i++){
            double factor { static_cast<double>(piles[i]) / k};
            int f { piles[i] / k};
            if (factor > f){
                hours += f + 1;
            } else {
                hours += f;
            }
        }
        return hours;
    }
};
