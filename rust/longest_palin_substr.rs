pub struct Solution;

impl Solution {
    pub fn longest_palindrome(s: String) -> String {
        let len = s.len();
        if len < 2 {
            return s;
        }
        let s_v: Vec<char> = s.chars().collect();
        let mut start = 0;
        let mut end = 0;

        for i in 0..len {
            let mut left = i;
            let mut right = i;
            while right + 1 < len && s_v[left] == s_v[right+1]{
                right+=1;
            }
            while right + 1< len && left>0 && s_v[left-1] == s_v[right+1]{
                right+=1;
                left-=1;
            } 
            if right - left>end-start{
                start = left;
                end = right;
            }
        }
        s_v[start..=end].iter().collect()
    }
}

fn main(){
    assert_eq!(Solution::longest_palindrome("abccbd".to_string()), "bccb");
    assert_eq!(Solution::longest_palindrome("a".to_string()), "a");
    assert_eq!(Solution::longest_palindrome("".to_string()), "")
}