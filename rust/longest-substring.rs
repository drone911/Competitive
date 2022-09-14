use std::collections::HashSet;
pub struct Solution;

impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let mut longest = 1;
        let mut curr = 1;
        let mut hash: HashSet<char> = HashSet::new();
        hash.insert(s.chars().next().unwrap());
        for ss in s.chars().skip(1){
            if hash.contains(&ss){
                if curr>longest{
                    longest = curr;
                }
                curr = 1;
                hash.clear();
            }else{
                curr+=1;
                hash.insert(ss);
            }
        }
        longest
    }
}

fn main(){
    print!("{}", Solution::length_of_longest_substring(String::from("abcaa")))
}