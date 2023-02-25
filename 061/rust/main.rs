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
    pub fn rotate_right(head: Option<Box<ListNode>>, k: i32) -> Option<Box<ListNode>> {
        let mut temp = head.as_deref();
        let mut v = Vec::new();
        while temp.is_some() {
            let t = temp.unwrap();
            v.push(t.val);
            temp = t.next.as_deref();
        }

        if v.is_empty() {
            return None;
        }
        let k = v.len() - 1 - (k as usize) % v.len();
        let mut root = None;
        for i in 0..v.len() {
            let j = if i > k { v.len() - (i - k) } else { k - i };
            let mut temp = ListNode::new(v[j]);
            temp.next = root;
            root = Some(Box::new(temp));
        }
        return root;
    }
}
