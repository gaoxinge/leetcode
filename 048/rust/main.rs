impl Solution {
    fn rotateAxis(axis: (usize, usize), n: usize) -> (usize, usize) {
        let (i, j) = axis;
        return (j, n - 1 - i);
    }

    fn generate(axis: (usize, usize), n: usize) -> Vec<(usize, usize)> {
        let (i, j) = axis;
        if n % 2 == 1 && i == n / 2 && j == n / 2 {
            return vec![(i, j)];
        }
        let mut res = Vec::new();
        let mut axis = (i, j);
        res.push(axis);
        for _ in 0..3 {
            axis = Solution::rotateAxis(axis, n);
            res.push(axis);
        }
        return res;
    }

    fn swap0(matrix: &mut Vec<Vec<i32>>, axis1: (usize, usize), axis2: (usize, usize)) {
        let (i1, j1) = axis1;
        let (i2, j2) = axis2;
        let t = matrix[i1][j1];
        matrix[i1][j1] = matrix[i2][j2];
        matrix[i2][j2] = t; 
    }

    fn swap(matrix: &mut Vec<Vec<i32>>, axiss: &Vec<(usize, usize)>) {
        if axiss.len() == 1 {
            return;
        }
        Solution::swap0(matrix, axiss[0], axiss[3]);
        Solution::swap0(matrix, axiss[3], axiss[2]);
        Solution::swap0(matrix, axiss[2], axiss[1]);
    }

    pub fn rotate(matrix: &mut Vec<Vec<i32>>) {
        let n = matrix.len();
        for i in 0..n / 2 {
            for j in i..n - 1 - i {
                let axiss = Solution::generate((i, j), n);
                Solution::swap(matrix, &axiss);
            }
        }
    }
}
