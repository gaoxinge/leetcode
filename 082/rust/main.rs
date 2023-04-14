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
    pub fn delete_duplicates(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut head = head;
        let mut root = ListNode::new(0);
        let mut temp = &mut root;
        let mut val = -200;
        let mut cnt = false;
        while head.is_some() {
            let t = head.unwrap();
            if t.val == val {
                cnt = true;
            } else {
                if val != -200 && !cnt {
                    temp.next = Some(Box::new(ListNode::new(val)));
                    temp = temp.next.as_mut().unwrap();
                }
                val = t.val;
                cnt = false;
            }
            head = t.next;
        }
        if val != -200 && !cnt {
            temp.next = Some(Box::new(ListNode::new(val)));
        }
        return root.next;
    }
}
