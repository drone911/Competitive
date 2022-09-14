pub struct Solution;

impl Solution {
    pub fn multiply(num1: String, num2: String) -> String {
        let num1_bytes= num1.as_bytes();
        let num2_bytes = num2.as_bytes();
        let mut result: Vec<i32> = vec![0; num1_bytes.len() + num2_bytes.len()];
        let mut temp;
        for i in (0..num1_bytes.len()).rev() {
            for j in (0..num2_bytes.len()).rev() {
                temp = ((num1_bytes[i] - 48)* (num2_bytes[j] - 48)) as i32;
                temp += result[i+j+1]; 
                result[i+j+1] = temp%10;
                result[i+j] += temp/10; 
            }
        }
        let mut to_skip = 0;
        while to_skip < result.len() && result[to_skip] == 0  {
            to_skip += 1;
        }
        if to_skip < result.len() {
            result.iter().skip(to_skip).map(ToString::to_string).collect()
        } else {
            String::from("0")
        }
    }
}
fn main(){
    assert_eq!(Solution::multiply(String::from("50"), String::from("30")), "1500".to_string());
    assert_eq!(Solution::multiply(String::from("0123"), String::from("889744")), "109438512".to_string());
    assert_eq!(Solution::multiply(String::from("0"), String::from("0")), "0".to_string());
    assert_eq!(Solution::multiply(String::from("3"), String::from("0")), "0".to_string());
    assert_eq!(Solution::multiply(String::from("10"), String::from("05")), "50".to_string());

}