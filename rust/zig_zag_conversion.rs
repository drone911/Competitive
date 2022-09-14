use std::vec::Vec;

pub struct Solution;

impl Solution {
    pub fn convert(s: String, num_rows: i32) -> String {
        if num_rows == 1 {
            return s;
        }
        let num_rows = num_rows as usize
        let s_v: Vec<char> = s.chars().collect();
        let mut r_v: Vec<char> = Vec::new();
        
        let mut index;
        for i in 0..num_rows{
            let mut down = true;
            index = i;
            while index < s_v.len(){
                r_v.push(s_v[index]);
                if i==(num_rows-1){
                    index += ((num_rows - 2) * 2 + 2);
                }else if down || i == 0{
                    index += ((num_rows - i - 2) * 2 + 2);
                }
                else{
                    index += ((i - 1) * 2 + 2);
                }
                down = !down;
            }
        }
        r_v.iter().collect()
    }
}

fn main(){

    assert_eq!(Solution::convert("A".to_string(), 1), "A".to_string());
    assert_eq!(Solution::convert("PAYPALISHIRING".to_string(), 3), "PAHNAPLSIIGYIR".to_string());
}