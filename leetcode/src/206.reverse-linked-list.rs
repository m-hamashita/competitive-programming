/*
 * @lc app=leetcode id=206 lang=rust
 *
 * [206] Reverse Linked List
 *
 * https://leetcode.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (74.85%)
 * Likes:    19762
 * Dislikes: 357
 * Total Accepted:    3.5M
 * Total Submissions: 4.6M
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Given the head of a singly linked list, reverse the list, and return the
 * reversed list.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,2,3,4,5]
 * Output: [5,4,3,2,1]
 *
 *
 * Example 2:
 *
 *
 * Input: head = [1,2]
 * Output: [2,1]
 *
 *
 * Example 3:
 *
 *
 * Input: head = []
 * Output: []
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the list is the range [0, 5000].
 * -5000 <= Node.val <= 5000
 *
 *
 *
 * Follow up: A linked list can be reversed either iteratively or recursively.
 * Could you implement both?
 *
 */

struct Solution;

#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>,
}

impl ListNode {
    #[inline]
    fn new(val: i32) -> Self {
        ListNode { next: None, val }
    }
}
// @lc code=start
// Definition for singly-linked list.
impl Solution {
    pub fn reverse_list(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        // 前の node を prev として持っておき、node.next に prev を入れるというのを繰り返す
        let mut prev = None;
        let mut head = head;
        while let Some(mut node) = head {
            head = node.next;
            node.next = prev;
            prev = Some(node);
        }
        prev
    }
}
// @lc code=end

use rstest::rstest;

#[rstest]
#[case(
    Some(Box::new(ListNode {
        val: 1,
        next: Some(Box::new(ListNode {
            val: 2,
            next: Some(Box::new(ListNode::new(3)))
        }))
    })),
    Some(Box::new(ListNode {
        val: 3,
        next: Some(Box::new(ListNode {
            val: 2,
            next: Some(Box::new(ListNode::new(1)))
        }))
    }))
)]
#[case(Some(Box::new(ListNode::new(1))), Some(Box::new(ListNode::new(1))))]
#[case(
    Some(Box::new(ListNode {
        val: 1,
        next: Some(Box::new(ListNode::new(2)))
    })),
    Some(Box::new(ListNode {
        val: 2,
        next: Some(Box::new(ListNode::new(1)))
    }))
)]
// None pattern
#[case(None, None)]
fn test(#[case] head: Option<Box<ListNode>>, #[case] expected: Option<Box<ListNode>>) {
    assert_eq!(Solution::reverse_list(head), expected);
}
