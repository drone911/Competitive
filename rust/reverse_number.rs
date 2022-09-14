pub struct Solution;

impl Solution {
    pub fn reverse(x: i32) -> i32 {
        let mut rev: i32 = 0;
        let mut x: i32 = x;
        while x !=0 {
            if let Some(y) = rev.checked_mul(10) {
                if let Some(z) = y.checked_add(x%10) {
                    rev = z; 
                } else{
                    return 0;
                }
            } 
            else{
                return 0;
            }
        x=x/10;
        }
        rev
    }
}

pub fn main() {
    assert_eq!(Solution::reverse(1), 1);
    assert_eq!(Solution::reverse(123), 321);
    assert_eq!(Solution::reverse(-123), -321);
}