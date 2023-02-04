// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
// 
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
use std::cmp::Ordering;
use std::collections::BinaryHeap;

#[derive(Clone, Eq, PartialEq)]
struct Wrapper {
    n: ListNode,
}

impl Wrapper {
    fn new(n: Option<Box<ListNode>>) -> Self {
        Wrapper {
            n: *n.unwrap()
        }
    }
}

impl Ord for Wrapper {
    fn cmp(&self, other: &Self) -> Ordering {
       other.n.val.cmp(&self.n.val) 
    }
}

impl PartialOrd for Wrapper {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

impl Solution {
    pub fn merge_k_lists(lists: Vec<Option<Box<ListNode>>>) -> Option<Box<ListNode>> {
        let mut q = BinaryHeap::new();
        for list in lists {
            if list.is_some() {
                q.push(Wrapper::new(list));
            }
        }
        let mut root = ListNode::new(0);
        let mut temp = &mut root;
        while let Some(w) = q.pop() {
            temp.next = Some(Box::new(w.n.clone()));
            temp = temp.next.as_deref_mut().unwrap();
            if w.n.next.is_some() {
                q.push(Wrapper::new(w.n.next));
            }
        }
        return root.next;
    }
}
