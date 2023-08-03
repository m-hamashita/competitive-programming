/*
 * @lc app=leetcode id=20 lang=rust
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (40.22%)
 * Likes:    21143
 * Dislikes: 1348
 * Total Accepted:    3.6M
 * Total Submissions: 8.9M
 * Testcase Example:  '"()"'
 *
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 *
 * An input string is valid if:
 *
 *
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * Every close bracket has a corresponding open bracket of the same type.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: s = "()"
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: s = "()[]{}"
 * Output: true
 *
 *
 * Example 3:
 *
 *
 * Input: s = "(]"
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^4
 * s consists of parentheses only '()[]{}'.
 *
 *
 */

struct Solution;
// @lc code=start
impl Solution {
    pub fn is_valid(s: String) -> bool {
        use std::collections::HashMap;
        // using stack
        // if ([{ => push
        // if )]} => pop and check if it matches
        // if stack is empty => true
        let mut stack: Vec<char> = Vec::new();
        let map = vec![(')', '('), (']', '['), ('}', '{')]
            .into_iter()
            .collect::<HashMap<char, char>>();

        for c in s.chars() {
            if c == '(' || c == '[' || c == '{' {
                stack.push(c);
            } else {
                let match_char = map.get(&c).unwrap();
                match stack.pop() {
                    Some(x) => {
                        if x != *match_char {
                            return false;
                        }
                    }
                    None => return false,
                }
            }
        }
        if stack.len() == 0 {
            return true;
        }
        false
    }
}
// @lc code=end

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case("()", true)]
    #[case("()[]{}", true)]
    #[case("(]", false)]
    #[case("([)]", false)]
    fn test_20(#[case] s: &str, #[case] expected: bool) {
        assert_eq!(Solution::is_valid(s.to_string()), expected);
    }
}
