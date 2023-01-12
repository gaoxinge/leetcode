class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int len = len1 + len2;
        int half = len / 2;
        bool isOdd = len % 2 == 1;
        int lastVal;
        for (int i = 0, j = 0, k = 0; i < len1 || j < len2; k++) {
            int val;
            if (i < len1 && j >= len2) {
                val = nums1[i++];
            } else if (i >= len1 && j < len2) {
                val = nums2[j++];
            } else {
                int val1 = nums1[i];
                int val2 = nums2[j];
                if (val1 <= val2) {
                    val = val1;
                    i++;
                } else {
                    val = val2;
                    j++;
                }
            }

            if (isOdd) {
                if (k == half) {
                    return val;
                }
            } else {
                if (k == half - 1) {
                    lastVal = val;
                } else if (k == half) {
                    return (lastVal + val) / 2.0;
                }
            }
        }

        return 0;
    }
};
