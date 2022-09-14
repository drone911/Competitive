use std::cmp::max;
pub struct Solution;

impl Solution {
    pub fn max_sub_array(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut i = 0;
        let mut soln = nums[0];
        while i<n && nums[i] <= 0 {
            soln = max(nums[i], soln);
            i=i+1;
        }
        if i==n {
            return soln;
        }
        soln = nums[i];
        let mut curr = nums[i];
        i = i+1;
        while i<n {
            curr = curr + nums[i];
            if nums[i] >= soln 
            if curr+nums[i]>=soln {
                soln = curr + nums[i];
            }
            curr = curr + nums[i];
            i = i+1;
        }
        soln
    }
}

pub fn main() {
    assert_eq!(Solution::max_sub_array(vec![0]), 0);
    assert_eq!(Solution::max_sub_array(vec![-2]), -2);
    assert_eq!(Solution::max_sub_array(vec![2]), 2);
    assert_eq!(Solution::max_sub_array(vec![-2, -3]), -2);
    assert_eq!(Solution::max_sub_array(vec![-2, 0, -3]), 0);
    assert_eq!(Solution::max_sub_array(vec![-2, 0, 2]), 2);
    assert_eq!(Solution::max_sub_array(vec![2, 2]), 4);
    assert_eq!(Solution::max_sub_array(vec![1, 2]), 3   );
    assert_eq!(Solution::max_sub_array(vec![2, -2]), 2);
    assert_eq!(Solution::max_sub_array(vec![-4, -2]), -2);
    assert_eq!(Solution::max_sub_array(vec![5,4,-1,7,8]), 23);
    assert_eq!(Solution::max_sub_array(vec![-2,1,-3,4,-1,2,1,-5,4]), 6);
    
}