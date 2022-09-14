pub struct Solution;

impl Solution {
    pub fn candy(ratings: Vec<i32>) -> i32 {
        let len = ratings.len();
        if len == 1 {
            return 1;
        }
        if len == 2 {
            return if ratings[0] == ratings[1] {2} else {3};
        }
        let mut i = 0;
        let mut min_candies = len;
        let mut alloc_candies = vec![1; len];
        while i < len -1 {
            if ratings[i+1] - ratings[i] > 0 {
                alloc_candies[i+1] += alloc_candies[i];
                min_candies += alloc_candies[i];
            }
            i += 1;
        }
        while i > 0 {
            if ratings[i-1] - ratings[i] > 0 {
                if alloc_candies[i] >= alloc_candies[i-1] {
                    min_candies += alloc_candies[i] - alloc_candies[i-1] + 1;
                    alloc_candies[i-1] += alloc_candies[i] - alloc_candies[i-1] + 1;
                }
            } 
            i -= 1;
        }
        min_candies as i32
    }
}

fn main() {
    assert_eq!(Solution::candy(vec![1]), 1);
    assert_eq!(Solution::candy(vec![1,1]), 2);
    assert_eq!(Solution::candy(vec![1,2]), 3);
    assert_eq!(Solution::candy(vec![1,0,2]), 5);
    assert_eq!(Solution::candy(vec![1,2,1,0,5]), 9);
    assert_eq!(Solution::candy(vec![4,2,1,0,5]), 12);
    assert_eq!(Solution::candy(vec![2,3,4,1,1,5]), 10);
    assert_eq!(Solution::candy(vec![1,2,3,3,2]), 9);
    assert_eq!(Solution::candy(vec![1,2,3,1,0]), 9);
}