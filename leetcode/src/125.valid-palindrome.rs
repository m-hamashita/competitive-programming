/*
 * @lc app=leetcode id=125 lang=rust
 *
 * [125] Valid Palindrome
 *
 * https://leetcode.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (45.05%)
 * Likes:    7534
 * Dislikes: 7501
 * Total Accepted:    2.1M
 * Total Submissions: 4.7M
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * A phrase is a palindrome if, after converting all uppercase letters into
 * lowercase letters and removing all non-alphanumeric characters, it reads the
 * same forward and backward. Alphanumeric characters include letters and
 * numbers.
 *
 * Given a string s, return true if it is a palindrome, or false otherwise.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "A man, a plan, a canal: Panama"
 * Output: true
 * Explanation: "amanaplanacanalpanama" is a palindrome.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "race a car"
 * Output: false
 * Explanation: "raceacar" is not a palindrome.
 *
 *
 * Example 3:
 *
 *
 * Input: s = " "
 * Output: true
 * Explanation: s is an empty string "" after removing non-alphanumeric
 * characters.
 * Since an empty string reads the same forward and backward, it is a
 * palindrome.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 2 * 10^5
 * s consists only of printable ASCII characters.
 *
 *
 */

struct Solution;

// @lc code=start
impl Solution {
    pub fn is_palindrome(s: String) -> bool {
        // naive solution
        // let s = s
        //     .chars()
        //     .filter(|c| c.is_ascii_alphanumeric())
        //     .collect::<String>()
        //     .to_lowercase();
        // let mut i = 0;
        // if s.len() <= 1 {
        //     return true;
        // }
        // // s.len() - 1 is usize, so it's always > 0
        // let mut j = s.len() - 1;
        // while i < j {
        //     if s.chars().nth(i) != s.chars().nth(j) {
        //         return false;
        //     }
        //     i += 1;
        //     j -= 1;
        // }
        // true

        // check equal reversing string
        let s = s
            .chars()
            .filter(|c| c.is_ascii_alphanumeric())
            .collect::<String>()
            .to_lowercase();
        let rev = s.chars().rev().collect::<String>();
        s == rev
    }
}
// @lc code=end
