impl Solution {
    pub fn spiral_order(matrix: Vec<Vec<i32>>) -> Vec<i32> {
        let (mut left, mut top, mut right, mut bottom) = (-1, -1, matrix[0].len() as i32, matrix.len() as i32);
        let mut direction = 2;
        let (mut i, mut j) = (0, 0);
        let mut result = Vec::new();
        while left + 1 < right && top + 1 < bottom {
            result.push(matrix[i as usize][j as usize]);
            match direction {
                0 => j -= 1,
                1 => i -= 1,
                2 => j += 1,
                3 => i += 1,
                _ => ()
            }
            if j == left {
                bottom -= 1;
                direction = 1;
                i -= 1;
                j += 1;
            } else if i == top {
                left += 1;
                direction = 2;
                i += 1;
                j += 1;
            } else if j == right {
                top += 1;
                direction = 3;
                i += 1;
                j -= 1;
            } else if i == bottom {
                right -= 1;
                direction = 0;
                i -= 1;
                j -= 1;
            }
        }
        return result;
    }
}
