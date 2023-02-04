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
    pub fn remove_nth_from_end(head: Option<Box<ListNode>>, n: i32) -> Option<Box<ListNode>> {
        let mut head = head;
        let mut first = head.as_deref();
        for i in 0..n {
            first = first.unwrap().next.as_deref();
        }

        if first.is_none() {
            return head.unwrap().next;
        }
        first = first.unwrap().next.as_deref();

        let mut i = 0;
        while first.is_some() {
            first = first.unwrap().next.as_deref();
            i += 1;
        }

        let mut second = head.as_deref_mut();
        while i > 0 {
            second = second.unwrap().next.as_deref_mut();
            i -= 1;
        }

        let second = second.unwrap();
        second.next = second.clone().next.unwrap().next;

        // match second {
        //     Some(ref mut second) => second.next = second.clone().next.unwrap().next,
        //     _ => (),
        // }
        return head;
    }
}
