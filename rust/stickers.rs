use std::collections::HashMap;

pub struct Solution;

impl Solution {
    pub fn min_stickers(stickers: Vec<String>, target: String) -> i32 {
        let mut target_char_freq: HashMap<u8, i32>;
        for target_char in AsRef::<[u8]>::as_ref(&target).iter() {
            if target_char_freq.contains_key(&target_char) {
                target_char_freq.insert(*target_char, target_char_freq.get(target_char).unwrap() + 1);
            } else {
                target_char_freq.insert(*target_char, 1);
            }
        }
        print!("{:?}", target_char_freq);
        0
    }
}

fn main() {
    Solution::min_stickers(vec![], "avcdfgaac".to_string());

}