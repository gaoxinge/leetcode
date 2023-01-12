impl Solution {
    pub fn find_median_sorted_arrays(nums1: Vec<i32>, nums2: Vec<i32>) -> f64 {
        let len1 = nums1.len();
        let len2 = nums2.len();
        let len = len1 + len2;
        let half = len / 2;
        let isOdd = len % 2 == 1;
        let mut lastVal = 0;

        let (mut i, mut j, mut k) = (0, 0, 0);
        while i < len1 || j < len2 {
            let val;
            if i < len1 && j >= len2 {
                val = nums1[i];
                i += 1; 
            } else if i >= len1 && j < len2 {
                val = nums2[j];
                j += 1;
            } else {
                let val1 = nums1[i];
                let val2 = nums2[j];
                if (val1 <= val2) {
                    val = val1;
                    i += 1;
                } else {
                    val = val2;
                    j += 1;
                }
            }

            if isOdd {
                if k == half {
                    return val.into();
                }
            } else {
                if k == half - 1 {
                    lastVal = val;
                } else if k == half {
                    return (lastVal + val) as f64 / 2.0;
                }
            }
            
            k += 1;
        }

        return 0.0;
    }
}
