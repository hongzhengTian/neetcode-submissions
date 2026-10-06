class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        while (left < right) {
            int mid = left + (right - left) / 2;
            long long hours = 0;

            for (int pile : piles) {
                hours += (pile - 1LL) / mid + 1; // ceil(pile / mid)
            }

            if (hours <= h) {
                right = mid;      // mid 可行，但可能还能更慢
            } else {
                left = mid + 1;   // mid 不可行，必须更快
            }
        }

        return left;
    }
};