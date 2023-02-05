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
    fn swap(n: Option<&ListNode>) -> Option<Box<ListNode>> {
        let n = n.clone().unwrap();
        let a = Some(Box::new(ListNode::new(n.val)));
        if n.next.is_none() {
            return a;
        }
        
        let mut b = ListNode::new(n.next.clone().unwrap().val);
        b.next = a;
        let b = Some(Box::new(b));
        
        return b;
    }

    pub fn swap_pairs(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut root = ListNode::new(0);
        let mut temp = &mut root;
        let mut t = head.as_deref();
        while t.is_some() {
            temp.next = Solution::swap(t);
            temp = temp.next.as_deref_mut().unwrap();
            t = t.unwrap().next.as_deref();
            if temp.next.is_none() || t.is_none() {
                break;
            }
            temp = temp.next.as_deref_mut().unwrap();
            t = t.clone().unwrap().next.as_deref();
        }
        return root.next;
    }
}
