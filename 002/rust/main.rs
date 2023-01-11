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
impl Solution {
    pub fn add_two_numbers(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut root = Some(Box::new(ListNode::new(0)));
        let mut temp = &mut root;
        let mut l1 = l1;
        let mut l2 = l2;
        let mut left = 0;
        while l1.is_some() || l2.is_some() {
            let mut val1 = 0;
            if let Some(l) = l1 {
                val1 = l.val;
                l1 = l.next;   
            }
            let mut val2 = 0;
            if let Some(l) = l2 {
                val2 = l.val;
                l2 = l.next;   
            }
            let val = val1 + val2 + left;
            if let Some(ref mut t) = temp {
               t.next = Some(Box::new(ListNode::new(val % 10)));
               temp = &mut t.next;
            }
            left = val / 10;
        }
        if left > 0 {
            if let Some(ref mut t) = temp {
                t.next = Some(Box::new(ListNode::new(left)));
            }
        }
        return root.unwrap().next;
    }
}
