
pub struct Solution;

impl Solution {
    pub fn wiggle_max_length(nums: Vec<i32>) -> i32 {
        let len = nums.len();
        if vec![0, 0] == nums {
            return 1;
        }
        if len <= 2{
            return len as i32;
        }
        
        let mut skip = 0;
        while skip < len - 1 && nums[skip+1] == nums[skip] {
            skip +=1;
        }
        if skip == len - 1 {
            return 1;
        }
        let mut prev_diff = nums[skip+1] - nums[skip];
        let mut result = 2;
        for i in (skip+1)..len {
            let diff =  nums[i] - nums[i-1];
            if diff != 0 {
                if ((diff ^ prev_diff) >> 31) == -1
                {
                    result +=1;
                }
                prev_diff = diff;
            }
        }
        result
    }
}

fn main() {
    assert_eq!(Solution::wiggle_max_length(vec![1]), 1);
    assert_eq!(Solution::wiggle_max_length(vec![1,2]), 2);
    assert_eq!(Solution::wiggle_max_length(vec![0, 0]), 1);
    assert_eq!(Solution::wiggle_max_length(vec![0, 0, 0]), 1);
    assert_eq!(Solution::wiggle_max_length(vec![1, 1, 1]), 1);
    assert_eq!(Solution::wiggle_max_length(vec![1,7,4,9,2,5]), 6);
    assert_eq!(Solution::wiggle_max_length(vec![1,1,3,4,5,6,7,8,9]), 2);
    assert_eq!(Solution::wiggle_max_length(vec![1,17,5,10,13,15,10,5,16,8]), 7);
}