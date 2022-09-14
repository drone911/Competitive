pub struct Solution;

use std::cmp::max;
const MOD: i32 = 1000000007;

impl Solution {
    pub fn max_area(h: i32, w: i32, horizontal_cuts: Vec<i32>, vertical_cuts: Vec<i32>) -> i32 {
        let mut horizontal_cuts = horizontal_cuts;
        let mut vertical_cuts = vertical_cuts;
        horizontal_cuts.insert(0, 0);
        horizontal_cuts.push(h);
        vertical_cuts.insert(0, 0);
        vertical_cuts.push(w);
        horizontal_cuts.sort_unstable();
        vertical_cuts.sort_unstable();
        let mut max_h_distance = 1;
        let mut max_w_distance = 1;
        for i in horizontal_cuts.windows(2) {
            max_h_distance = (max(max_h_distance, i[1] - i[0])) % MOD;
        }
        for i in vertical_cuts.windows(2) {
            max_w_distance = (max(max_w_distance, i[1] - i[0])) % MOD;
        }
        return ((max_h_distance as i64 * max_w_distance as i64) % MOD as i64) as i32;
    }
}

fn main() {
    assert_eq!(Solution::max_area(1000000000, 1000000000, vec![2], vec![2]), 81)
}
