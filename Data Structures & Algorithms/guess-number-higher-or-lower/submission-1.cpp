/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int i {1};

        while(true){
            int m {(i+n)/2};

            if(guess(m) < 0){
                i = m + 1;
            } else if (guess(m) > 0){
                n = m - 1;
            } else {
                return m;
            }
        }
    }
};