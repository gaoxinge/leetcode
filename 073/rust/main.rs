impl Solution {
    pub fn set_zeroes(matrix: &mut Vec<Vec<i32>>) {
        let m = matrix.len();
        let n = matrix[0].len();
        
        let mut is_first_col_zero = false;
        for i in 0..m {
            let e = matrix[i][0];
            if e == 0 {
                is_first_col_zero = true;
                break;
            }
        }

        let mut is_first_row_zero = false;
        for j in 0..n {
            let e = matrix[0][j];
            if e == 0 {
                is_first_row_zero = true;
                break;
            }
        }

        for i in 1..m {
            for j in 1..n {
                let e = matrix[i][j];
                if e == 0 {
                    matrix[i][0] = 0;                    
                    matrix[0][j] = 0;
                }
            }
        }

        for i in 1..m {
            let e = matrix[i][0];
            if e == 0 {
                for j in 0..n {
                    matrix[i][j] = 0;
                }
            }
        }

        for j in 1..n {
            let e = matrix[0][j];
            if e == 0 {
                for i in 0..m {
                    matrix[i][j] = 0;
                }
            }
        }

        if is_first_col_zero {
            for i in 0..m {
                matrix[i][0] = 0;
            }
        }

        if is_first_row_zero {
            for j in 0..n {
                matrix[0][j] = 0;
            }
        }
    }
}
