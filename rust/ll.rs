use std::mem;

pub struct Node {
    elem: i32,
    next: Link
}
impl Node {
    pub fn new(elem: i32, next: Link) -> Self {
        Node {
            elem, next
        }
    }
}

pub enum Link {
    More(Box<Node>),
    Nil
}
pub struct List {
    head: Link
}

impl List {
    pub fn new(i: i32) -> Self {
        List {
            head: Link::More(Box::new(Node::new(i, Link::Nil)))
        }
    }
    pub fn push(&mut self, i: i32) {
        let new_node = Box::new(Node::new(i, mem::replace(&mut self.head, Link::Nil)));
        self.head = Link::More(new_node);
    }
    pub fn pop(&mut self) -> Option<i32> {
        // remove first elem
        // point head to next elem
        match mem::replace(&mut self.head, Link::Nil) {
            Link::Nil => None,
            Link::More(node) => {
                self.head = node.next;
                Some(node.elem)
            }
        }
    }
    pub fn iterate(&self) {
        let mut curr = &self.head;
        while let Link::More(curr_node_ptr) = &curr {
            print!("{}\n", (*curr_node_ptr).elem);
            curr = &curr_node_ptr.next;
        }
    }
    pub fn from_vec(vec: Vec<i32>) -> Self {
        let mut list = List {
            head: Link::Nil
        };
        for i in vec.iter().rev() {
            list.push(*i);
        }
        list
    }
}

pub fn main() {
    let mut ll = List::from_vec(vec![1, 2, 3, 4]);
    ll.pop();
    ll.iterate();
}