use std::vec;
use std::mem;

// Definition for singly-linked list.

#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
  pub val: i32,
  pub next: Option<Box<ListNode>>
}

impl ListNode {
  #[inline]
  fn new(val: i32) -> Self {
    ListNode {
      next: None,
      val
    }
  }

}
pub struct Solution;

impl Solution {
    pub fn reverse_k_group(head: Option<Box<ListNode>>, k: i32) -> Option<Box<ListNode>> {
        if k==1 {
            return head
        }
        head
    }
}

pub fn make_list(list: Vec<i32>) -> Option<Box<ListNode>>{
    let mut head: Option<Box<ListNode>> = Some(Box::new(ListNode::new(list[0])));
    let hdd: &Option<Box<ListNode>> = &head;
    
    for i in list.iter().skip(1) {
        let new_elem: Option<Box<ListNode>> = Some(Box::new(ListNode::new(*i)));
        head.next = new_elem;
        head = head.next;
    }
    *hdd
}
pub fn main() {

    print!("{}", (make_list(vec![1,2, 3])).unwrap().as_ref().val);
    // assert_eq!(Solution::reverse_k_group())
}