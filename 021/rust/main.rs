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
    pub fn merge_two_lists(list1: Option<Box<ListNode>>, list2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut list1 = list1;
        let mut list2 = list2;
        let mut root = ListNode::new(0);
        let mut temp = &mut root;
        while list1.is_some() || list2.is_some() {
            let mut val = 0;
            if list1.is_none() {
                let b2 = list2.clone().unwrap();
                val = b2.val;
                list2 = b2.next;
            } else if list2.is_none() {
                let b1 = list1.clone().unwrap();
                val = b1.val;
                list1 = b1.next;
            } else {
                let b1 = list1.clone().unwrap();
                let b2 = list2.clone().unwrap();
                if b1.val <= b2.val {
                    val = b1.val;
                    list1 = b1.next;
                } else {
                    val = b2.val;
                    list2 = b2.next;
                }
            }
            temp.next = Some(Box::new(ListNode::new(val)));
            temp = temp.next.as_deref_mut().unwrap();
        }
        return root.next;
    }
}
