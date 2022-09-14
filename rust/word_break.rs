pub struct Solution;

use std::collections::HashSet;

impl Solution {
    fn backtract(s: &String, word_set: &HashSet<String>, start: usize, dp: &mut Vec<Option<bool>>) -> Option<bool> {
        let n = s.len();
        if start>=n {
            return true
        }
        let mut i=start;
        dp[i] = Some(match dp[start] {
            None => {
                while i<=n {
                    if word_set.contains(&s[start..i]) {
                        if Solution::backtract(&s, &word_set, i+1, dp) {
                            return true;
                        }
                    }
                    i = i+1;
                }
                false
            },
            Some(res) => res
        })
        dp[i]
    }
    pub fn word_break(s: String, word_dict: Vec<String>) -> bool {
        let mut word_dict = word_dict;
        let mut chars = HashSet::new();
        let mut chars_in_dict = HashSet::new();
        for i in s.chars() {
            chars.insert(i);
        }

        for word in &word_dict {
            for i in word.chars() {
                chars_in_dict.insert(i);
            }
        } 
        if !chars.is_subset(&chars_in_dict) {
            return false;
        }
        word_dict.sort_unstable_by(|a, b| {
            b.len().cmp(&a.len())
        });
        let mut word_set = HashSet::new();
        for i in word_dict {
            word_set.insert(i);
        }
        let mut dp = vec![None; 300];
        Solution::backtract(&s, &word_set, 0, &mut dp)
    }
}

pub fn main() {
    assert_eq!(Solution::word_break(String::from("aaaaaab"), vec!["aa".to_string(), "a".to_string(), "aaa".to_string()]), false);
    assert_eq!(Solution::word_break(String::from("one"), vec!["sdf".to_string(), "one".to_string(), "dog".to_string()]), true);
    assert_eq!(Solution::word_break(String::from("on"), vec!["one".to_string()]), false);
    assert_eq!(Solution::word_break(String::from("o"), vec!["o".to_string()]), true);    
    assert_eq!(Solution::word_break(String::from("catsanddog"), vec!["cats".to_string(), "and".to_string(), "dog".to_string()]), true);
    assert_eq!(Solution::word_break(String::from("catsanddog"), vec!["wifi".to_string(), "cats".to_string(), "and".to_string(), "dog".to_string()]), true);
    assert_eq!(Solution::word_break(String::from("catsandog"), vec!["wifi".to_string(), "cats".to_string(), "and".to_string(), "dog".to_string()]), false);
    assert_eq!(Solution::word_break(String::from("catsandog"), vec!["cats".to_string(), "and".to_string(), "dog".to_string()]), false);
    assert_eq!(Solution::word_break(String::from("abcd"), vec!["a".to_string(), "abc".to_string(), "b".to_string(), "cd".to_string()]), true);
    // assert_eq!(Solution::word_break(String::from("aaaaaaa"), vec!["aaaa".to_string(), "aaa".to_string()]), true);
}