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


impl Solution {
    pub fn add_two_numbers(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        type List = Option<Box<ListNode>>;
        let mut p1: List = l1;
        let mut p2: List = l1;
        let mut carry = 0;
        let to_return: List = Some(Box::new(ListNode::new(0)));
        let mut new_list: List = to_return;

        while p1 || p2 || carry {
            let sum = match (&p1, &p2) {
                (Some(&x), Some(&y)) => x+y+carry,
                (Some(&x), None) => x+carry,
                (None, Some(&y)) => y+carry,
                (None, None) => carry
            }
            p1 = p1.unwrap_or().next;
            p2 = p2.unwrap_or().next;
            new_list.next = Box::new(ListNode::new(sum%10))
            new_list = new_list.next;
            carry = sum/10;

        }
        to_return
    }
}

fn main(){
    ()
}