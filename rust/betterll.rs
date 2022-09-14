type Link<T> = Option<Box<Node<T>>>;

pub struct Node<T> {
    elem: T,
    next: Link<T>
}

pub struct List<T> {
    head: Link<T>
}

impl<T> List<T> {
    pub fn new() -> Self {
        List {
            head: None
        }
    }
    pub fn push(&mut self, elem: T) {
        let new_node = Box::new(Node {elem: elem, next: self.head.take()});
        self.head = Some(new_node); 
    }
    pub fn pop(&mut self) -> Option<T> {
        self.head.take().map(|node| {
            self.head = node.next;
            node.elem
        })
    }
    pub fn peek(&self) -> Option<&T> {
        self.head.as_ref().map(|node|  {
            &node.elem
        })
        // match &self.head {
        //     None => None,
        //     Some(node) => {
        //         Some(&node.elem)        
        //     }
        // }
    }
    pub fn peek_mut(&mut self) -> Option<&mut T> {
        // self.head.as_mut().map(|node| {
        //     &mut node.elem
        // })
        match &mut self.head {
            None => None,
            Some(node) => {
                Some(&mut node.elem)
            }
        }
    }
    pub fn into_iter(self) -> IntoIter<T> {
        IntoIter(self)
    }

    pub fn iter(&self) -> Iter<T> {
        Iter(&self.head)
    }
}

pub struct IntoIter<T>(List<T>);
pub struct Iter<'a, T>(&'a Link<T>);

impl<T> Iterator for IntoIter<T> {
    type Item = T;
    fn next(&mut self) -> Option<Self::Item> {
        self.0.pop()
    }
}

impl<'a, T> Iterator for Iter<'a, T> {
    type Item = &'a T;
    fn next(&mut self) -> Option<Self::Item> {
        self.0.as_ref().map(|node| {
            self.0 = &node.next;
            &node.elem
        })
    }
}

pub fn main() {
    let mut ll = List::new();
    ll.push(3);
    ll.push(4);
    let mut iter = ll.iter();
    assert_eq!(iter.next(), Some(&4));
    assert_eq!(iter.next(), Some(&3));
    
    // let yy = ll.peek_mut();
    // *(yy.unwrap()) = 5;
    // print!("{}", ll.peek().unwrap_or(&44));
}