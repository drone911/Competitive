use std::vec::Vec;
use std::cmp::Ordering;

pub struct Solution;

impl Solution {
    pub fn maximum_units(box_types: Vec<Vec<i32>>, truck_size: i32) -> i32 {
        let mut box_types = box_types;
        let mut truck_size = truck_size;
        let mut units = 0;
        // box_types.sort_by(cmp_vec);
        box_types.sort_unstable_by_key(|x|(x[1]));
        for i in box_types.iter().rev() {
            if i[0] >= truck_size {
                units += truck_size * i[1];
                return units;
            } else {
                units += i[0] * i[1];
                truck_size -= i[0];
            }
        }
        units
    }
}

fn cmp_vec(a: &Vec<i32>, b: &Vec<i32>) -> Ordering {
    if a[1] < b[1] {
        return Ordering::Less;
    } else if a[1] > b[1] {
        return Ordering::Greater;
    }
    return Ordering::Equal;
}

fn main() {
    let one: Vec<i32> = Vec::from(&[1, 5][..]);
    let two: Vec<i32> = Vec::from(&[2, 4][..]);
    let mut three: Vec<Vec<i32>> = Vec::new();
    three.push(one);
    three.push(two);
    assert_eq!(Solution::maximum_units(three, 4), 13);
}