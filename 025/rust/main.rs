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
    fn full(mut head: Option<&ListNode>, k: i32) -> bool {
        let mut count = 0;
        while head.is_some() && count < k {
            head = head.unwrap().next.as_deref();
            count += 1;
        }
        return count == k;
    }

    fn reverse(mut head: Option<&ListNode>, k: i32) -> Option<Box<ListNode>> {
        let mut dummy = None;
        for _ in 0..k {
            let t = head.unwrap();
            let mut temp = ListNode::new(t.val);
            temp.next = dummy;
            dummy = Some(Box::new(temp));
            head = t.next.as_deref();
        }
        return dummy;
    }

    pub fn reverse_k_group(head: Option<Box<ListNode>>, k: i32) -> Option<Box<ListNode>> {
        let mut root = ListNode::new(0);
        let mut temp = &mut root;
        let mut t = head.as_deref();
        while t.is_some() {
            if !Solution::full(t, k) {
                temp.next = Some(Box::new((*t.unwrap()).clone()));
                break;
            } 
            temp.next = Solution::reverse(t, k);
            for _ in 0..k {
                temp = temp.next.as_deref_mut().unwrap();
                t = t.unwrap().next.as_deref();
            }
        }
        return root.next;
    }
}
