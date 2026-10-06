class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const vector<int>* A = &nums1;
        const vector<int>* B = &nums2;
        if (A->size() > B->size()) swap(A, B); // 在较短数组中二分

        int m = static_cast<int>(A->size());
        int n = static_cast<int>(B->size());
        int leftCount = (m + n + 1) / 2;

        int lo = 0, hi = m;
        while (lo <= hi) {
            int i = lo + (hi - lo) / 2; // A 左边放 i 个
            int j = leftCount - i;      // B 左边放 j 个

            int Aleft  = (i == 0) ? INT_MIN : (*A)[i - 1];
            int Aright = (i == m) ? INT_MAX : (*A)[i];
            int Bleft  = (j == 0) ? INT_MIN : (*B)[j - 1];
            int Bright = (j == n) ? INT_MAX : (*B)[j];

            if (Aleft <= Bright && Bleft <= Aright) {
                if ((m + n) % 2 == 1) {
                    return max(Aleft, Bleft);
                }
                return (static_cast<double>(max(Aleft, Bleft)) +
                        min(Aright, Bright)) / 2.0;
            }

            if (Aleft > Bright) {
                hi = i - 1; // A 左边放多了
            } else {
                lo = i + 1; // A 左边放少了
            }
        }

        return 0.0; // 题目保证输入有效，不会执行到这里
    }
};