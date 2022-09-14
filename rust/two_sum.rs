use std::collections::HashMap;

pub struct Solution{}

impl Solution{
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32>{
        let mut hash: HashMap<i32, i32> = HashMap::new();

        for (i, num) in nums.iter().enumerate(){
            
            if let Some(&start) = hash.get(&(target - num)){
                return vec![start, i as i32];
            }else{
                hash.insert(*num, i as i32);
            }
        }
        vec![]
    }
}

fn main(){
    print!("{:?}", Solution::two_sum(vec![2,7,11,15], 9));
    print!("{:?}", Solution::two_sum(vec![3,2,4], 6));
    
}