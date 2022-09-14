struct Solution;
const roman_to_val:Vec<(i32, &str)> = Vec::from([
    (1, "I"),
    (4, "IV"),
    (5, "V"),
    (9, "IX"),
    (10, "X"),
    (40, "XL"),
    (50, "L"),
    (90, "XC"),
    (100, "C"),
    (400, "CD"),
    (500, "D"),
    (900, "CM"),
    (1000, "M")
]);

impl Solution {
    pub fn int_to_roman(num: i32) -> String {
        let mut num = num;
        let mut roman: String = String::new();
        for i in roman_to_val.iter().rev() {
            while num >= i.0 {
                num -= i.0;
                roman.push_str(i.1);
            }
        }
        roman
    }
}

fn main() {
    assert_eq!(Solution::int_to_roman(1994), "MCMXCIV".to_string());
    assert_eq!(Solution::int_to_roman(1), "I".to_string());
    assert_eq!(Solution::int_to_roman(3), "III".to_string());
    assert_eq!(Solution::int_to_roman(5), "V".to_string());
    assert_eq!(Solution::int_to_roman(6), "VI".to_string());
    
}