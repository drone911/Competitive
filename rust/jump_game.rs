use std::cmp;

pub struct Solution;

impl Solution {
    pub fn jump(nums: Vec<i32>) -> i32 {
        let len = nums.len() as i32;
        if len ==1 {
            return 0;
        }
        if len == 2 || nums[0]>=len-1{
            return 1;
        }
        let mut start = 1;
        let mut end = nums[0];
        let mut jumps = 1;
        while true {
            let prev_end = end;
            for i in start..end+1 {
                end = cmp::max(end, i + nums[i as usize]);
            }
            jumps=jumps+1;
            if end>=len-1 {
                break;
            }
            start = prev_end + 1;
        }
        jumps
    }
}

fn main() {
    assert_eq!(Solution::jump(vec![0]), 0);
    assert_eq!(Solution::jump(vec![1, 1]), 1);
    assert_eq!(Solution::jump(vec![2]), 0);
    assert_eq!(Solution::jump(vec![2, 1, 1]), 1);
    assert_eq!(Solution::jump(vec![1, 1, 1]), 2);
    assert_eq!(Solution::jump(vec![2, 1, 1]), 1);
    assert_eq!(Solution::jump(vec![2, 3, 1, 1, 4]), 2);
    assert_eq!(Solution::jump(vec![2, 3, 0, 1, 4]), 2);
    assert_eq!(Solution::jump(vec![2, 5, 3, 6, 2, 3, 4, 5]), 3);
}