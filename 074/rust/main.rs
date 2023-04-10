impl Solution {
    pub fn search_matrix(matrix: Vec<Vec<i32>>, target: i32) -> bool {
        let m = matrix.len();
        let n = matrix[0].len();

        let mut i = 0;
        let mut j = m * n;
        while i + 1 < j {
            let k = i + (j - i) / 2;
            let t = matrix[k / n][k % n];
            if t == target {
                return true;
            }
            if t < target {
                i = k;
            } else {
                j = k;
            }
        }

        return matrix[i / n][i % n] == target;
    }
}
