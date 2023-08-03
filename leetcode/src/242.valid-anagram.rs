/*
 * @lc app=leetcode id=242 lang=rust
 *
 * [242] Valid Anagram
 */

struct Solution;
// @lc code=start
impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {
        use std::collections::HashMap;
        let mut map = HashMap::new();
        for c in s.chars() {
            map.entry(c).and_modify(|e| *e += 1).or_insert(1);
        }

        // if t contains a char not in s, return false
        for c in t.chars() {
            if let Some(e) = map.get_mut(&c) {
                *e -= 1;
            } else {
                return false;
            }
        }

        // check if all values are 0
        map.values().all(|&v| v == 0)
    }
}
// @lc code=end
