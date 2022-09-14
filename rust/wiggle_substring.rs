pub struct Solution;

impl Solution {
    pub fn wiggle_max_length(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        if n <= 2{
            return n as i32;
        }
        let mut result = 2;
        let mut i = 0;
        while i < n-1 {
            let mut diff = nums[i+1] - nums[i];
            let mut is_diff_pos: i32 = diff & 0x8000000;
            let mut j = i+1;
            while j < n-1 {
                diff = nums[j+1] - nums[j];
                if is_diff_pos == diff & 0x8000000 {
                    break;
                }else {
                    j+=1;                    
                    is_diff_pos = diff & 0x8000000;
                }
            }
            diff = (j - i) as i32 + 1;
            if diff > result{
                result = diff;
            }
            i = j;
        }
        result
    }
}

fn main() {
    assert_eq!(Solution::wiggle_max_length(vec![1]), 1);
    assert_eq!(Solution::wiggle_max_length(vec![1,2]), 2);
    assert_eq!(Solution::wiggle_max_length(vec![1,7,4,9,2,5]), 6);
    assert_eq!(Solution::wiggle_max_length(vec![1,2,3,4,5,6,7,8,9]), 2);
}